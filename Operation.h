#include"BackGround.h"
#include"Player.h"
#include"Enemy.h"


class OPERATION
{
private:
	BACK* back;
	
	PLAYER* player;//プレイヤークラスのポインタの作成

	ENEMY* enemy[ENEMY_NUM];

	bool Collision(double c1,double c2, double cx1, double cx2, double cy1, double cy2);
		//円形１の半径,円形２の半径、円形１のx座標、円形２のx座標、円形１のy座標、円形２のy座標
	void EnemyCollisionAll();
public:
	OPERATION();
	~OPERATION();
	void All();

};

