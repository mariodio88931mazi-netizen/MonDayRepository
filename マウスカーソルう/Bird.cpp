#include "Bird.h"
#include "DxLib.h"
#include <iostream>
using namespace std;

Bird::Bird()
{
    graph = 0;

    birdGraph[0] = 0;
    birdGraph[1] = 0;

    hp = 50;
    x = -100.0f;
    y = 300.0f;
    speed = 3.0f;
    scale = 0.2f;
    alive = true;

    animationFrame = 0;
    animationTimer = 0;
}
// 鳥の更新
void Bird::Update()
{
    // 親クラスの移動処理を実行
    Enemy::Update();

    if (!alive) return;

    // アニメーション時間を進める
    animationTimer++;

    // 10フレームごとに画像切り替え
    if (animationTimer >= 10)
    {
        animationTimer = 0;

        animationFrame++;

        // 0と1を交互にする
        animationFrame %= 2;
    }

    // 現在の画像を設定
    graph = birdGraph[animationFrame];
}

// 鳥の描画
void Bird::Draw()
{
    if (!alive) return;

    DrawRotaGraph(
        (int)x,
        (int)y,
        scale,
        0.0,
        graph,
        TRUE
    );
}

float Bird::GetX() const
{
    return Enemy::GetX();
}

float Bird::GetY() const
{
    return Enemy::GetY();
}

void Bird::TakeDamage(int damage)
{
    if (!alive) return;

    hp -= damage;

    if (hp <= 0)
    {
        hp = 0;
        alive = false;
    }
}

// 画像を設定する
void Bird::SetAnimationGraphs(int graph1, int graph2)
{
    birdGraph[0] = graph1;
    birdGraph[1] = graph2;

    graph = birdGraph[0];
}