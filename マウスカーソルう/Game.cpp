#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include "DxLib.h"
#include "Game.h"
#include "Enemy.h"
#include "Sword.h"
#include "Bird.h"
#include "skeleton.h"
float PointToSegmentDistance(float px, float py, float ax, float ay, float bx, float by)
{
	float abX = bx - ax;
	float abY = by - ay;

	float apX = px - ax;
	float apY = py - ay;

	float lengthSquared = abX * abX + abY * abY;

	// 線分の長さが0の場合
	if (lengthSquared == 0.0f)
	{
		float dx = px - ax;
		float dy = py - ay;
		return sqrt(dx * dx + dy * dy);
	}

	float t = (apX * abX + apY * abY) / lengthSquared;

	// 線分の範囲に制限
	if (t < 0.0f)
	{
		t = 0.0f;
	}
	else if (t > 1.5f)
	{
		t = 1.5f;
	}

    float closestX = ax + t * abX;
	float closestY = ay + t * abY;

	float dx = px - closestX;
	float dy = py - closestY;

	return sqrt(dx * dx + dy * dy);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // 画面モードの初期化など
    SetGraphMode(1280, 720, 32);

    SetWindowText("FrySord!");

    ChangeWindowMode(TRUE);
    if (DxLib_Init() == -1) return -1;
    SetDrawScreen(DX_SCREEN_BACK);

    // 画像の読み込み
    SwordGraph = LoadGraph("img/sord.png");           // 剣
    BackGround = LoadGraph("img/BackGround.png");    // 背景
    // エフェクト
	SwordEffect = LoadGraph("img/effect/swordeffect.png");  // 剣の軌道
    
	// 敵２スケルトン
	Enemy_SKELETON1 = LoadGraph("img/enemy/skeleton1.png");  // スケルトン

    //プレイヤーオブジェクツ
    Sword sword;
    //敵オブジェクト作成
    Bird birdEnemy;
    Skeleton skeletonEnemy;

    // プレイヤー初期化
    sword.Initialize(SwordGraph,640.0f, 360.0f, angle, exRate, easing, false);

    // 画像のサイズを取得
    GetGraphSize(SwordGraph, &imgW, &imgH);

   
    // OS標準のマウスカーソルを非表示にする
    SetMouseDispFlag(FALSE);

    // メインループ
    while (ProcessMessage() == 0 && ScreenFlip() == 0 && ClearDrawScreen() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        //スクロール
        bgX += scrollSpeed;

        if (bgX >= screenWidth)
        {
            bgX = 0.0;
        }

        // 背景描写
        DrawExtendGraph(static_cast<int>(bgX),
            0,
            static_cast<int>(bgX) + screenWidth,
            720,
            BackGround,
            FALSE);

        // 2枚目の背景（スクロール用）
        DrawExtendGraph(static_cast<int>(bgX) + -screenWidth,
            0,
            static_cast<int>(bgX) + screenWidth * 2,
            720,
            BackGround,
            FALSE);

        // 敵の移動・表示
        birdEnemy.Update();
        sword.Update();

        if (sword.GetAttack() == true)
        {
			float startX, startY, endX, endY;

			
            if (birdEnemy.IsAlive())
            {
                sword.GetSwordSegment(startX, startY, endX, endY);
                
                float distance = PointToSegmentDistance(birdEnemy.GetX(), birdEnemy.GetY(), startX, startY, endX, endY);
                
				const float enemyRadius = 50.0f; // 敵の半径（当たり判定用）

				const float swordRadius = 12.0f; // 剣の半径（当たり判定用）

                if (distance <= enemyRadius + swordRadius)  // 剣と敵の距離が近い場合
                {
                    birdEnemy.TakeDamage(1);
                    DrawFormatString(600, 600, GetColor(255, 0, 0), "HIT!");
					sword.DrawEffect(birdEnemy.GetX(), birdEnemy.GetY(), 1.0f, SwordEffect);
					WaitTimer(10); // 10ミリ秒待機
                }
            }
        }

        //描画
        birdEnemy.Draw();
        sword.Draw();
    }
        DxLib_End();
        return 0;
}
