#include<iostream>
#include"VendingManchine.h"
using namespace std;

int main(void)
{
	//	コンストラクタ
	VendingManchine machine;
	cout << "お金を投入してください。\n" << endl;
	int  insertMoney;
	cin >> insertMoney;

	machine.insertMoney(insertMoney);
	machine.buyCola();

	cout << "残金：" << machine.getMoney() << "円\n";
	cout << "残りのコーラの在庫:" << machine.getColaStock() << "本\n";

	return 0;
}