#include <windows.h>

//extern�錾�ŃO���[�o����
extern char key[256];

//���b�Z�[�W�{�b�N�X
#define MSG(m) {\
	MessageBox(NULL,m,"���b�Z�[�W",MB_OK);}

/*�v���C���[*/
#define PLAYER_MOVE_MARGIN 10;//�v���C���[�̈ړ������p�@��

#define PLAYER_WORK_SPEED 6;//�v���C���[�̈ړ����x
