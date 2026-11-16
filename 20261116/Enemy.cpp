#include "Enemy.h"
#include <iostream>

// コンストラクタ
Enemy::Enemy(const std::string& name) : name(name), hp(100)
{
	std::cout << name << "が出現した\n";
}

// デストラクタ
Enemy::~Enemy()
{
	std::cout << "名前" << "は破棄されました。\n";
}

// 表示
void Enemy::Draw() const
{
	std::cout << "名前" << name << "\n";
	std::cout << "HP" << hp << "\n";
}