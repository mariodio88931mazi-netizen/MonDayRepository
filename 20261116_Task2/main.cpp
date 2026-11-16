#include<iostream>
#include<memory>
#include"Enemy.h"
using namespace std;

int main(void)
{
	std::shared_ptr<Enemy> enemy[3];
	for (int i = 0; i < 3; i++)
	{
		enemy[i] = std::make_shared<Enemy>(i);
	}
	int target;

	while(true)
	{
		for (int i = 0; i < 3; i++)
		{
			enemy[i]->Draw();
			std::cout << "Š—LŽÒ‚Ì”" << enemy[i].use_count() << "\n";
		}
		
		// UŒ‚‘ÎÛ‘I‘ð
		cout << "\nUŒ‚‚·‚é“G‚ð‘I‘ð‚µ‚Ä‚­‚¾‚³‚¢ (1`3): ";
		cin >> target;

		// ‘Sˆõ“|‚µ‚½‚©Šm”F
		bool allDead = true;

		for (const auto& enemy : enemy)
		{
			if (enemy->IsAlive())
			{
				allDead = false;
				break;
			}
		}

		if (allDead)
		{
			cout << "\n‘S‚Ä‚Ì“G‚ð“|‚µ‚½I" << endl;
			break;
		}

		// “ü—Íƒ`ƒFƒbƒN
		if (target < 1 || target > 3)
		{
			cout << "1`3‚Ì”Žš‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢I" << endl;
			continue;
		}

		// ‘I‘ð‚µ‚½“G‚ðŽæ“¾
		Enemy* enemy = enemy[target - 1].get();

		// Ž€–Sƒ`ƒFƒbƒN
		if (!enemy->IsAlive())
		{
			cout << "‚»‚Ì“G‚ÍŠù‚É“|‚³‚ê‚Ä‚¢‚Ü‚·I" << endl;
			continue;
		}

		// 30ƒ_ƒ[ƒW
		enemy->TakeDamage(30);
	}
	

	return 0;
}