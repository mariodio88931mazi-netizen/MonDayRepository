#include "Character.h"
#include <iostream>
using namespace std;

Character::Character(string name)
{
	this->name = name;
}

string Character::GetName()
{
	return name;
}

void Character::Attack()
{
	cout << "UŒ‚‚µ‚½I" << endl;
}