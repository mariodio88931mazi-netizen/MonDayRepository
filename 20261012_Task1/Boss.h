#pragma once
#include"Character.h"
using namespace std;

class Boss :public Character
{
public:
	Boss(string name);
	void Attack()override;
};