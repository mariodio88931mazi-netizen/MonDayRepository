#include "Dxlib.h"
#include "Game.h"

// ステージ選択用変数の実体
bool isPushUp = false;
bool isPushDown = false;
bool isPushEnter = false;

const int stageMax = 3;
int stageSelect = 0;

void StartScene()
{        
    // タイトル画面
    DrawExtendGraph(
        static_cast<int>(0.0),
        0,
        static_cast<int>(1300),
        720,
        BackGround,
        FALSE);

    DrawFormatString(
        525, 250,
        GetColor(255, 0, 0),
        "FrySord!"
    );

    DrawFormatString(
        490, 350,
        GetColor(255, 255, 0),
        "Press ENTER to Start"
    );
}