
#pragma once
#include <vector>

// 敵の種類
enum class StageEnemyType
{
    Bird,
    Skeleton
};

// ボスの種類
enum class BossType
{
    Samurai,
    Daija,
    Daitouryo,
    Dragon
};

// 出現パターン
enum class SpawnPattern
{
    Single,
    Formation
};

// 敵1体の情報
struct StageSpawnData
{
    StageEnemyType type;
    float x;
    float y;
    float speed;
};

// 1回の出現イベント
struct StageWaveData
{
    int startTime;
    SpawnPattern pattern;

    const StageSpawnData* enemies;
    int enemyCount;
};

// 1ステージの情報
struct StageData
{
    const StageWaveData* waves;
    int waveCount;

    int bossSpawnTime;
    BossType boss;
};

class StageManager
{
private:
    int currentStage;
    int stageFrame;
    int nextWaveIndex;

    bool waitingForBossDefeat;
    bool bossSpawnRequested;
    bool allStagesCleared;

    const StageData* currentData;

    std::vector<StageSpawnData> spawnRequests;

    void LoadStage(int stage);

    static const StageSpawnData* Bird_V(int& count);

public:
    void Initialize();
    void Update();

    bool ConsumeBossSpawnRequest();
    void NotifyBossDefeated();

    const std::vector<StageSpawnData>&
        GetSpawnRequests() const;

    BossType GetCurrentBossType() const;

    int GetCurrentStage() const;

    bool IsWaitingForBossDefeat() const;
    bool IsAllStagesCleared() const;
};
