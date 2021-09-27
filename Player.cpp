#include "pch.h"
#include "Player.h"

PLAYER::PLAYER() {
	/*�v���C���[��b*/
	//�摜�ǂݍ���
	if (-1 == LoadDivGraph("Img/Player/Player.png", 3, 3, 1, 50, 60, PlayerImg)) {
		MSG("�G���[����");
	}
	Width = 29, Height = 40;//�摜��

	X = 180, Y = 400;//���W
	move = 1.0f;//�ړ��W��
	ImgCount = 0;//�摜�A�j���[�V�����p�ϐ�
	Result = 0;//���݂̃A�j���[�V�����ԍ��i�[�ϐ�

	Life = true;//�����Ă��邩�ǂ���

	/*�e*/
	memset(P_shot, 0, sizeof(P_shot));//������

	int ShotImg = LoadGraph("Img/Player/Player_Shot.png");
	int width, height;
	GetGraphSize(ShotImg, &width, &height);//�摜�T�C�Y�𒲂׊i�[

	//for���őS�Ă̒e�̃t���O��false�ɁA�摜��T�C�Y����
	for (int i = 0; i < P_SHOT_NUM; ++i) 
	{
		P_shot[i].P_NowShotFlag = false;
		P_shot[i].P_ShotImg = ShotImg;
		P_shot[i].ImgWidth = width;
		P_shot[i].ImgHeight = height;
	}

	Shot_count = 0;
}
/*�v���C���[�̈ړ�*/
void PLAYER::Move() {
	/*�ړ� ���E�㉺�̏�*/
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

	/*�v���C���[�̊p�x*/
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


	/*�v���C���[�̈ړ�����*/
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

/*�e*/
void PLAYER::Shot() {
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

	for (int i = 0; i < P_SHOT_NUM; ++i) {
		if (P_shot[i].P_NowShotFlag == true) {
			P_shot[i].P_ShotY -= SHOT_SPEED;

			if (P_shot[i].P_ShotY < -10) {
				P_shot[i].P_NowShotFlag = false;
			}
		}
	}
}

/*�`��*/
void PLAYER::Draw() {
	//�e�̕`��
	for (int i = 0; i < P_SHOT_NUM; ++i) {
		if (P_shot[i].P_NowShotFlag == true) {
			DrawGraph(P_shot[i].P_ShotX - Width/2, P_shot[i].P_ShotY - Height/2, P_shot[i].P_ShotImg, TRUE);
		}
	}

	//�v���C���[�̕`��i�����Ă����ԂȂ�j
	if (Life) {
		DrawGraph(X - Width / 2, Y - Height / 2, PlayerImg[Result], TRUE);
	}

	
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

//All�֐�
void PLAYER::All() {
	Move();
	Shot();
	Draw();
	
	++Shot_count;
}