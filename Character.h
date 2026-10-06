#pragma once

#include <iostream>
#include <cstdlib>
#include "Config.h"

using namespace std;

class Character
{
protected:
    int HP;
    int ATK;
    int DEF;
    int EVA;

public:

    Character()
    {
        HP = MAX_HP;
        ATK = (rand() % MAX_VALUE) + MIN_VALUE;
        DEF = (rand() % MAX_VALUE) + MIN_VALUE;
        EVA = (rand() % MAX_VALUE) + MIN_VALUE;
    }

    int GetEVA()
    {
        return EVA;
    }

    int GetDEF()
    {
        return DEF;
    }

    int GetHP()
    {
        return HP;
    }

    void Damage(int damage)
    {
        HP -= damage;
    }

    void ATTACK(Character& target)
    {
        int Atkrandom =
            rand() % (ATTACK_MAX - ATTACK_MIN + 1) + ATTACK_MIN;

        if (Atkrandom > target.GetEVA())
        {
            int damage = ATK + Atkrandom - target.GetDEF();

            target.Damage(damage);

            cout << "攻撃成功！" << endl;
            cout << "ダメージ：" << damage << endl;
        }
        else
        {
            cout << "攻撃が外れた！" << endl;
        }
    }

    void Heal()
    {
        int HealRandom =
            rand() % (HEAL_MAX - HEAL_MIN + 1) + HEAL_MIN;

        HP += HealRandom;

        if (HP > MAX_HP)
        {
            HP = MAX_HP;
        }

        cout << "HPが" << HealRandom << "回復した！" << endl;
    }

    bool IsAlive()
    {
        return HP > 0;
    }
};