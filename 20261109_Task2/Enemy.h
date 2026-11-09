
#pragma once

class Enemy
{
private:
    int hp;

public:
    // コンストラクタ
    Enemy();

    // HP取得
    int GetHp() const;

    // Enemy描画
    void Draw() const;
};
