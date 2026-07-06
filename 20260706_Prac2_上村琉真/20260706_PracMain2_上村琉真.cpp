#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
const int Level_up_gauge = 20;
const int Level_MAX = 5;

enum
{
	rock,
	scissors,
	paper,
};

int main(void)
{
	int cpu{};
	int player{};
	int judge{};
	int exp{};
	int EXP{};
	int level{};

	cout << "CPUとじゃんけんを行いましょう。出す手の選択は、「ぐー：0」「ちょき：1」「ぱー：2」とします。勝つと経験値が獲得でき、閾値を越えるとレベルが上がっていきます。経験値は1〜15までランダムで取得できます。閾値は20以上です。" << endl;
	while (true)
	{
		srand((unsigned)time(NULL));

		cpu = rand() % 3;

		cout << "プレイヤーのターン！０=グー：１=チョキ：２=パー：" << endl;

		cin >> player;

		if (player < 0 || player > 2)
		{
			cout << "入力が違います。" << endl;
			continue;
		}

		switch (cpu)
		{
		case1:
			cout << "ぐー" << endl;
			break;
		case2:
			cout << "チョキ" << endl;
			break;
		case3:
			cout << "パー" << endl;
			break;
		}

		judge = player - cpu;

		if (2 == judge || -1 == judge)
		{
			exp = rand() % 16;

			EXP = EXP + exp;

			cout << "勝利！\n" << "経験値を" << exp << "獲得した！" << endl;
			cout << "現在EXP" << EXP << endl;
		}
		else if (cpu == player)
		{
			cout << "あいこ!" << endl;
		}
		else
		{
			cout << "負け！" << endl;
		}
		
	}
	return 0;
}