#include <windows.h>

//extern�錾�ŃO���[�o����
extern char key[256];

//���b�Z�[�W�{�b�N�X
#define MSG(m) {\
	MessageBox(NULL,m,"���b�Z�[�W",MB_OK);}

/*�}�b�v*/
#define MapWidth 500
#define MapHeight 700

/*�v���C���[*/
#define PLAYER_MOVE_MARGIN 10//�v���C���[�̈ړ������p�@��

#define PLAYER_WORK_SPEED 6//�v���C���[�̈ړ����x

/*�v���C���[�̒e*/
#define P_SHOT_NUM 20 //�v���C���[�̒e��
#define SHOT_SPEED 14 //�e��

struct P_SHOT {
	bool ShotFlag;//�e�����˒����ǂ���
	double Shotx;//�e�̍��W x,y
	double Shoty;
	int ShotImg;//�摜�i�[�ϐ�
	int width, height;//�摜���A����
};
