#pragma once
#include <string>
using namespace std;

class Character
{
private:
	string name;
public:
	Character(string name);

	string GetName();

	virtual void Attack();
};