#include "VendingManchine.h"
#include<iostream>
using namespace std;

VendingManchine::VendingManchine()
{
	money = 0;
	colaStock = 15;
}

void VendingManchine::insertMoney(int amount)
{
	if (amount > 0)
	{
		money += amount;
	}
}

void VendingManchine::buyCola()
{
	const int price = 180;
	if(money >= price && colaStock > 0)
	{
		money -= price;
		colaStock--;
		cout << "コカ・コーラを購入しました。\n";
	}
	else
	{
		cout << "購入できませんでした。\n";
	}
}

int VendingManchine::getMoney() const
{
	return money;
}

int VendingManchine::getColaStock() const
{
	return colaStock;
}