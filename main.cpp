#include <iostream>
#include "Config.h"
#include "Enemy.h"
#include "Player.h"

using namespace std;

int main()
{
    Player player;
    Enemy enemy;

    while (player.IsAlive() && enemy.IsAlive())
    {
        int action;

        cout << "==============================" << endl;
        cout << "        プレイヤーのターン！" << endl;
        cout << "==============================" << endl;

        cout << "現在のHP：" << player.GetHP() << endl;
        cout << "1:攻撃" << endl;
        cout << "2:回復" << endl;

        cin >> action;
        if (action < 1 || action > 2)
        {
            continue;
        }

        // プレイヤーのターン
        if (action == 1)
        {
            cout << "プレイヤーの攻撃！" << endl;
            player.ATTACK(enemy);
        }
        else if (action == 2)
        {
            player.Heal();
        }

        // 敵が倒れたか確認
        if (!enemy.IsAlive())
        {
            cout << "勝利！" << endl;
            break;
        }

        // 敵のターン
        cout << "============================\n"
            << "　　　　　敵のターン!\n"
            << "============================" << endl;
        cout << "現在のHP：" << enemy.GetHP() << endl;
        int enemyAction = rand() % 2 + 1;

        if (enemyAction == 1)
        {
            cout << "敵の攻撃！" << endl;
            enemy.ATTACK(player);
        }
        else
        {
            enemy.Heal();
        }
    }

    return 0;
}