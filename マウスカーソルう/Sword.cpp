#include "Sword.h"
#include "DxLib.h"
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
}

// 剣の移動・角度
void Sword::Update()
{
	int mouseX;
	int mouseY;

	// マウスの現在位置を取得
	GetMousePoint(&mouseX, &mouseY);

	// 剣の位置
	x += (mouseX - x) * easing;
	y += (mouseY - y) * easing;


	// マウスの方向を計算
	float dx = mouseX - x;
	float dy = mouseY - y;
	targetAngle = atan2f(dy, dx);

	// 剣を向ける
	float angleDifference = targetAngle - angle;

	// -PIからPIにする
	while (angleDifference > DX_PI_F)
	{
		angleDifference -= 2.0f * DX_PI_F;
	}
	while (angleDifference < -DX_PI_F)
	{
		angleDifference += 2.0f * DX_PI_F;
	}

	//360度以上の回転をしたらリセット
	while (angle > 2.0f * DX_PI_F)
	{
		angle -= 2.0f * DX_PI_F;
	}
	while (angle < -2.0f * DX_PI_F)
	{
		angle += 2.0f * DX_PI_F;
	}

	bool isMousePressed = (GetMouseInput() & MOUSE_INPUT_LEFT) != 0;
	// 剣の角度を滑らかに変化
	if (!isMousePressed)
	{
		angle += angleDifference * rotationSpeed;
		if (angleDifference > 1.5f)
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
		if (true)
		{
			// 前のフレームからの移動距離を計算
			float dx = x - oldX;
			float dy = y - oldY;

			// 移動速度を計算
			velocity = sqrtf(dx * dx + dy * dy);

			// 攻撃判定
			if (velocity >= attackSpeed)
			{
				attack = true;
			}
			else
			{
				attack = false;
			}

			// 現在位置を保存
			oldX = x;
			oldY = y;
		}
		
	}

}
float Sword::GetAttack() const
{
	return attack;
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