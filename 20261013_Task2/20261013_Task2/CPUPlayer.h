#pragma once
#include "Player.h"

class CPUPlayer :public Player
{
public:
	Action ChooseAction(int card, int pot) override;
};

