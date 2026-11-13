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

    // 無敵時間の初期化
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

    // 無敵時間を減らす
    if (invincibleTimer > 0)
    {
        invincibleTimer--;
    }
}

void Player::Draw()
{
    if (!alive) return;

    // 無敵中は点滅させる
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
    // 死亡中・無敵中・ダメージ0以下なら何もしない
    if (!alive || invincibleTimer > 0 || damage <= 0)
    {
        return 0;
    }

    int actualDamage = damage;

    // HP以上のダメージを受けた場合
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

    // 約1秒間無敵
    invincibleTimer = invincibleDuration;

    return actualDamage;
}

void Player::LevelUp()
{

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
    // 今回はGame.cpp側で敵との接触判定を行う
}