#include "pch.h"
#include "Operation.h"

OPERATION::OPERATION() {
	player = new PLAYER;//�v���C���[�N���X����
}
OPERATION::~OPERATION() {
	delete player;//�v���C���[�N���X�̉��
}
void OPERATION::All() {
	player->All();//�v���C���[�N���X��All�֐����s
}