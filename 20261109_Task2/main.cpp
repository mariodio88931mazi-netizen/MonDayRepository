
#include <iostream>
#include <memory>
#include "Enemy.h"

// Enemy表示
void ShowEnemy(const Enemy& enemy)
{
    std::cout << "ShowEnemy内のHP : "
        << enemy.GetHp() << std::endl;
}

int main()
{
    // Enemy生成
    std::unique_ptr<Enemy> enemy =
        std::make_unique<Enemy>();

    // HP表示
    std::cout << "最初のHP : "
        << enemy->GetHp() << std::endl;

    // EnemyをShowEnemyに渡す
    ShowEnemy(*enemy);

    // HP確認
    std::cout << "関数呼び出し後のHP : "
        << enemy->GetHp() << std::endl;

    // Draw呼び出し
    enemy->Draw();

    return 0;
}
