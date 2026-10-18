#include <iostream>
#include "HumanPlayer.h"
using namespace std;

Action HumanPlayer::ChooseAction(int card, int pot)
{
	if (GetChips() == 0)
	{
	 	cout << "チップがないため、カードを取ります。\n";
		return Action::TakeCard;
	}

	int choice;

	while (true)
	{
		cout << "\n公開カード:" << card
			<< "  場のチップ:" << pot << "\n";

		cout << "あなたのチップ:" << GetChips() << "\n\n";
		cout << "1:カードを取る　2:チップを払って回す\n";
		cout << "選択:";

		if (cin >> choice && (choice == 1 || choice == 2))
		{
			break;
		}

		cout << "1か2を入力してください。\n";
		cin.clear();
		cin.ignore(10000, '\n');
	}

	if (choice == 1)
	{
		return Action::TakeCard;
	}

	return Action::Pass;
}

