#pragma once
class VendingManchine
{
private:
	int money;     //Ç®ã‡(é©îÃã@)
	int colaStock; //ç›å…
public:
	VendingManchine();
	void insertMoney(int amount);
	void buyCola();
	int getMoney() const;
	int getColaStock() const;
};