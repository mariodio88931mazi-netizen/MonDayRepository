#include "Player.h"
#include "Dxlib.h"

void Player::Initialize
(
	int handgraph,
	int hp,
	int startx,
	int starty,
	int exp,
	int level,
	float moveEasing
)
{
	graph = handgraph;
	HP = hp;
	EXP = exp;
	Level = level;
	X = startx;
	Y = starty;
	move = moveEasing;
}

void Player::Update()
{
	int mouseX, mouseY;

	// マウスの現在位置を取得
	GetMousePoint(&mouseX, &mouseY);

	X += (mouseX - X) * move;
	Y += (mouseY - Y) * move;
}

void Player::Draw()
{
	// プレイヤーの座標を表示
	DrawFormatString(
		20, 50,
		GetColor(255, 255, 255),
		"X: %f  Y: %f",
		X, Y
	);

	// 画面中央に赤い円を強制表示
	DrawRotaGraph2
	(
		static_cast<int>(x),
		static_cast<int>(y),
		625,
		85,
		TRUE
	);
}