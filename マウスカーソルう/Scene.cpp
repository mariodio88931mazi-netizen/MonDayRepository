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
        static_cast<int>(1920),
        1080,
        BackGround,
        FALSE);

    DrawGraph(
        600,
        250,
        TitleGraph,
        TRUE
    );

    DrawFormatString(
        600, 520,
        GetColor(255,0, 0),
        "Press ENTER to Start"
    );
}

void GameOver()
{
    // ゲーム画面
    DrawExtendGraph(
        static_cast<int>(0.0),
        0,
        static_cast<int>(1300),
        1080,
        BackGround,
        FALSE);

    DrawFormatString(
        525, 250,
        GetColor(255, 0, 0),
        "GAME OVER"
    );
}
