#include <windows.h>

//extern�錾�ŃO���[�o����
extern char key[256];
extern int Game_Count;

//���b�Z�[�W�{�b�N�X
#define MSG(m) {\
	MessageBox(NULL,m,"���b�Z�[�W",MB_OK);}

/*�S��*/
#define MARGIN 10//��

/*�}�b�v*/
#define MapWidth 500
#define MapHeight 700

/*�w�i*/
#define SCROLL_SPEED 2//�w�i�X�N���[���X�s�[�h

/*�v���C���[*/

#define PLAYER_WORK_SPEED 6//�v���C���[�̈ړ����x

/*�v���C���[�̒e*/
#define P_SHOT_NUM 20 //�v���C���[�̒e��
#define SHOT_SPEED 14 //�e��

struct P_SHOT {
	bool P_NowShotFlag;//�e�����˒����ǂ���
	double P_ShotX;//�e�̍��W x,y
	double P_ShotY;
	int P_ShotImg;//�摜�i�[�ϐ�
	int ImgWidth, ImgHeight;//�摜���A����
};

/*�G�l�~�[�̒e*/

#define ENEMY_SHOT_NUM 50//�G�̒e��
struct E_SHOT{
	bool E_NowShotFlag;
	double E_ShotX;
	double E_ShotY;
	int E_ShotImg;
	int ImgWidth, ImgHeight;
	//���܂ł͓G�p�̃v���C���[�̒e�Ɠ��������̕ϐ�
	int E_ShotPattern;//�e�̃p�^�[��
	int E_ShotSpeed;//�e���x
};

#define ENEMY_NUM 5//�G�f�[�^��
struct ENEMYDATA {
	int E_Type;//���
	int E_shot_Type;//�e�̎��
	int E_Move_Pattern;//�ړ��p�^�[��
	int E_shot_Pattern;//�e�̃p�^�[��
	int InTime_E;//�G�̏o��
	int StopTime_E;//��~
	int E_shot_Time;//���˃^�C�~���O
	int OutTime_E;//����
	int x;
	int y;
	int Speed;
	int HP;
};
