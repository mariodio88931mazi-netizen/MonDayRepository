#include "ImageManager.h"
#include "DxLib.h"

// 画像ハンドル
int SwordGraph;
int BackGround;

const int BIRD_MAX = 1;
int Enemy_BIRD[BIRD_MAX];

const int EFFECT_MAX = 5;
int effectGraph[EFFECT_MAX];

// 画像読み込み
bool ImageManager::Initialize()
{
    SwordGraph = LoadGraph("img/sord.png");
    BackGround = LoadGraph("img/BackGround.png");
    // 鳥画像
    for (int i = 0; i < BIRD_MAX; i++)
    {
        char fileName[100];

        sprintf_s(
            fileName,
            "img/enemy/BIRD%d.png",
            i
        );

        Enemy_BIRD[i] = LoadGraph(fileName);

        if (Enemy_BIRD[i] == -1)
        {
            return false;
        }
    }

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

    for (int i = 0; i < BIRD_MAX; i++)
    {
        DeleteGraph(Enemy_BIRD[i]);
    }

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

int ImageManager::GetBirdGraph(int index)
{
	if (index < 0 || index >= BIRD_MAX)
	{
		return -1;
	}
	return Enemy_BIRD[index];
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