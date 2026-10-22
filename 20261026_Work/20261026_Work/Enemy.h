#pragma once
#include "Character.h"
using namespace std;

class Enemy :public Character
{
public:
	void Attack() override;
};

