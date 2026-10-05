#include <iostream>
#include <string>
#include "Config.h"
#include "Dxlib.h"

class Character
{
protected:
	int HP;
	int ATK;
	int DEF;
	int EVA;

public:

	Character()
	{
		HP = MAX_HP;
		ATK = (rand() % MAX_VALUE) + MIN_VALUE;
		DEF = (rand() % MAX_VALUE) + MIN_VALUE;
		EVA = (rand() % MAX_VALUE) + MIN_VALUE;
	};
};