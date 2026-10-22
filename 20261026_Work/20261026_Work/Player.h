#pragma once
#include "Character.h"
using namespace std;

class Player:public Character
{
public:
	void Attack() override;
};

