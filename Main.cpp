#include"pch.h"
#include"Operation.h"

char key[256];//�L�[�擾�p�z��
int Game_Count;//�Q�[���X�^�[�g���牽���[�v�������B
int SceneCount;

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetGraphMode(MapWidth,MapHeight, NULL);
	ChangeWindowMode(TRUE);//�E�B���h�E���[�h�ɕύX

	SetWindowSize(MapWidth,MapHeight);//�E�B���h�E�T�C�Y�ύX
	
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	OPERATION* operation = new OPERATION;//operation�N���X�̃C���X�^���X�쐬
	

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && 
		ClearDrawScreen() == 0 && GetHitKeyStateAll(key) == 0) 
	{
		operation->All();
	}

	DxLib_End();			// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}