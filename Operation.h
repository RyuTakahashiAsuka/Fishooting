#include"BackGround.h"
#include"Player.h"
#include"Enemy.h"


class OPERATION
{
private:
	BACK* back;
	
	PLAYER* player;//�v���C���[�N���X�̃|�C���^�̍쐬

	ENEMY* enemy[ENEMY_NUM];

	bool Collision(double c1,double c2, double cx1, double cx2, double cy1, double cy2);
		//�~�`�P�̔��a,�~�`�Q�̔��a�A�~�`�P��x���W�A�~�`�Q��x���W�A�~�`�P��y���W�A�~�`�Q��y���W
	void EnemyCollisionAll();
public:
	OPERATION();
	~OPERATION();
	void All();

};

