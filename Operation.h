#include"Player.h"
#include"Enemy.h"

class OPERATION
{
private:
	PLAYER* player;//プレイヤークラスのポインタの作成

	ENEMY* enemy;
public:
	OPERATION();
	~OPERATION();
	void All();

};

