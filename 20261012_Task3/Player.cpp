#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(string name) :Character(name) {}

void Player::Attack()
{
	cout << "剣で攻撃した！" << endl;
}