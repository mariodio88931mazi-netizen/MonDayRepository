//1.なぜCharacterのオブジェクトは作れない？
//  　Attackが純粋仮想関数になっているため。
//2.なぜPlayerのオブジェクトは作れる？
//　　Attackを自分で実装しているので、作れる。
//3.Characterクラスは。なにを決めるためのクラスだと思う？
//　　ChacterクラスはPlayerなど、キャラクターが共通して持つ機能を決めるためのクラス。
#include "Character.h"
#include "Player.h"

int main(void)
{
	Player player;
	Character Character;

	player.Attack();

}