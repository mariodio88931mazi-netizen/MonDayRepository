#pragma once

#include <vector>

enum class Action
{
	TakeCard,
	Pass
};

class Player
{
private:
	int chips;
	std::vector<int> cards;

public:
	Player();

	virtual ~Player() = default;

	virtual Action ChooseAction(int card, int pot) = 0;

	void PayChip();
	void TakeCard(int card, int pot);

	int GetChips() const;
	int CalculateScore() const;
};

