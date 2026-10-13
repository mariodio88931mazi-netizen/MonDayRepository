#pragma once
#include<string>
class Character
{
private:
	std::string name;

public:
	Character(std::string name);
	virtual ~Character() = default;
	std::string GetName();
	virtual void Attack();
};