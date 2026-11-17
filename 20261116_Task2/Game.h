#pragma once
#include <memory>
#include <vector>
#include "Enemy.h"
#include "Config.h"
class Game
{
private:
	std::vector<std::shared_ptr<Enemy>> enemies;
public:
};

