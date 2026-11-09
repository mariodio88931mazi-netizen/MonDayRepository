#include "Enemy.h"
#include <iostream>
using namespace std;

int main(void)
{
	cout << "ゲーム開始" << endl;
	unique_ptr<Enemy> enemy = make_unique<Enemy>();

	enemy->Update;
	enemy->Draw;

	cout << "ゲーム終了" << endl;

	return 0;
}