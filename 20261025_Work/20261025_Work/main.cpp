//1.BossにAttackを使わなかった場合どうなる？
// Attackが仮想関数なので、BossがAttackを実装しないとBossも抽象クラスになる。
  
//2.抽象クラスを使うことで、どんなルールを守らせられる？
// 継承したクラスに、中小クラスにあった仮想関数等を必ず実装しなければならない。

//3.新しいキャラクターを追加するとき、既存の攻撃処理を大きく変更せずに済むのはなぜ？
// Character型のポインタからAttackを呼び出せるため。 
 
#include <iostream>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Boss.h"

using namespace std;

int main()
{
    Player player;
    Enemy enemy;
    Boss boss;

    Character* character;

    character = &player;
    character->Attack();

    character = &enemy;
    character->Attack();

    character = &boss;
    character->Attack();

    return 0;
}