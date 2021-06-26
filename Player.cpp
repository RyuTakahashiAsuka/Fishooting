#include "pch.h"
#include "Player.h"

PLAYER::PLAYER() {
	/*プレイヤー基礎*/
	//画像読み込み
	if (-1 == LoadDivGraph("Img/Player/Player.png", 3, 3, 1, 50, 60, PlayerImg)) {
		MSG("エラー発生");
	}
	Width = 29, Height = 40;//画像幅

	X = 180, Y = 400;//座標
	move = 1.0f;//移動係数
	ImgCount = 0;//画像アニメーション用変数
	Result = 0;//現在のアニメーション番号格納変数

	Life = true;//生きているかどうか

	/*弾*/
	memset(shot, 0, sizeof(shot));//初期化
	//画像読み込み
	int S_Img = LoadGraph("Img/Player/Player_Shot.png");
	int w, h;//画像幅、高さ
	GetGraphSize(S_Img, &w, &h);//画像サイズを調べそれぞれ格納
	
	//弾数の分だけ全てフラグをfalseにして画像やサイズを入れる
	for (int i = 0; i < P_SHOT_NUM; ++i) 
	{
		shot[i].ShotFlag = false;
		shot[i].ShotImg = S_Img;
		shot[i].width = w;
		shot[i].height = h;
	}
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

void PLAYER::Shot() {
	//スペースキーが押されてcountを6で割って0の時
	if (key[KEY_INPUT_SPACE] == 1 && S_count % 6 == 0) {
		//弾数の数だけ
		for (int i = 0; i < P_SHOT_NUM; i++) {
			//フラグがfalseの時trueにして弾の位置をプレイヤーの座標に
			if (shot[i].ShotFlag == false) {
				shot[i].ShotFlag = true;
				shot[i].Shotx = X;
				shot[i].Shoty = Y;
			}
		}
	}
	
	//弾の移動
	//弾の数だけ
	for (int i = 0; i < P_SHOT_NUM; i++) {
		//発射している弾のみ
		if (shot[i].ShotFlag) {
			shot[i].Shoty -= SHOT_SPEED;//弾の移動（画面上は上に向かって）
			//画面外に出たら消去　フラグを戻す
			if (shot[i].Shoty < -10) {
				shot[i].ShotFlag = false;
			}
		}
	}
}
/*描画*/
void PLAYER::Draw() {
	//弾の描画
	for (int i = 0; i < P_SHOT_NUM; i++) {
		if (shot[i].ShotFlag) {
			DrawGraph(shot[i].Shotx -Width/2, shot[i].Shoty -Height/2,
				shot[i].ShotImg, TRUE);
		}
	}
	//プレイヤーの描画（生きている状態なら）
	if (Life) {
		DrawGraph(X - Width / 2, Y - Height / 2, PlayerImg[Result], TRUE);
	}

	
}
//All関数
void PLAYER::All() {
	Shot();
	Move();
	Draw();
	
	S_count++;
}