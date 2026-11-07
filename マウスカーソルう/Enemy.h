#pragma once

class Enemy
{
protected:
    int hp;
    double y;
    double x;
    double speed;
    int graph;
    float scale;
    bool alive;

public:
    Enemy()
    {
        hp = 0;
        x = 0.0f;
        y = 0.0f;
        speed = 0.0f;
        graph = -1;
        scale = 1.0f;
        alive = false;
    }

    virtual ~Enemy() {}

    virtual void Initialize(
        int graphHandle,
        int enemyHP,
        float startX,
        float startY,
        float moveSpeed,
        float exRate,
        bool initialAlive
    );

    // virtual‚ð’Ç‰Á
    virtual void Update();
    virtual void Draw();

    virtual float GetX() const;
    virtual float GetY() const;

    virtual int TakeDamage(int damage);

    bool IsAlive() const;
    float GetRadius() const;
};