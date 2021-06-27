#include "pch.h"
#include "Operation.h"

OPERATION::OPERATION() {
	back = new BACK;//背景クラス作成
	player = new PLAYER;//プレイヤークラス生成

	enemy = new ENEMY;//敵クラス生成
}
OPERATION::~OPERATION() {
	delete player;//プレイヤークラスの解放

	if (enemy != NULL) { delete enemy; }
}
void OPERATION::All() {
	back->All();
	player->All();//プレイヤークラスのAll関数実行

	if (enemy != NULL) {
		if (enemy->All()) {
			enemy = NULL;
		}
	}

	++Game_Count;
}