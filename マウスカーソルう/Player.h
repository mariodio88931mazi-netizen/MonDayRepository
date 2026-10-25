#pragma once
// 個々の初期化部分から

class Player
{
private:
	//int graph;
	int HP;			// 体力
	int EXP;		// 経験値
	int Level;		// レベル
	float X, Y;		// 現在の座標
	float targetX, targetY; // 目標の座標
	float move; // 移動のなめらかさ
public:
	void Initialize
	(
		//int handgraph,
		int hp,
		int startx,
		int starty,	
		int exp,
		int level,
		float moveEasing
	);

	// 座標
	void Draw();
	// 移動処理
	void Update();
};

