

#include <cmath>
#include "DxLib.h"
#include "Game.h"
#include "Enemy.h"
#include "Sword.h"
#include "Bird.h"
#include "skeleton.h"
#include "Player.h"

// ---------------------------------
// 変数の実体
// ---------------------------------

int SwordGraph = -1;
int BackGround = -1;
int Enemy_BIRD1 = -1;
int Enemy_BIRD2 = -1;
int Enemy_SKELETON1 = -1;
int SwordEffect = -1;

int imgW = 0;
int imgH = 0;

double bgX = 0.0;
double scrollSpeed = 2.0;
int screenWidth = 1300;

int mouseX = 0;
int mouseY = 0;

double enemyX = 1300.0;
double enemyY = 300.0;
double enemySpeed = 3.0;

double currentX = 0.0;
double currentY = 0.0;

double easing = 0.08;

double Rangi = 0.0;
double exRate = 0.2 + Rangi;

double angle = 0.0;

double counttime = 0.0;
float addTime = 0.001f;

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
    // 画像読み込み
    SwordGraph = LoadGraph("img/sord.png");
    BackGround = LoadGraph("img/BackGround.png");
    SwordEffect = LoadGraph("img/effect/swordeffect.png");
    Enemy_SKELETON1 = LoadGraph("img/enemy/skeleton1.png");
    Enemy_BIRD1 = LoadGraph("img/enemy/BIRD1.png");

    // 読み込み失敗確認
    if (SwordGraph == -1 ||
        BackGround == -1 ||
        SwordEffect == -1 ||
        Enemy_SKELETON1 == -1 ||
        Enemy_BIRD1 == -1)
    {
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
        0,
        easing
    );

    birdEnemy.Initialize(
        Enemy_BIRD1,
        50,
        -100.0f,
        300.0f,
        3.0f,
        0.2f,
        true
    );
    bgX = 0.0f;

    return true;
}

// ---------------------------------
// ゲーム更新
// ---------------------------------

void GameUpdate()
{
    // 背景スクロール
    bgX += scrollSpeed;

    if (bgX >= screenWidth)
    {
        bgX = 0.0f;
    }

    // 敵・剣・プレイヤー更新
    birdEnemy.Update();
    sword.Update();
    player.Update();

    // 剣の攻撃判定
    if (sword.GetAttack() == true)
    {
        float startX, startY;
        float endX, endY;

        if (birdEnemy.IsAlive())
        {
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

                // HIT表示
                DrawFormatString(
                    600, 600,
                    GetColor(255, 0, 0),
                    "HIT!"
                );

                sword.DrawEffect(
                    birdEnemy.GetX(),
                    birdEnemy.GetY(),
                    1.0f,
                    SwordEffect
                );

                WaitTimer(10);
            }
        }
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
}

// ---------------------------------
// ゲーム終了処理
// ---------------------------------

void GameFinalize()
{
    DeleteGraph(SwordGraph);
    DeleteGraph(BackGround);
    DeleteGraph(SwordEffect);
    DeleteGraph(Enemy_SKELETON1);
}
