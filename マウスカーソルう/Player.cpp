#include "Player.h"
#include "DxLib.h"
#include "Game.h"

void Player::Initialize(
    int hp,
    int startx,
    int starty,
    int exp,
    int level,
    int AttackPowor,
    float moveEasing,
    bool alivecheck
)
{
    HP = hp;
    EXP = exp;
    Level = level;
    Powor = AttackPowor;

    X = startx;
    Y = starty;

    targetX = startx;
    targetY = starty;

    move = moveEasing;
    alive = alivecheck;

    // –³“GŠÔ‚Ì‰Šú‰»
    invincibleTimer = 0;
    invincibleDuration = 60;
}

void Player::Update()
{
    if (!alive) return;

    int mouseX, mouseY;

    GetMousePoint(&mouseX, &mouseY);

    X += (mouseX - X) * move;
    Y += (mouseY - Y) * move;

    // –³“GŠÔ‚ğŒ¸‚ç‚·
    if (invincibleTimer > 0)
    {
        invincibleTimer--;
    }
}

void Player::Draw()
{
    if (!alive) return;

    // –³“G’†‚Í“_–Å‚³‚¹‚é
    if (invincibleTimer == 0 || invincibleTimer % 10 < 5)
    {
        int Color = GetColor(255, 0, 0);
        DrawCircle(
            static_cast<int>(X),
            static_cast<int>(Y),
            10,
            Color,
            TRUE
        );
    }

    DrawFormatString(
        20, 50,
        GetColor(255, 255, 255),
        "PLAYER HP : %d",
        HP
    );
}

int Player::TakeDamage(int damage)
{
    // €–S’†E–³“G’†Eƒ_ƒ[ƒW0ˆÈ‰º‚È‚ç‰½‚à‚µ‚È‚¢
    if (!alive || invincibleTimer > 0 || damage <= 0)
    {
        return 0;
    }

    int actualDamage = damage;

    // HPˆÈã‚Ìƒ_ƒ[ƒW‚ğó‚¯‚½ê‡
    if (actualDamage > HP)
    {
        actualDamage = HP;
    }

    HP -= actualDamage;

    if (HP <= 0)
    {
        HP = 0;
        alive = false;
    }

    // –ñ1•bŠÔ–³“G
    invincibleTimer = invincibleDuration;

    return actualDamage;
}

float Player::GetX() const
{
    return X;
}

float Player::GetY() const
{
    return Y;
}

int Player::GetHP() const
{
    return HP;
}

int Player::GetAttackPower() const
{
    return Powor;
}

bool Player::IsAlive() const
{
    return alive;
}

bool Player::IsInvincible() const
{
    return invincibleTimer > 0;
}

void Player::HitCheck()
{
    // ¡‰ñ‚ÍGame.cpp‘¤‚Å“G‚Æ‚ÌÚG”»’è‚ğs‚¤
}