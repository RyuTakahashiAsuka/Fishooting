#include"BackGround.h"
#include"Player.h"
#include"Enemy.h"
#include"TitleScene.h"
#include"GAMEOVER.h"
#include"GAMECLEAR.h"

class OPERATION
{
private:
	BACK* back;
	
	PLAYER* player;//�v���C���[�N���X�̃|�C���^�̍쐬

	ENEMY* enemy[ENEMY_NUM];

	TitleScene* titleScene;
	GAMEOVER* GameOver;
	GAMECLEAR* GameClear;

	bool Collision(double c1,double c2, double cx1, double cx2, double cy1, double cy2);
		//�~�`�P�̔��a,�~�`�Q�̔��a�A�~�`�P��x���W�A�~�`�Q��x���W�A�~�`�P��y���W�A�~�`�Q��y���W
	void CollisionAll();


public:
	OPERATION();
	~OPERATION();
	void All();

};

