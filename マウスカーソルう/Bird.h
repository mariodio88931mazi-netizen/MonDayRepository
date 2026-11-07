#pragma once
#include "Enemy.h"

class Bird : public Enemy
{
public:
    int birdGraph[2];

    int animationFrame;
    int animationTimer;

    Bird();

    void SetAnimationGraphs(int graph1, int graph2);

    void Update() override;
    void Draw() override;

    float GetX() const override;
    float GetY() const override;

    int TakeDamage(int damage) override;
};