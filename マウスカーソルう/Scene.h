#pragma once
#include "DxLib.h"

extern int stageSelect;
extern const int stageMax;

extern bool isPushEnter;
extern bool isPushDown;
extern bool isPushUp;

enum Scene {
	Start,
	Init,
	Game,
	End
};

void StartScene();

