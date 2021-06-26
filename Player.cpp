#include "pch.h"
#include "Player.h"

PLAYER::PLAYER() {
	/*画像読み込み*/
	if (-1 == LoadDivGraph("Img/Player/Player.png", 3, 3, 1, 50, 60, PlayerImg)) {
		MSG("エラー発生");
	}

	Width = 29, Height = 40;

	move = 1.0f;
	
	ImgCount = 0;
	Result = 0;

	X = 180, Y = 400;

	Life = true;
}
/*プレイヤーの移動*/
void PLAYER::Move() {
	/*移動 左右上下の順*/
	if (key[KEY_INPUT_LEFT] == 1) {
		X -= move * (int)PLAYER_WORK_SPEED;
	}
	if (key[KEY_INPUT_RIGHT] == 1) {
		X += move * (int)PLAYER_WORK_SPEED;
	}
	if (key[KEY_INPUT_UP] == 1) {
		Y -= move * (int)PLAYER_WORK_SPEED;
	}
	if (key[KEY_INPUT_DOWN] == 1) {
		Y += move * (int)PLAYER_WORK_SPEED;
	}

	/*プレイヤーの角度*/
	if (key[KEY_INPUT_LEFT] == 1 || key[KEY_INPUT_RIGHT] == 1) {
		if (key[KEY_INPUT_UP] == 1 || key[KEY_INPUT_DOWN] == 1){
			move = 0.71f;
		}
		else { move = 1.0f; }
	}
	else { move = 1.0f; }

	if (key[KEY_INPUT_LEFT] == 1) { Result = 1; }
	else if (key[KEY_INPUT_RIGHT] == 1) { Result = 2; }
	else { Result = 0; }


	/*プレイヤーの移動制限*/
	if (X <= 10) {
		X = PLAYER_MOVE_MARGIN;
	}
	else if (X>=490-Width) {
		X = 490-Width;
	}
	if (Y <= 200) {
		Y = 200;
	}
	else if (Y >= 690-Height) {
		Y = 690 - Height;
	}
	
}

/*描画*/
void PLAYER::Draw() {
	//生きている状態なら
	if (Life) {
		DrawGraph(X - Width / 2, Y - Height / 2, PlayerImg[Result], TRUE);
	}
}
//All関数
void PLAYER::All() {
	Move();
	Draw();
}