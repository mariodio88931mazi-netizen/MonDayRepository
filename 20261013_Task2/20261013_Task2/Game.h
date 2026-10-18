#pragma once
#include <vector>
#include "Player.h"
#include "HumanPlayer.h"]
#include "CPUPlayer.h"
using namespace std;

class Game
{
private:
	HumanPlayer human;
	CPUPlayer cpu1;
	CPUPlayer cpu2;

	Player* Players[3];
	vector<int> deck;

public:
	Game();

	void Initialize();
	void Run();
	void ShowResult() const;
};

