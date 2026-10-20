#pragma once
#include "DxLib.h"

class Sword
{
private:
    int graph;     // 剣の画像
	int exp;       // 剣の経験値
	int level;     // 剣のレベル
	float angle;        // 現在の角度
	float targetAngle;  // 目標の角度
	float rotationSpeed; // 回転速度
    float x, y;         // 剣の現在位置
    float scale;        // 剣の大きさ
    float easing;       // 移動のなめらかさ
	bool attack;        // 攻撃中かどうかのフラグ

public:
    // 初期化
    void Initialize(
        int graphHandle,
        float startX,
        float startY,
        float startAngle,
        float exRate,
        float moveEasing,
        bool isAttacking
    );

	void GetSwordSegment(float& startx, float& starty, float& endx, float& endy) const;

	// 座標取得(当たり判定用)
    float GetX() const;
	float GetY() const;

    // 移動処理
    void Update();

    // 描画処理
    void Draw();
	void DrawEffect(float x, float y, float scale, float angle);

	float GetAttack() const;
};