#pragma once

class Player
{
private:
    int HP;                 // 体力
    int EXP;                // 経験値
    int Level;              // レベル
    int Powor;              // 攻撃力

    float X, Y;             // 現在の座標
    float targetX, targetY; // 目標座標
    float move;              // 移動のなめらかさ

    bool alive;              // 生存状態

    int invincibleTimer;     // 無敵時間
    int invincibleDuration;  // 無敵時間の長さ

public:
    void Initialize(
        int hp,
        int startx,
        int starty,
        int exp,
        int level,
        int AttackPowor,
        float moveEasing,
        bool alivecheck
    );

    void Draw();
    void Update();

    void HitCheck();
    int TakeDamage(int damage);

    // 追加する関数
    float GetX() const;
    float GetY() const;
    int GetHP() const;
    int GetAttackPower() const;
    bool IsAlive() const;
    bool IsInvincible() const;
};