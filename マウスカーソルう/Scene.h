#pragma once
#include "DxLib.h"

extern int stageSelect = 0;
extern const int stageMax = 5;

extern bool isPushEnter = false;
extern bool isPushDown = false;
extern bool isPushUp = false;

enum Scene {
	Start,
	Init,
	Game,
	End
};

