#include<iostream>
#include "Player.h"
#include "Enemy.h"
#include "Boss.h"
#include "Wizrad.h"
#include "BattleManager.h"
int main(void)
{
	//コンストラクタ
	Player player("勇者ヨシヒコ");
	Wizrad wizrad("魔法使い");
	Enemy enemy("スライム");
	Boss boss("魔王");

	BattleManager manager;

	manager.StartBattle(&player);
	manager.StartBattle(&wizrad);
	manager.StartBattle(&enemy);
	manager.StartBattle(&boss);

	return 0;
}
