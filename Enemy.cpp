#include "pch.h"
#include "Enemy.h"

ENEMY::ENEMY() {
	/*エネミー基本情報*/
	if (-1 == LoadDivGraph("Img/Player/Player.png", 3, 3, 1, 50, 60, EnemyImg)) {
		MSG("エラー発生");
	}
	//座標やフラグ（Enemy.h参照）
	E_Width = 27;
	E_Height = 25;

	x = 50;
	y = -50;

	In_E = 180;
	Stop_E = 300;
	Out_E = 420;
	E_count = 0;

	Enemy_Dead = false;
	Enemy_flag = false;

	
}

void ENEMY::Move() {
	if (In_E<Game_Count && Stop_E>Game_Count) {
		y += 2;
	}
	else if (Game_Count > Out_E) {
		y -= 2;
		if (y < -40) {
			Enemy_Dead = true;
		}
	}
}

void ENEMY::Draw() {

	if (!Enemy_Dead) {
		DrawGraph(x, y, EnemyImg[0], TRUE);
	}
}

bool ENEMY::All() {
	Move();
	Draw();

	E_count++;

	return Enemy_flag;
}

