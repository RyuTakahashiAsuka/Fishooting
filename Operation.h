#include"BackGround.h"
#include"Player.h"
#include"Enemy.h"


class OPERATION
{
private:
	BACK* back;
	
	PLAYER* player;//�v���C���[�N���X�̃|�C���^�̍쐬

	ENEMY* enemy[ENEMY_NUM];
public:
	OPERATION();
	~OPERATION();
	void All();

};

