#include "pch.h"
#include "Enemy.h"

ENEMY::ENEMY(int E_Type, int E_shot_Type, int E_Move_Pattern, int E_shot_Pattern, int InTime_E, int StopTime_E,
	int E_shot_Time, int OutTime_E, int x, int y, int shotSpeed, int E_HP) {
	/*エネミー基本情報*/
	
	//座標やフラグ（Enemy.h参照）
	E_Width = 27;
	E_Height = 25;

	this->E_Type = E_Type;
	this->E_shot_Type = E_shot_Type;

	this->E_Move_Pattern = E_Move_Pattern;
	this->E_shot_Pattern = E_shot_Pattern;

	this->x = x;
	this->y = y;
	
	this->InTime_E = InTime_E;
	this->StopTime_E = StopTime_E;
	this->E_shot_Time = E_shot_Time;
	this->OutTime_E = OutTime_E;

	this->E_HP = E_HP;

	/*画像*/
	if (E_Type == 0) {
		LoadDivGraph("Img/Player/Player.png", 3, 3, 1, 50, 60, EnemyImg);
	}
	int EShotImg;
	if (E_shot_Type == 0) {
		EShotImg = LoadGraph("Img/Enemy/enemyshot1.png");
	}
	int W, H;
	GetGraphSize(EShotImg, &W, &H);
	//弾の初期化
	for (int i = 0; i < ENEMY_SHOT_NUM; ++i) {
		E_shot[i].E_NowShotFlag = false;
		E_shot[i].E_ShotImg = EShotImg;
		E_shot[i].ImgWidth = W;
		E_shot[i].ImgHeight = H;
		E_shot[i].E_ShotPattern = E_shot_Pattern;
		E_shot[i].E_ShotSpeed = shotSpeed;
		E_shot[i].E_ShotX = x;
		E_shot[i].E_ShotY = y;
		
	}
	
	E_count = 0;
	E_shot_count = 0;

	Enemy_DeadFlag = false;
	Enemy_endflag = false;
	E_shotflag = false;
	
}
void ENEMY::Shot() {
	if (E_shot_Time == Game_Count) {
		E_shotflag = true;
	}
	if (E_shotflag) {
		if(!Enemy_DeadFlag){
		switch (E_shot_Pattern)
		{
		case 0:
			if (E_shot_count % 10 == 0 && E_shot_count <= 40) {
				for (int i = 0; i < ENEMY_SHOT_NUM; ++i) {
					if (E_shot[i].E_NowShotFlag == false) {
						E_shot[i].E_NowShotFlag = true;
						E_shot[i].E_ShotX = x;
						E_shot[i].E_ShotY = y;
						break;
					}
				}
			}
			break;
		}
	}
		int s = 0;//フラグが立っている弾の数
		//フラグが立っているだけ移動を行う
		for (int i = 0; i < ENEMY_SHOT_NUM; ++i) {
			if (E_shot[i].E_NowShotFlag) {
				E_shot[i].E_ShotY += E_shot[i].E_ShotSpeed;
				if (E_shot[i].E_ShotX < -20 || E_shot[i].E_ShotX>420 || E_shot[i].E_ShotY < -20 || E_shot[i].E_ShotY>500) {
					E_shot[i].E_NowShotFlag = false;
					continue;
				}
				++s;
			}
		}
		if (s == 0 && Enemy_DeadFlag) {
			Enemy_endflag;
		}
		++E_shot_count;
	}
}

void ENEMY::Move() {
	if (InTime_E<Game_Count && StopTime_E>Game_Count) {
		y += 2;
	}
	else if (Game_Count > OutTime_E) {
		y -= 2;
		if (y < -40) {
			Enemy_DeadFlag = true;
		}
	}
}

void ENEMY::Draw() {

	for (int i = 0; i < ENEMY_SHOT_NUM; ++i) {
		if (E_shot[i].E_NowShotFlag) {
			DrawGraph(E_shot[i].E_ShotX+(E_Width*0.25), E_shot[i].E_ShotY+E_Height , E_shot[i].E_ShotImg, true);
		}
	}

	if (!Enemy_DeadFlag) {
		DrawGraph(x, y, EnemyImg[0], TRUE);
	}
}

void ENEMY::GetPosition(double* x, double* y)
{
	*x = this->x;
	*y = this->y;
}
bool ENEMY::GetShotPosition(int index, double* x, double* y)
{
	if (E_shot[index].E_NowShotFlag) {
		*x = E_shot[index].E_ShotX;
		*y = E_shot[index].E_ShotY;
		return true;
	}
	else {
		return false;
	}
}

void ENEMY::SetDeadFlag()
{
	Enemy_DeadFlag = true;
}

bool ENEMY::GetDeadFlag()
{
	return Enemy_DeadFlag;
}

bool ENEMY::All() {
	Move();
	Draw();
	Shot();

	E_count++;

	return Enemy_endflag;
}

