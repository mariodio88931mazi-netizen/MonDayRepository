#include "Enemy.h"
#include "DxLib.h"
#include <iostream>
#include "DamageText.h"

void Enemy::Initialize(int graphHandle, int enemyHP,float startX, float startY, float moveSpeed, float exRate, bool initialAlive)
{
	graph = graphHandle;
	hp = enemyHP;
	x = startX;
	y = startY;
	speed = moveSpeed;
	scale = exRate;
	alive = initialAlive;
}

void Enemy::Update()
{
	if (!alive) return;

	//右方向に移動
	x += speed;

	//画面の右側に消えたら左側に戻す
	if (x > 1400.0f)
	{
		x = -1300.0f;
	}
}

//	敵の描画処理
void Enemy::Draw()
{
	if (!alive)
	{
		return;
	}
	DrawRotaGraph(
		static_cast<int>(x),
		static_cast<int>(y),
		scale,
		0,
		graph,
		TRUE
	);
}
int Enemy::TakeDamage(int damage)
{
	if (!alive || damage <= 0)
	{
		return 0;
	}

	int actualDamage = damage;

	hp -= actualDamage;

	if (hp <= 0)
	{
		hp = 0;
		alive = false;
	}

	return actualDamage;
}

bool Enemy::IsAlive() const
{
	return alive;
}

float Enemy::GetX() const
{
	return static_cast<float>(x);
}

float Enemy::GetY() const
{
	return static_cast<float>(y);
}

float Enemy::GetRadius() const
{
	return 35.0f;
}