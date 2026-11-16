#include<iostream>
#include<memory>
#include"Enemy.h"

int main(void)
{
	std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>("ƒXƒ‰ƒCƒ€");

	enemy->Draw();
	std::cout << "Š—LŽÒ‚Ì”" << enemy.use_count() << "\n";

	return 0;
}