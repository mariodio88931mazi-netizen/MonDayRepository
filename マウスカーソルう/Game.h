#pragma once
#include "DxLib.h"


// 画像各種
extern int SwordGraph;
extern int BackGround;
extern int Enemy_BIRD1;
extern int Enemy_BIRD2;
extern int Enemy_SKELETON1;
extern int SwordEffect;

// 画像の縦横大きさ
extern int imgW, imgH;

// 背景スクロール用変数S
extern double bgX;
extern double scrollSpeed;
extern int screenWidth;

// マウスの位置
extern int mouseX, mouseY;

//敵の位置
extern double enemyX;
extern double enemyY;

// 敵の移動速度
extern double enemySpeed;

// 画像の現在位置
extern double currentX;
extern double currentY;

// 追従の滑らかさ
extern double easing;

// 剣の大きさ（0.1倍 = 元のサイズの10%）
extern double Rangi;
extern double exRate;
// 剣の角度
extern double angle;

// 時間
extern double counttime;
extern float addTime;

void timer(bool stoptime, double maxTime);

float PointToSegmentDistance(
    float px, float py,
    float ax, float ay,
    float bx, float by);

bool GameInitialize();

void GameUpdate();

void GameDraw();

void GameFinalize();