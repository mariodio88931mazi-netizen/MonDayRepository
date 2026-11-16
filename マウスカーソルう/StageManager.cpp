
#include "StageManager.h"

namespace
{
    const int MAX_STAGE = 3;

    // --------------------------------
    // 単体出現用データ
    // --------------------------------
    const StageSpawnData SINGLE_BIRD[] =
    {
        { StageEnemyType::Bird, -100, 350, 2.0f }
    };

    // --------------------------------
    // 横編隊用データ
    // --------------------------------
    const StageSpawnData BIRD_H[] =
    {
        { StageEnemyType::Bird, -100, 200, 2.0f },
        { StageEnemyType::Bird, -100, 250, 2.0f },
        { StageEnemyType::Bird, -100, 300, 2.0f },
        { StageEnemyType::Bird, -100, 350, 2.0f },
        { StageEnemyType::Bird, -100, 400, 2.0f },
        { StageEnemyType::Bird, -100, 450, 2.0f },
        { StageEnemyType::Bird, -100, 500, 2.0f },
        { StageEnemyType::Bird, -100, 550, 2.0f }
    };

    // --------------------------------
    // ステージ2の出現データ
    // --------------------------------
    const StageSpawnData STAGE2_SINGLE[] =
    {
        { StageEnemyType::Bird, -100, 150, 2.5f },
        { StageEnemyType::Bird, -100, 350, 2.5f },
        { StageEnemyType::Skeleton, -100, 250, 1.5f },
        { StageEnemyType::Skeleton, -100, 500, 1.5f }
    };

    const StageWaveData STAGE2_WAVES[] =
    {
        { 0,   SpawnPattern::Single, &STAGE2_SINGLE[0], 1 },
        { 120, SpawnPattern::Single, &STAGE2_SINGLE[1], 1 },
        { 240, SpawnPattern::Single, &STAGE2_SINGLE[2], 1 },
        { 360, SpawnPattern::Single, &STAGE2_SINGLE[3], 1 }
    };

    // --------------------------------
    // ステージ3の出現データ
    // --------------------------------
    const StageSpawnData STAGE3_SINGLE[] =
    {
        { StageEnemyType::Bird, -100, 200, 3.0f },
        { StageEnemyType::Bird, -100, 400, 3.0f },
        { StageEnemyType::Skeleton, -100, 300, 2.0f },
        { StageEnemyType::Skeleton, -100, 500, 2.0f }
    };

    const StageWaveData STAGE3_WAVES[] =
    {
        { 0,   SpawnPattern::Single, &STAGE3_SINGLE[0], 1 },
        { 90,  SpawnPattern::Single, &STAGE3_SINGLE[1], 1 },
        { 180, SpawnPattern::Single, &STAGE3_SINGLE[2], 1 },
        { 300, SpawnPattern::Single, &STAGE3_SINGLE[3], 1 }
    };

    // --------------------------------
    // ステージ2・3の登録
    // --------------------------------
    const StageData STAGES[MAX_STAGE - 1] =
    {
        {
            STAGE2_WAVES,
            sizeof(STAGE2_WAVES) / sizeof(STAGE2_WAVES[0]),
            720,
            BossType::Daitouryo
        },
        {
            STAGE3_WAVES,
            sizeof(STAGE3_WAVES) / sizeof(STAGE3_WAVES[0]),
            600,
            BossType::Dragon
        }
    };
}

// --------------------------------
// 鳥の縦編隊
// --------------------------------
const StageSpawnData* StageManager::Bird_V(int& count)
{
    static const StageSpawnData enemies[] =
    {
        { StageEnemyType::Bird, -100, 200, 2.0f },
        { StageEnemyType::Bird, -100, 550, 2.0f },
        { StageEnemyType::Bird, -100, 500, 2.0f },
        { StageEnemyType::Bird, -100, 250, 2.0f },
        { StageEnemyType::Bird, -100, 300, 2.0f },
        { StageEnemyType::Bird, -100, 450, 2.0f },
        { StageEnemyType::Bird, -100, 350, 2.0f },
        { StageEnemyType::Bird, -100, 400, 2.0f }
    };

    count = sizeof(enemies) / sizeof(enemies[0]);

    return enemies;
}

// --------------------------------
// 初期化
// --------------------------------
void StageManager::Initialize()
{
    currentStage = 1;
    stageFrame = 0;
    nextWaveIndex = 0;

    waitingForBossDefeat = false;
    bossSpawnRequested = false;
    allStagesCleared = false;

    spawnRequests.clear();

    LoadStage(currentStage);
}

// --------------------------------
// ステージ読み込み
// --------------------------------
void StageManager::LoadStage(int stage)
{
    stageFrame = 0;
    nextWaveIndex = 0;

    waitingForBossDefeat = false;
    bossSpawnRequested = false;

    spawnRequests.clear();

    if (stage < 1 || stage > MAX_STAGE)
    {
        currentData = nullptr;
        allStagesCleared = true;
        return;
    }

    if (stage == 1)
    {
        static StageWaveData stage1Waves[4];
        static StageData stage1Data;

        int birdCount = 0;
        const StageSpawnData* birdEnemies = Bird_V(birdCount);

        stage1Waves[0] =
        {
            0,
            SpawnPattern::Single,
            SINGLE_BIRD,
            1
        };

        stage1Waves[1] =
        {
            180,
            SpawnPattern::Formation,
            birdEnemies,
            birdCount
        };

        stage1Waves[2] =
        {
            480,
            SpawnPattern::Single,
            SINGLE_BIRD,
            1
        };

        stage1Waves[3] =
        {
            720,
            SpawnPattern::Formation,
            birdEnemies,
            birdCount
        };

        stage1Data =
        {
            stage1Waves,
            4,
            900,
            BossType::Samurai
        };

        currentData = &stage1Data;
    }
    else
    {
        currentData = &STAGES[stage - 2];
    }
}

// --------------------------------
// 更新
// --------------------------------
void StageManager::Update()
{
    spawnRequests.clear();

    if (allStagesCleared || waitingForBossDefeat)
    {
        return;
    }

    if (currentData == nullptr)
    {
        return;
    }

    // 時間になった編隊・単体を出現させる
    while (nextWaveIndex < currentData->waveCount)
    {
        const StageWaveData& wave =
            currentData->waves[nextWaveIndex];

        if (wave.startTime > stageFrame)
        {
            break;
        }

        for (int i = 0; i < wave.enemyCount; i++)
        {
            spawnRequests.push_back(wave.enemies[i]);
        }

        nextWaveIndex++;
    }

    // ボス出現時間
    if (stageFrame >= currentData->bossSpawnTime)
    {
        bossSpawnRequested = true;
        waitingForBossDefeat = true;
    }

    stageFrame++;
}

// --------------------------------
// ボス出現要求
// --------------------------------
bool StageManager::ConsumeBossSpawnRequest()
{
    if (!bossSpawnRequested)
    {
        return false;
    }

    bossSpawnRequested = false;
    return true;
}

// --------------------------------
// ボス撃破通知
// --------------------------------
void StageManager::NotifyBossDefeated()
{
    if (!waitingForBossDefeat)
    {
        return;
    }

    if (currentStage >= MAX_STAGE)
    {
        waitingForBossDefeat = false;
        allStagesCleared = true;
        return;
    }

    currentStage++;
    LoadStage(currentStage);
}

// --------------------------------
// 出現要求取得
// --------------------------------
const std::vector<StageSpawnData>&
StageManager::GetSpawnRequests() const
{
    return spawnRequests;
}

// --------------------------------
// ボスの種類
// --------------------------------
BossType StageManager::GetCurrentBossType() const
{
    return currentData->boss;
}

// --------------------------------
// ステージ番号
// --------------------------------
int StageManager::GetCurrentStage() const
{
    return currentStage;
}

// --------------------------------
// ボス撃破待ち
// --------------------------------
bool StageManager::IsWaitingForBossDefeat() const
{
    return waitingForBossDefeat;
}

// --------------------------------
// 全ステージクリア
// --------------------------------
bool StageManager::IsAllStagesCleared() const
{
    return allStagesCleared;
}
