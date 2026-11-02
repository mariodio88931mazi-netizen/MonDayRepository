#include <cmath>
#include "DxLib.h"
#include "Game.h"
#include "Enemy.h"
#include "Sword.h"
#include "Bird.h"
#include "skeleton.h"
#include "Player.h"
#include "Scene.h"

// ---------------------------------
// グローバル変数の実体
// ---------------------------------

int SwordGraph;
int BackGround;
int Enemy_BIRD1;
int Enemy_BIRD2;
int Enemy_SKELETON1;
int SwordEffect;

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
const int EFFECT_MAX = 5;
const int EFFECT_SPEED = 5;

int effectGraph[EFFECT_MAX];

int effectFrame = 0;     // 現在の画像番号
int effectCount = 0;     // コマ切り替え用
bool effectActive = false;

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
    SwordGraph = LoadGraph("img/sord.png");
    BackGround = LoadGraph("img/BackGround.png");
    Enemy_BIRD1 = LoadGraph("img/enemy/bird1.png");

    // エフェクト画像読み込み
    for (int i = 0; i < EFFECT_MAX; i++)
    {
        char fileName[100];

        sprintf_s(
            fileName,
            "img/effect/swordeffect%d.png",
            i
        );

        effectGraph[i] = LoadGraph(fileName);

        // 読み込み失敗を確認
        if (effectGraph[i] == -1)
        {
            MessageBox(
                NULL,
                fileName,
                "画像読み込みエラー",
                MB_OK
            );

            return false;
        }
    }

    // その他の画像読み込み確認
    if (SwordGraph == -1 ||
        BackGround == -1 ||
        Enemy_BIRD1 == -1)
    {
        MessageBox(
            NULL,
            "剣・背景・敵の画像が読み込めませんでした。",
            "画像読み込みエラー",
            MB_OK
        );

        return false;
    }

    // 剣の画像サイズ
    GetGraphSize(SwordGraph, &imgW, &imgH);

    // 剣・プレイヤー初期化
    sword.Initialize(
        SwordGraph,
        640.0f,
        360.0f,
        angle,
        exRate,
        easing,
        false
    );

    player.Initialize(
        10,
        640.0f,
        360.0f,
        0,
        1,
        easing,
        true
    );

    birdEnemy.Initialize(
        Enemy_BIRD1,
        3,
        -100.0f,
        300.0f,
        3.0f,
        0.2f,
        true
    );
    bgX = 0.0f;

    return true;

    // エフェクトの初期状態
    effectFrame = 0;
    effectCount = 0;
    effectActive = false;
    effectHitThisAttack = false;
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

    if (effectActive)
    {
        effectCount++;

        // 5フレームごとに次の画像へ
        if (effectCount >= EFFECT_SPEED)
        {
            effectCount = 0;
            effectFrame++;

            // 最後の画像まで再生したら終了
            if (effectFrame >= EFFECT_MAX)
            {
                effectActive = false;
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
                birdEnemy.TakeDamage(1);

                // エフェクトの位置を保存
                effectX = birdEnemy.GetX();
                effectY = birdEnemy.GetY();

                // アニメーションを最初から再生
                effectFrame = 0;
                effectCount = 0;
                effectActive = true;

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
                player.TakeDamage(2);
            }
        }
    }

    if (!player.IsAlive())
    {
        gameOver = true;
    }

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
    if (effectActive)
    {
        DrawFormatString(700, 600, GetColor(255, 255, 255), "x: %f, y: %f", effectX, effectY);

        DrawRotaGraph(
            (int)effectX,
            (int)effectY,
            1.0,
            0.0,
            effectGraph[effectFrame],
            TRUE
        );
    }

    // HIT表示
    DrawFormatString(
        600, 600,
        GetColor(255, 0, 0),
        "HIT!"
        );
}

// ---------------------------------
// ゲーム終了処理
// ---------------------------------

void GameFinalize()
{
    DeleteGraph(SwordGraph);
    DeleteGraph(BackGround);

    for (int i = 0; i < EFFECT_MAX; i++)
    {
        if (effectGraph[i] != -1)
        {
            DeleteGraph(effectGraph[i]);
        }
    }
}

// 取得関数
bool IsGameOver()
{
    return gameOver;
}
