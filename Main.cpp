#include"pch.h"
#include"Operation.h"

char key[256];//�L�[�擾�p�z��

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetGraphMode(500,700, NULL);
	ChangeWindowMode(TRUE);//�E�B���h�E���[�h�ɕύX

	SetWindowSize(500, 700);//�E�B���h�E�T�C�Y�ύX
	
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