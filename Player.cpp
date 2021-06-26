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
	memset(shot, 0, sizeof(shot));//������
	//�摜�ǂݍ���
	int S_Img = LoadGraph("Img/Player/Player_Shot.png");
	int w, h;//�摜���A����
	GetGraphSize(S_Img, &w, &h);//�摜�T�C�Y�𒲂ׂ��ꂼ��i�[
	
	//�e���̕������S�ăt���O��false�ɂ��ĉ摜��T�C�Y������
	for (int i = 0; i < P_SHOT_NUM; ++i) 
	{
		shot[i].ShotFlag = false;
		shot[i].ShotImg = S_Img;
		shot[i].width = w;
		shot[i].height = h;
	}
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

void PLAYER::Shot() {
	//�X�y�[�X�L�[���������count��6�Ŋ�����0�̎�
	if (key[KEY_INPUT_SPACE] == 1 && S_count % 6 == 0) {
		//�e���̐�����
		for (int i = 0; i < P_SHOT_NUM; i++) {
			//�t���O��false�̎�true�ɂ��Ēe�̈ʒu���v���C���[�̍��W��
			if (shot[i].ShotFlag == false) {
				shot[i].ShotFlag = true;
				shot[i].Shotx = X;
				shot[i].Shoty = Y;
			}
		}
	}
	
	//�e�̈ړ�
	//�e�̐�����
	for (int i = 0; i < P_SHOT_NUM; i++) {
		//���˂��Ă���e�̂�
		if (shot[i].ShotFlag) {
			shot[i].Shoty -= SHOT_SPEED;//�e�̈ړ��i��ʏ�͏�Ɍ������āj
			//��ʊO�ɏo��������@�t���O��߂�
			if (shot[i].Shoty < -10) {
				shot[i].ShotFlag = false;
			}
		}
	}
}
/*�`��*/
void PLAYER::Draw() {
	//�e�̕`��
	for (int i = 0; i < P_SHOT_NUM; i++) {
		if (shot[i].ShotFlag) {
			DrawGraph(shot[i].Shotx -Width/2, shot[i].Shoty -Height/2,
				shot[i].ShotImg, TRUE);
		}
	}
	//�v���C���[�̕`��i�����Ă����ԂȂ�j
	if (Life) {
		DrawGraph(X - Width / 2, Y - Height / 2, PlayerImg[Result], TRUE);
	}

	
}
//All�֐�
void PLAYER::All() {
	Shot();
	Move();
	Draw();
	
	S_count++;
}