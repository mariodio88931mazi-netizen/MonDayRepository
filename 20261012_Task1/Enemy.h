#pragma once
#include"Character.h"
using namespace std;

class Enemy :public Character
{
public:
	Enemy(string name);
	void Attack()override;
};