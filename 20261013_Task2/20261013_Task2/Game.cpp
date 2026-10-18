#include "Game.h"

#include <algorithm>
#include <iostream>
#include <random>
using namespace std;

Game::Game()
{
	Players[0] = &human;
	Players[1] = &cpu1;
	Players[2] = &cpu2;
}

void Game::Initialize()
{
	deck.clear();

	// 3～35のカードを使用	
	for (int card = 0; card <= 35 ; card++)
	{
		deck.push_back(card);
	}

	// カードをシャッフルする
	random_device rd;  // random_device：乱数の種に使う値を取得するための機能
	mt19937 gen(rd()); // mt19937 : 乱数生成器
	shuffle(deck.begin(), deck.end(), gen); //デッキの始まり(deck.begin)から
	                                        //デッキの終わり(deck.end)までシャッフル
											//gen = mt19937	で作った乱数
	// 24枚使用
	deck.resize(24);

	cout << "====== ゲームスタート！ =====\n";
	cout << "あなたはプレイヤー1です。\n";
	cout << "CPUが2人相手します。\n\n";
}

void Game::Run()
{
	int currentPlayer = 0;

	// 24枚のカードを順番に公開する
	for (int card : deck)
	{
		int pot = 0;
		bool cardTaken = false;

		cout << "\n===========================\n";
		cout << "公開カード:" << card << "\n";

		// 誰かがカードを取るまで手番を回す
		while (!cardTaken)
		{
			Player* player = Players[currentPlayer];

			cout << "\nプレイヤー"
				<< currentPlayer + 1 << "の番です\n\n";

			Action action = player->ChooseAction(card, pot);

			if (action == Action::TakeCard || player->GetChips() == 0)
			{
				player->TakeCard(card, pot);

				cout << "プレイヤー"
					<< currentPlayer + 1
					<< "がカード" << card
					<< "を取りました。\n\n";

				cout << "受け取ったチップ:" 
					<< pot << "枚\n";


				cardTaken = true;
			}
			else
			{
				player->PayChip();
				pot++;

				cout << "チップを１枚支払いました。\n";
				cout << "場のチップ:" << pot << "枚\n";

				// 次のプレイヤーへ
				currentPlayer = (currentPlayer + 1) % 3;
			}
		}

		//カードを取ったプレイヤーの次から開始
		currentPlayer = (currentPlayer + 1) % 3;
	}

	cout << "\n山札がなくなりました！\n";
}

void Game::ShowResult() const
{
	cout << "\n====== 結果発表 ======\n";
	int bestScore = 100000;

	for (int i = 0;i < 3;i++)
	{
		int score = Players[i]->CalculateScore();

		cout << "プレイヤー" << i + 1 << ":得点" << score
			<< "点、チップ"
			<< Players[i]->GetChips()
			<< "枚\n";

		if (score < bestScore)
		{
			bestScore = score;
		}
	}

	cout << "\n勝者:";

	for (int i = 0; i < 3; i++)
	{
		if (Players[i]->CalculateScore() == bestScore)
		{
			cout << "プレイヤー" << i + 1 << " ";
		}
	}

	cout << "\n======================================\n";

}