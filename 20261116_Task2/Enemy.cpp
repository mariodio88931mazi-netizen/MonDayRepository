#include "Enemy.h"
#include <iostream>

// コンストラクタ
Enemy::Enemy(const std::string& name) : name(name), hp(100)
{
    id = ;
    hp = 3;
	std::cout << name << "が出現した\n";
}

void Enemy::TakeDamage(int damage)
{
    if (!IsAlive())
    {
        cout << "この敵は既に倒されています！" << endl;
        return;
    }

    hp -= damage;

    if (hp < 0)
    {
        hp = 0;
    }

    cout << "敵" << id << "に"
        << damage << "ダメージ！" << endl;
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

// 生存確認
bool Enemy::IsAlive() const
{
	return hp > 0;
}