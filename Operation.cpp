#include "pch.h"
#include "Operation.h"

OPERATION::OPERATION() {
	player = new PLAYER;//�v���C���[�N���X����

	enemy = new ENEMY;//�G�N���X����
}
OPERATION::~OPERATION() {
	delete player;//�v���C���[�N���X�̉��
}
void OPERATION::All() {
	player->All();//�v���C���[�N���X��All�֐����s

	if (enemy != NULL) {
		if (enemy->All()) {
			enemy = NULL;
		}
	}

	Game_Count++;
}