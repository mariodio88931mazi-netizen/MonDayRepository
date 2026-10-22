//1.なぜPlayerとEnemyにはAttack()を書く必要がある？
// 基底クラスで純粋仮想関数をつかっているから。

//2.片方のクラスにAttack()を書かなかったらどうなる？
// 純粋仮想関数を実装しないことになり、オブジェクトを直接作れなくなる。

//3.なぜoverrideを使っている？
// 親クラスの仮想関数を正しく上書きしているか、確認aするため。


#include "Player.h"
#include <iostream>

void Player::Attack()
{
	std::cout << "剣で攻撃" << endl;
}
