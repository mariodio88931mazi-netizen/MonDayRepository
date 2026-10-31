#include "DxLib.h"
#include "Game.h"
#include "Scene.h"

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow)
{
    SetGraphMode(1280, 720, 32);
    SetWindowText("FrySord!");
    ChangeWindowMode(TRUE);

    if (DxLib_Init() == -1)
    {
        return -1;
    }

    SetDrawScreen(DX_SCREEN_BACK);
    SetMouseDispFlag(FALSE);

    // ゲーム初期化
    if (!GameInitialize())
    {
        DxLib_End();
        return -1;
    }

    // true：タイトル画面、false：ゲーム画面
    bool isTitle = true;
    bool oldEnter = false;

    // メインループ
    while (ProcessMessage() == 0 &&
        CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        ClearDrawScreen();

        // Enterキーの押した瞬間を検出
        bool enter = CheckHitKey(KEY_INPUT_RETURN) != 0;
        bool enterPressed = enter && !oldEnter;
        oldEnter = enter;

        if (isTitle)
        {
            StartScene();

            // Enterキーでゲーム開始
            if (enterPressed)
            {
                isTitle = false;
            }
        }
        else
        {
            // ゲーム画面
            GameUpdate();
            GameDraw();
        }

        ScreenFlip();
    }

    // ゲーム終了処理
    GameFinalize();

    DxLib_End();

    return 0;
}