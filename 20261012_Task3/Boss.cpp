#include "Boss.h"
#include <iostream>
using namespace std;

Boss::Boss(string name) :Character(name) {}
void Boss::Attack()
{
	cout << "強力な必殺技を放った！" << endl;
}