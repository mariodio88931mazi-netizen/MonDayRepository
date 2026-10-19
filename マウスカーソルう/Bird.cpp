#include "Bird.h"
#include "DxLib.h"
#include <iostream>
using namespace std;


Bird::Bird()
{
	int Enemy_BIRD1 = LoadGraph("img/enemy/BIRD1.png");  // ’¹1
	int Enemy_BIRD2 = LoadGraph("img/enemy/BIRD2.png");  // ’¹2

	graph = Enemy_BIRD1;
	hp = 50;
	x = -100.0f;
	y = 300.0f;
	speed = 3.0f;
	scale = 0.2f;
	alive = true;
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
	hp -= damage;
	if (hp <= 0)
	{
		alive = false;
	}
}