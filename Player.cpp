#include "pch.h"
#include "Player.h"

PLAYER::PLAYER() {
	/*プレイヤー基礎*/
	//画像読み込み
	if (-1 == LoadDivGraph("Data/Img/Player/Player.png", 3, 3, 1, 50, 60, PlayerImg)) {
		MSG("エラー発生");
	}
	Width = 29, Height = 40;//画像幅

	X = PLAYER_INITX, Y = PLAYER_INITY;//座標
	move = 1.0f;//移動係数
	ImgCount = 0;//画像アニメーション用変数
	Result = 0;//現在のアニメーション番号格納変数

	//プレイヤーのライフ
	life = PLAYER_LIFE;
	dcount = 0;
	/*弾*/
	memset(P_shot, 0, sizeof(P_shot));//初期化

	int ShotImg = LoadGraph("Data/Img/Player/Player_Shot.png");
	int width, height;
	GetGraphSize(ShotImg, &width, &height);//画像サイズを調べ格納

	//for分で全ての弾のフラグをfalseに、画像やサイズを代入
	for (int i = 0; i < P_SHOT_NUM; ++i) 
	{
		P_shot[i].P_NowShotFlag = false;
		P_shot[i].P_ShotImg = ShotImg;
		P_shot[i].ImgWidth = width;
		P_shot[i].ImgHeight = height;
	}

	Shot_count = 0;
	damageflag = false;
	endflag = false;
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
		X = MARGIN;
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

/*弾*/
void PLAYER::Shot() {
	if (!damageflag) {
		if (key[KEY_INPUT_Z] == 1 && Shot_count % 6 == 0) {
			for (int i = 0; i < P_SHOT_NUM; ++i) {
				if (P_shot[i].P_NowShotFlag == false) {
					P_shot[i].P_NowShotFlag = true;
					P_shot[i].P_ShotX = X;
					P_shot[i].P_ShotY = Y;
					break;
				}
			}
		}
	}

	for (int i = 0; i < P_SHOT_NUM; ++i) {
		if (P_shot[i].P_NowShotFlag == true) {
			P_shot[i].P_ShotY -= SHOT_SPEED;

			if (P_shot[i].P_ShotY < -10) {
				P_shot[i].P_NowShotFlag = false;
			}
		}
	}
}

/*描画*/
void PLAYER::Draw() {
	//弾の描画
	for (int i = 0; i < P_SHOT_NUM; ++i) {
		if (P_shot[i].P_NowShotFlag == true) {
			DrawGraph(P_shot[i].P_ShotX - Width/2, P_shot[i].P_ShotY - Height/2, P_shot[i].P_ShotImg, TRUE);
		}
	}

	//プレイヤーの描画（生きている状態なら）
	if (damageflag==true) {
		if (dcount > 20) {
			if (dcount % 2 == 0) {
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 140);
				DrawGraph(PLAYER_INITX - Width / 2, PLAYER_INITY - Height / 2 + 60 - (dcount - 20), PlayerImg[0], TRUE);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			}
			else {
				DrawGraph(PLAYER_INITX - Width / 2, PLAYER_INITY - Height / 2 + 60 - (dcount - 20), PlayerImg[0], TRUE);
			}
		}
		++dcount;
		if (dcount == 80) {
			damageflag = false;
			dcount = 0;
			//座標を初期値に戻す
			X = PLAYER_INITX;
			Y = PLAYER_INITY;
			//上向きの画像にする
			Result = 0;
		}
	}
	else {
		DrawGraph(X - Width / 2, Y - Height / 2, PlayerImg[Result], TRUE);
	}

	
}

void PLAYER::GetPosition(double* x, double* y)
{
	*x = this->X;
	*y = this->Y;

}

bool PLAYER::GetShotPosition(int index, double* x, double* y)
{
	if (P_shot[index].P_NowShotFlag) {
		*x = P_shot[index].P_ShotX;
		*y = P_shot[index].P_ShotY;
		return true;
	}
	else {
		return false;
	}

}
void PLAYER::SetShotFlag(int index, bool flag)
{
	P_shot[index].P_NowShotFlag = flag;
}
void PLAYER::SetDamageFlag()
{
	damageflag = true;
	//ライフを減らす
	--life;
	if (life == 0) {
		ClearDrawScreen();
		SceneCount = 2;
	}
}
bool PLAYER::GetDamageFlag()
{
	return damageflag;
}

//All関数
void PLAYER::All() {
	if (!damageflag) {
		Move();
	}
	Shot();
	Draw();
	++Shot_count;
}