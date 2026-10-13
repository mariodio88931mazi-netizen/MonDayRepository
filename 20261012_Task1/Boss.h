#pragma once
#include "Character.h"
class Boss :public Character
{
public:
	Boss(std::string name);
	void Attack();
};

