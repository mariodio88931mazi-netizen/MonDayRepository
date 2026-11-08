#pragma once

class DamageText
{
private:
    int damage;         // ダメージ量
    float x, y;         // 表示位置
    int startTime;      // 表示開始時間
    int duration;       // 表示時間
    bool active;        // 表示中か

public:
    void Initialize(int damageValue, float posX, float posY);
    void Update();
    void Draw(int colorR, int colorG, int colorB);
    bool IsActive() const;
};