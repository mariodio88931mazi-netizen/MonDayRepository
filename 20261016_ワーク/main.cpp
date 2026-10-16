#include "Character.h"
#include "Player.h"
#include "Enemy.h"
/*考えること
　　1.プレイヤーは（剣で攻撃）Enemy(噛みつき攻撃）
    2.おんなじ関数名でも、ポリモーフィズムを使って違う処理を呼び出せるため。
    3.名前が同じだと、キャラクターごとに同じ関数名で呼び出し、別々の処理が出せるが、関数名を別々にすると呼び出すときも別々で呼び出さないといけない。*/

int main()
{
    Character character;
    Player player;
    Enemy enemy;

    character.Attack();
    player.Attack();
    enemy.Attack();

    return 0;
}
