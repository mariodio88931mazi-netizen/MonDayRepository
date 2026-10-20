#include <iostream>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Boss.h"

using namespace std;


int main()
{
    Player player;
    Enemy enemy;
    Boss boss;


    Character* characters[3];

    characters[0] = &player;
    characters[1] = &enemy;
    characters[2] = &boss;

    for (int i = 0; i < 3; i++)
    {
        characters[i]->Attack();
    }

    return 0;
}