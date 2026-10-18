#include "CPUPlayer.h"

Action CPUPlayer::ChooseAction(int card, int pot)
{
	if (GetChips() == 0)
	{
		return Action::TakeCard;
	}

	// 大きいカードを取る
	if (card <= 15)
	{
		return Action::Pass;
	}

	return Action::TakeCard;
}