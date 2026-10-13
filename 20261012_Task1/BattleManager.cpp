#include "BattleManager.h"
#include<iostream>
using namespace std;

void BattleManager::StartBattle(Character* character)
{
	cout << character->GetName() << endl;
	character->Attack();
}