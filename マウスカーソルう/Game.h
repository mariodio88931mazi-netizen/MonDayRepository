#pragma once
#include "DxLib.h"


// 画像各種
int SwordGraph;
int BackGround;
int Enemy_BIRD1;
int Enemy_BIRD2;
int Enemy_SKELETON1;
int SwordEffect;

// 画像の縦横大きさ
int imgW, imgH;

// 背景スクロール用変数S
double bgX = 0.0;
double scrollSpeed = 2.0;
int screenWidth = 1300;

// マウスの位置
int mouseX, mouseY;

//敵の位置
double enemyX = 1300.0;
double enemyY = 300.0;

// 敵の移動速度
double enemySpeed = 3.0;

// 画像の現在位置
double currentX = 0.0;
double currentY = 0.0;

// 追従の滑らかさ
double easing = 0.08;

// 剣の大きさ（0.1倍 = 元のサイズの10%）
double Rangi = 0.0;
double exRate = 0.2 + Rangi;
// 剣の角度
double angle;

// 時間
double counttime = 0.0;
float addTime = 0.001;

void timer(bool stoptime, double maxTime);