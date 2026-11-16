#include <iostream>
#include <string>
#pragma once
class Enemy
{
private:
	std::string name;
	int hp;
	int id;

public:
	Enemy(const std::string& name);

	~Enemy();

	void Draw()const;

	// ê∂ë∂ämîF
	bool IsAlive()const;

	void TakeDamage(int damage) const;
};