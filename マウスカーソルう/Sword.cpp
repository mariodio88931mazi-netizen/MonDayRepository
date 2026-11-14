#include "Sword.h"
#include "DxLib.h"
#include <string>
#include<math.h>

// 円周率
#define DX_PI_F 3.14159265358979323846f
// 剣の初期化
void Sword::Initialize(
	int graphHandle,
	float startX,
	float startY,
	float startAngle,
	float exRate,
	float moveEasing,
	bool isAttacking
)
{
    // 剣関係
	graph = graphHandle;

	x = startX;
	y = startY;

	oldX = startX;
	oldY = startY;

	angle = startAngle;
	targetAngle = startAngle;
	rotationSpeed = 0.1f;
	scale = exRate;

	velocity = 0.0f;
	attackSpeed = 8.0f;

	easing = moveEasing;
	attack = isAttacking;

    // 剣の当たり判定関係
    float swordLength = -540.0f * scale;

    oldStartX = x;
    oldStartY = y;

    oldEndX = x + swordLength * cosf(angle);
    oldEndY = y + swordLength * sinf(angle);
}

// 剣の移動・角度

void Sword::Update()
{
    int mouseX;
    int mouseY;

    // マウスの現在位置を取得
    GetMousePoint(&mouseX, &mouseY);

    // 剣の位置を更新
    x += (mouseX - x) * easing;
    y += (mouseY - y) * easing;

    // マウスの方向を計算
    float dx = mouseX - x;
    float dy = mouseY - y;
    targetAngle = atan2f(dy, dx);

    // 剣の角度差を計算
    angleDifference = targetAngle - angle;

    while (angleDifference > DX_PI_F)
    {
        angleDifference -= 2.0f * DX_PI_F;
    }
    while (angleDifference < -DX_PI_F)
    {
        angleDifference += 2.0f * DX_PI_F;
    }

    // 角度を調整
    while (angle > 2.0f * DX_PI_F)
    {
        angle -= 2.0f * DX_PI_F;
    }
    while (angle < -2.0f * DX_PI_F)
    {
        angle += 2.0f * DX_PI_F;
    }

    // 前のフレームからの移動距離を計算
    float moveX = x - oldX;
    float moveY = y - oldY;

    velocity = sqrtf(moveX * moveX + moveY * moveY);

    bool isMousePressed =
        (GetMouseInput() & MOUSE_INPUT_LEFT) != 0;

    if (!isMousePressed)
    {
        // 剣の角度を滑らかに変化
        angle += angleDifference * rotationSpeed;

        // 角度差による攻撃
        if (angleDifference > 0.8f || angleDifference < -0.8f)
        {
            attack = true;
        }
        else
        {
            attack = false;
        }
    }
    else
    {
        // 移動速度による攻撃
        if (velocity >= attackSpeed)
        {
            attack = true;
        }
        else
        {
            attack = false;
        }
    }

    // 現在の剣の線分を取得
    float startX, startY, endX, endY;

    GetSwordSegment(
        startX, startY,
        endX, endY
    );

    // 現在の剣の位置を保存
    oldStartX = startX;
    oldStartY = startY;

    oldEndX = endX;
    oldEndY = endY;

    // 次のフレーム用にプレイヤー位置も保存
    oldX = x;
    oldY = y;
}

float Sword::GetX() const
{
	return x;
}
float Sword::GetY() const
{
	return y;
}

// 剣の描画
void Sword::Draw()
{
	DrawRotaGraph2
	(
		static_cast<int>(x),
		static_cast<int>(y),
		625,
		85,
		scale,
		angle,
		graph,
		TRUE
	);

	// デバッグ
	DrawFormatString(10, 560, GetColor(255, 255, 255), "Sword Angle: %f", angle);
	DrawFormatString(10, 580, GetColor(255, 255, 255), "angleDifference: %f", angleDifference);
	DrawFormatString(10, 600, GetColor(255, 255, 255), "tragetangle: %f", targetAngle);
}


void Sword::DrawEffect(float x, float y, float scale, float graph)
{
	DrawGraph
	(
		static_cast<int>(x - 625 * scale),
		static_cast<int>(y - 85 * scale), 
		graph,
		TRUE
	);
}

void Sword::GetSwordSegment(float& startx, float& starty, float& endx, float& endy) const
{
	// 柄の長さを始点にする
	startx = x;
	starty = y;

	// 画像の中心から剣先までの距離
	float swordLength = -540.0f * scale;
	// 剣の先端の座標を計算
	endx = x + swordLength * cos(angle);
	endy = y + swordLength * sin(angle);
}

float Sword::GetAttack() const
{
	return attack;
}