#pragma once
#include "Sword.h"

class Enemy
{
protected:
	//敵のHP
	int hp;
	// 敵の座標
	double y;
	double x;
	// 敵の速度
	double speed;
	// 敵の見た目
	int graph;
	// 拡大率
	float scale;
	// 敵の生死
	bool alive;
public:
	//コンストラクタ
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

	//デストラクタ
	virtual ~Enemy() {}

	//初期化
	virtual void Initialize(int graphHandle, int enemyHP,float sstartX, float startY, float movespeed, float exRate, bool initialAlive);

	//// 死亡
	//virtual void Die();
	//{
	//	sword->levelUp(1); // 経験値を1増やす
	//}

	//敵の移動
	void Update();

	//てきの描画
	void Draw();

	//座標取得(当たり判定用)
	virtual float GetX() const;
	virtual float GetY() const;

	//ダメージを受ける
	virtual void TakeDamage(int damage);

	//生きているか
	bool IsAlive() const;
};

