#include "Enemy.h"
#include <iostream>
using namespace std;

Enemy::Enemy()
{
	cout << "Enemyを生成しました。" << endl;
}

Enemy::~Enemy()
{
	cout << "Enemyを破棄しました。" << endl;
}

void Enemy::Update()
{
	cout << "Enemyを更新しました。" << endl;
}

void Enemy::Draw()
{
	cout << "Enemyを描画しました。" <<
}