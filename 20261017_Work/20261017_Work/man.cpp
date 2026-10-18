/*なぜ同じ配列にPlayerEnemyを入れられる？
    どちらもCharacterを継承しているから、Characterのポインタで呼べる。

  なぜ同じAttack()の呼び出しで違う攻撃になる？
    Attack関数にvirtualがあるため、使うオブジェクトに応じてそれぞれの処理が呼べる
    。
  PlayerとEnemyが増えた場合、どのようなメリットがある？
    同じ配列とループを使いまわしてたくさんのキャラクターを一気に処理できる。*/

#include <iostream>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;


int main()
{
    Player player;
    Enemy enemy;

    Character* characters[2];

    characters[0] = &player;
    characters[1] = &enemy;

    for (int i = 0; i < 2; i++)
    {
        characters[i]->Attack();
    }

    return 0;
}
