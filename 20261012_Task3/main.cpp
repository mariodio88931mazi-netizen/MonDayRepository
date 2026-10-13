#include<iostream>
#include "Player.h"
#include "Enemy.h"
#include "Boss.h"
#include "BattleManager.h"
int main(void)
{
	//コンストラクタ
	Player player("勇者ヨシヒコ");
	Enemy enemy("スライム");
	Boss boss("魔王");

	BattleManager manager;

	manager.StartBattle(&player);
	manager.StartBattle(&enemy);
	manager.StartBattle(&boss);

	return 0;
}