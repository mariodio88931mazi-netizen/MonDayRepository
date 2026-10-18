#pragma once
#include "Player.h"

class HumanPlayer:public Player
{
public:
	Action ChooseAction(int card, int pot) override;
};

