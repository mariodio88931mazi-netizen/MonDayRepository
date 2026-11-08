#include "DamageText.h"
#include "DxLib.h"

void DamageText::Initialize(int damageValue, float posX, float posY)
{
    damage = damageValue;

    x = posX;
    y = posY;

    startTime = GetNowCount();
    duration = 1000; // 1000ƒ~ƒŠ•b = 1•b

    active = true;
}

void DamageText::Update()
{
    if (!active) return;

    // 1•bŒo‰ß‚µ‚½‚çÁ‚·
    if (GetNowCount() - startTime >= duration)
    {
        active = false;
    }
}

void DamageText::Draw(int colorR,int colorG,int colorB)
{
    if (!active) return;

    DrawFormatString(
        (int)x,
        (int)y,
        GetColor(colorR, colorG, colorB),
        "%d",
        damage
    );
}

bool DamageText::IsActive() const
{
    return active;
}