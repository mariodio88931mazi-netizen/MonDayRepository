
#include "Enemy.h"
#include <iostream>

Enemy::Enemy()
{
    hp = 100;
}

int Enemy::GetHp() const
{
    return hp;
}

void Enemy::Draw() const
{
    std::cout << "Enemy HP : " << hp << std::endl;
}
