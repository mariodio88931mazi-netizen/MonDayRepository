#include <iostream>
#include "Player.h"
#include "Config.h"
#include "Dxlib.h"

void ATTACK(Character& target)
{
	int randomValue = (rand() % RANDOM_ATTACK_MAX) + MIN_VALUE;

	if (randomValue > 0)
	{
		int damage = ATK + randomValue - target.DEF;

		if (damage < 0)
		{
			damage = 0;
		}

		target.HP -= damage;
	}
	else
	{
		cout << "UŒ‚‚ªŠO‚ê‚½I" << endl;
	}
}