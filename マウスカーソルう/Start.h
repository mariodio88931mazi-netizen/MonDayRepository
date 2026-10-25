#pragma once
#include "DxLib.h"
#include "Scene.h"
#include <Windows.h>

Scene StartScene() {

	if (GetAsyncKeyState(VK_DOWN)) {

		if (isPushDown == false) {
			isPushDown = true;

			stageSelect++;

			if (stageSelect > stageMax) {
				stageSelect = stageMax;
			}
		}
	}
	else
	{
		isPushDown = false;
	}


	if (GetAsyncKeyState(VK_UP)) {

		if (isPushUp == false) {
			isPushUp = true;

			stageSelect--;

			if (stageSelect < 0) stageSelect = 0;
		}
	}
	else
	{
		isPushUp = false;
	}

	if (GetAsyncKeyState(VK_RETURN)) {

		if (isPushEnter == false) {

			isPushEnter = true;

			if (stageSelect < stageMax) {
				return Scene::Init;
			}
			else {
				return Scene::End;
			}
		}
	}
	else
	{
		isPushEnter = false;
	}

	for (int i = 0; i < stageMax; i++) {

		DrawFormatString(10, 50 + i * 50, GetColor(255, 255, 255), "Stage%d%s", i, i == stageSelect ? " ←" : "");
	}

	DrawFormatString(10, 50 + stageMax * 50, GetColor(255, 255, 255), "終了%s", stageSelect == stageMax ? " ←" : "");

	return Scene::Start;
}