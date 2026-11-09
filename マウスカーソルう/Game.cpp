#include <cmath>
#include <vector>
#include <algorithm>
#include "DxLib.h"
#include "Game.h"
#include "Enemy.h"
#include "Sword.h"
#include "Bird.h"
#include "skeleton.h"
#include "Player.h"
#include "Scene.h"
#include "ImageManager.h"
#include "DamageText.h"

// ---------------------------------
// グローバル変数の実体
// ---------------------------------
// ダメージ表示
std::vector<DamageText> damageTexts;

int imgW, imgH;

double bgX = 0.0;
double scrollSpeed = 2.0;
int screenWidth = 1300;

int mouseX, mouseY;

double enemyX = 1300.0;
double enemyY = 300.0;

double enemySpeed = 1.0;

double currentX = 0.0;
double currentY = 0.0;

double easing = 0.08;

double Rangi = 0.0;
double exRate = 0.2 + Rangi;

double angle = 0.0;

double counttime = 0.0;
float addTime = 0.001f;

bool gameOver = false;

int score = 0; 

// エフェクトアニメーション
const int EFFECT_SPEED = 5;

int effectFrame = 0;     // 現在の画像番号
int effectCount = 0;     // コマ切り替え用
bool GraphActive = false;

float effectX = 0.0f;
float effectY = 0.0f;

bool effectHitThisAttack = false; // 1回の攻撃でエフェクトがヒットしたかどうかを追跡するフラグ


// ---------------------------------
// ゲーム内オブジェクト
// ---------------------------------

namespace
{
    Sword sword;
    Player player;
    Bird birdEnemy;
    Skeleton skeletonEnemy;
}

    // 2点間の線分と敵の距離
    float PointToSegmentDistance(
        float px, float py,
        float ax, float ay,
        float bx, float by)
    {
        float abX = bx - ax;
        float abY = by - ay;

        float apX = px - ax;
        float apY = py - ay;

        float lengthSquared =
            abX * abX + abY * abY;

        if (lengthSquared == 0.0f)
        {
            float dx = px - ax;
            float dy = py - ay;

            return sqrtf(dx * dx + dy * dy);
        }

        float t =
            (apX * abX + apY * abY)
            / lengthSquared;

        // 線分の範囲に制限
        if (t < 0.0f)
        {
            t = 0.0f;
        }
        else if (t > 1.0f)
        {
            t = 1.0f;
        }

        float closestX = ax + t * abX;
        float closestY = ay + t * abY;

        float dx = px - closestX;
        float dy = py - closestY;

        return sqrtf(dx * dx + dy * dy);
    }

// ---------------------------------
// ゲーム初期化
// ---------------------------------

    bool GameInitialize()
    {
        gameOver = false;

        // 画像読み込み
        if (!ImageManager::Initialize())
        {
            return false;
        }

        // 剣の画像サイズ
        GetGraphSize(
            ImageManager::GetSwordGraph(),
            &imgW,
            &imgH
        );

        // 剣の初期化
        sword.Initialize(
            ImageManager::GetSwordGraph(),
            640.0f,
            360.0f,
            angle,
            exRate,
            easing,
            false
        );

        // プレイヤーの初期化
        player.Initialize(
            10,//hp
            640.0f,//ｘ
            360.0f,//ｙ
            0,//exp
            1,//レベル
            1,//攻撃力
            easing,//移動ヌルヌル度
            true//生きてるか
        );

        // 鳥の初期化
        birdEnemy.Initialize(
            ImageManager::GetBirdGraph(0),
            3,
            -100.0f,
            300.0f,
            3.0f,
            0.2f,
            true
        );

        // 鳥のアニメーション画像を設定
        birdEnemy.SetAnimationGraphs(
            ImageManager::GetBirdGraph(0),
            ImageManager::GetBirdGraph(1)
        );

        bgX = 0.0;

        // エフェクトの初期状態
        effectFrame = 0;
        effectCount = 0;
        GraphActive = false;
        effectHitThisAttack = false;

        // ダメージ表記の初期化
        damageTexts.clear();

        return true;
    }
// ---------------------------------
// ゲーム更新
// ---------------------------------

void GameUpdate()
{
    if (gameOver) return;

    // ---------------------------------
    // 背景スクロール
    // ---------------------------------

    bgX += scrollSpeed;

    if (bgX >= screenWidth)
    {
        bgX = 0.0;
    }

    // ---------------------------------
    // オブジェクト更新
    // ---------------------------------

    birdEnemy.Update();
    sword.Update();
    player.Update();

    // ---------------------------------
    // エフェクトアニメーション更新
    // ---------------------------------

    if (GraphActive)
    {
        effectCount++;

        // 5フレームごとに次の画像へ
        if (effectCount >= EFFECT_SPEED)
        {
            effectCount = 0;
            effectFrame++;

            // 最後の画像まで再生したら終了
            if (effectFrame >= ImageManager::GetEffectMax())
            {
                GraphActive = false;
            }
        }
    }

    // ---------------------------------
    // 剣の攻撃判定
    // ---------------------------------

    // 攻撃が終わったら次の攻撃を許可
    if (!sword.GetAttack())
    {
        effectHitThisAttack = false;
    }

    if (sword.GetAttack() && !effectHitThisAttack)
    {
        if (birdEnemy.IsAlive())
        {
            float startX, startY;
            float endX, endY;

            sword.GetSwordSegment(
                startX, startY,
                endX, endY
            );

            float distance = PointToSegmentDistance(
                birdEnemy.GetX(),
                birdEnemy.GetY(),
                startX, startY,
                endX, endY
            );

            const float enemyRadius = 50.0f;
            const float swordRadius = 12.0f;

            if (distance <= enemyRadius + swordRadius)
            {
                // 敵にダメージを与える
                int actualDamage = birdEnemy.TakeDamage(player.GetAttackPower());

                // ダメージ表示を登録
                if (actualDamage > 0)
                {
                    DamageText text;

                    text.Initialize(
                        actualDamage,
                        birdEnemy.GetX(),
                        birdEnemy.GetY() - 60
                    );

                    damageTexts.push_back(text);
                }
                // アニメーション位置
                effectX = birdEnemy.GetX();
                effectY = birdEnemy.GetY();

                // アニメーションを最初から再生
                effectFrame = 0;
                effectCount = 0;
                GraphActive = true;

                // この攻撃では再発生させない
                effectHitThisAttack = true;
            }
        }
    }

    // ---------------------------------
    // プレイヤーと敵の接触判定
    // ---------------------------------

    float dx = player.GetX() - birdEnemy.GetX();
    float dy = player.GetY() - birdEnemy.GetY();

    float distance = sqrtf(dx * dx + dy * dy);

    const float playerRadius = 10.0f;
    const float enemyRadius = birdEnemy.GetRadius();

    if (player.IsAlive() && birdEnemy.IsAlive())
    {
        if (!player.IsInvincible())
        {
            if (distance < playerRadius + enemyRadius)
            {
                int actualDamage = player.TakeDamage(2);

                // 実際にダメージを受けた場合だけ表示
                if (actualDamage > 0)
                {
                    DamageText text;

                    text.Initialize(
                        actualDamage,
                        player.GetX(),
                        player.GetY() - 40
                    );

                    damageTexts.push_back(text);
                }
            }
        }
    }

    if (!player.IsAlive())
    {
        gameOver = true;
    }

    // ダメージ表示の更新
    for (auto& text : damageTexts)
    {
        text.Update();
    }

    // 表示時間が終わったものを削除
    damageTexts.erase(
        std::remove_if(
            damageTexts.begin(),
            damageTexts.end(),
            [](DamageText& text)
            {
                return !text.IsActive();
            }
        ),
        damageTexts.end()
    );
}

// ---------------------------------
// ゲーム描画
// ---------------------------------

void GameDraw()
{

    // 背景1枚目
    DrawExtendGraph(
        static_cast<int>(bgX),
        0,
        static_cast<int>(bgX + screenWidth),
        720,
        BackGround,
        FALSE
    );

    // 背景2枚目
    DrawExtendGraph(
        static_cast<int>(bgX - screenWidth),
        0,
        static_cast<int>(bgX),
        720,
        BackGround,
        FALSE
    );

    // キャラクター描画
    birdEnemy.Draw();
    sword.Draw();
    player.Draw();

    // エフェクトを表示
    if (GraphActive)
    {
        DrawRotaGraph(
            (int)effectX,
            (int)effectY,
            1.0,
            0.0,
            ImageManager::GetEffectGraph(effectFrame),
            TRUE
        ); 
        // HIT表示
    DrawFormatString(
        600, 600,
        GetColor(255, 0, 0),
        "HIT!"
        );
    }

    // ダメージ表記
    for (auto& text : damageTexts)
    {
        text.Draw(50*player.GetAttackPower(), 95, 236 / player.GetAttackPower());
    }
}

// ---------------------------------
// ゲーム終了処理
// ---------------------------------

void GameFinalize()
{
    ImageManager::Finalize();
}

// 取得関数
bool IsGameOver()
{
    return gameOver;
}
