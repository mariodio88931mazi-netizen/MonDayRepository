#include "Enemy.h"
#include<iostream>
using namespace std;

Enemy::Enemy(string name) :Character(name) {}

void Enemy::Attack()
{
	cout << "嚙みつき攻撃！" << endl;
}