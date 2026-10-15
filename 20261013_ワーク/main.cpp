#include "Character.h"
#include "Player.h"
#include "Enemy.h"

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
