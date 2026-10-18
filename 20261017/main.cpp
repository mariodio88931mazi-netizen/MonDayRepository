/*1回目と二回目はそれぞれなんと表示される？
    ・１回目：通常攻撃
    ・２回目：かみつき攻撃
    
  characterは何を指している？
    ・最初Playerオブジェクトを指した後にcharacter = &enemy;でEnemyオブジェクトを指す
    
  なぜPlayer型やEnemy型のポインタを使わなくても呼び出せる？
    ・PlayerとEnemyはどちらもCharacterクラスを継承して、Charactrerのポインタを使って呼び出せるから。
    
  なぜ実際のオブジェクトに応じた関数が呼ばれる？
    ・Attackにvirtualが付いていると、オブジェクトに応じてPlayerとEnemyのそれぞれのAttack関数が呼び出されるから。*/




#include <iostream>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;

int main()
{
    Player player;
    Enemy enemy;

    Character* character = &player;

    character->Attack();

    character = &enemy;
    character->Attack();

    return 0;
}
