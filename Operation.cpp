#include "pch.h"
#include "Operation.h"

OPERATION::OPERATION() {
	player = new PLAYER;//プレイヤークラス生成
}
OPERATION::~OPERATION() {
	delete player;//プレイヤークラスの解放
}
void OPERATION::All() {
	player->All();//プレイヤークラスのAll関数実行
}