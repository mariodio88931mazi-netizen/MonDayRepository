#pragma once
class Enemy
{
private:
	int hp;

public:
	Enemy();

	~Enemy()()const;

	void TakeDamage(int damage) const;
};