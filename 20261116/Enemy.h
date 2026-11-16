#include <iostream>
#include <string>
#pragma once
class Enemy
{
private:
	std::string name;
	int hp;

public:
	Enemy(const std::string& name);

	~Enemy();

	void Draw()const;
};