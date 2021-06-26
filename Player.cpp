#include "pch.h"
#include "Player.h"

PLAYER::PLAYER() {
	/*�摜�ǂݍ���*/
	if (-1 == LoadDivGraph("Img/Player/Player.png", 3, 3, 1, 50, 60, PlayerImg)) {
		MSG("�G���[����");
	}

	Width = 29, Height = 40;

	move = 1.0f;
	
	ImgCount = 0;
	Result = 0;

	X = 180, Y = 400;

	Life = true;
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

/*�`��*/
void PLAYER::Draw() {
	//�����Ă����ԂȂ�
	if (Life) {
		DrawGraph(X - Width / 2, Y - Height / 2, PlayerImg[Result], TRUE);
	}
}
//All�֐�
void PLAYER::All() {
	Move();
	Draw();
}