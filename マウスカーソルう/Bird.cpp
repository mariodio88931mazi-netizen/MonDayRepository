#include "Bird.h"
#include "DxLib.h"
#include <iostream>
using namespace std;


Bird::Bird()
{
	graph = -1;
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