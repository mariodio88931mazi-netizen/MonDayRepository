#include "Enemy.h"
#include "DxLib.h"
#include <iostream>

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
	//‰E•ûŒü‚ÉˆÚ“®
	x += speed;

	//‰æ–Ê‚Ì‰E‘¤‚ÉÁ‚¦‚½‚ç¶‘¤‚É–ß‚·
	if (x > 1400.0f)
	{
		x = -1300.0f;
	}
}

//	“G‚Ì•`‰æˆ—
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

float Enemy::GetX() const
{
	return static_cast<float>(x);
}

float Enemy::GetY() const
{
	return static_cast<float>(y);
}

void Enemy::TakeDamage(int damage)
{
	if (!alive)
	{
		return;
	}
	hp -= damage;
	if (hp <= 0)
	{
		hp = 0;
		alive = false;
	}
}

bool Enemy::IsAlive() const
{
	return alive;
}
