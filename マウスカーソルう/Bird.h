#pragma once
#include "Enemy.h"
class Bird : public Enemy
{
public:
	// ‰æ‘œ“Ç‚İ‚İ
	int Enemy_BIRD1;
	int Enemy_BIRD2;

	Bird();
	~Bird() {}

	float GetX() const override;
	float GetY() const override;

	void TakeDamage(int damage) override;
};
