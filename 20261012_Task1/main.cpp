#include <iostream>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Boss.h"
using namespace std;

int main(void)
{
	string playerName;
	string enemyName;
	string bossName;
	cout << "名前を入力してください" << endl;
	cout << "勇者" << endl;
	cin >> playerName;
	cout << "敵" << endl;
	cin >> enemyName;
	cout << "ボス" << endl;
	cin >> bossName;

	Player player(playerName);
	Enemy enemy(enemyName);
	Boss boss(bossName);

	cout << "プレイヤーの名前" << player.GetName() << endl;
	cout << "敵の名前" << enemy.GetName() << endl;
	cout << "ボスの名前" << boss.GetName() << endl;

	player.Attack();
	enemy.Attack();
	boss.Attack();
}