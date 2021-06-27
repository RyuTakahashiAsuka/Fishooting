#include "pch.h"
#include "Operation.h"

OPERATION::OPERATION() {
	back = new BACK;//�w�i�N���X�쐬
	player = new PLAYER;//�v���C���[�N���X����

	enemy = new ENEMY;//�G�N���X����
}
OPERATION::~OPERATION() {
	delete player;//�v���C���[�N���X�̉��

	if (enemy != NULL) { delete enemy; }
}
void OPERATION::All() {
	back->All();
	player->All();//�v���C���[�N���X��All�֐����s

	if (enemy != NULL) {
		if (enemy->All()) {
			enemy = NULL;
		}
	}

	++Game_Count;
}