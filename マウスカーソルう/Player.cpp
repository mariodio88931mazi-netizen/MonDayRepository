#include "Player.h"
#include "Dxlib.h"

void Player::Initialize
(
	int hp,
	int startx,
	int starty,
	int exp,
	int level,
	float moveEasing
)
{
}

void Player::Draw()
{
	DrawCircle(400, 300, 50, GetColor(255, 0, 0), TRUE);
}

void Player::Update()
{
	int mauseX, mouseY;

	// マウスの現在位置を取得
	GetMousePoint(&mauseX, &mouseY);



}