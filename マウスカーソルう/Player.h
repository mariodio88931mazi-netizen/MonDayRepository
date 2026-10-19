#pragma once
// 個々の初期化部分から

class Player
{
private:
	int hp;			// 体力
	int exp;		// 経験値
	int level;		// レベル
	float x, y;		// 現在の座標
	float targetX, targetY; // 目標の座標
	float moveEasing; // 移動のなめらかさ
public:
	void Initialize
	(
		int hp,
		int startx,
		int starty,	
		int exp,
		int level,
		float moveEasing
	);

	// 座標取得
	float GetX() const;
	float GetY() const;

	// 座標
	void Draw();
	// 移動処理
	void Update();
};

