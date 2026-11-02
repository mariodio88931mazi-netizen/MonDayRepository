#include "ImageManager.h"
#include "DxLib.h"

// 画像ハンドル
int SwordGraph;
int BackGround;
int Enemy_BIRD1;

const int EFFECT_MAX = 5;
int effectGraph[EFFECT_MAX];

// 画像読み込み
bool ImageManager::Initialize()
{
    SwordGraph = LoadGraph("img/sord.png");
    BackGround = LoadGraph("img/BackGround.png");
    Enemy_BIRD1 = LoadGraph("img/enemy/bird1.png");

    // エフェクト画像
    for (int i = 0; i < EFFECT_MAX; i++)
    {
        char fileName[100];

        sprintf_s(
            fileName,
            "img/effect/swordeffect%d.png",
            i
        );

        effectGraph[i] = LoadGraph(fileName);

        if (effectGraph[i] == -1)
        {
            return false;
        }
    }

    return true;
}

// 画像解放
void ImageManager::Finalize()
{
    DeleteGraph(SwordGraph);
    DeleteGraph(BackGround);
    DeleteGraph(Enemy_BIRD1);

    for (int i = 0; i < EFFECT_MAX; i++)
    {
        DeleteGraph(effectGraph[i]);
    }
}

int ImageManager::GetSwordGraph()
{
    return SwordGraph;
}

int ImageManager::GetBackGround()
{
    return BackGround;
}

int ImageManager::GetBirdGraph()
{
    return Enemy_BIRD1;
}

int ImageManager::GetEffectGraph(int index)
{
    if (index < 0 || index >= EFFECT_MAX)
    {
        return -1;
    }

    return effectGraph[index];
}

int ImageManager::GetEffectMax()
{
	return EFFECT_MAX;
}