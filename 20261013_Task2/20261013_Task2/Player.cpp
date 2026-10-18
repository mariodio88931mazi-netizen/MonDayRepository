#include "Player.h"
using namespace std;

Player::Player()
{
	chips = 11;
}

void Player::PayChip()
{
	if (chips > 0)
	{
		chips--;
	}
}

void Player::TakeCard(int card, int pot)
{
	cards.push_back(card);
	chips += pot;
}

int Player::GetChips() const
{
	return chips;
}

int Player::CalculateScore() const
{
	int cardScore = 0;
	int previousCard = -1;

	vector<int> sortedCards = cards;

	for (int i = 0; i < static_cast<int>(sortedCards.size()); i++)
	{
		for (int j = i + 1;j < static_cast<int>(sortedCards.size());j++)
		{
			if (sortedCards[i] > sortedCards[j])
			{
				int temp = sortedCards[i];
				sortedCards[i] = sortedCards[j];
				sortedCards[j] = temp;
			}
		}
	}

	for (int card : sortedCards)
	{
		if (previousCard == -1 || card != previousCard + 1)
		{
			cardScore += card;
		}

		previousCard = card;
	}

	return cardScore - chips;
}

