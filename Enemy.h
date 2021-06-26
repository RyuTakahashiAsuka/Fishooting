
class ENEMY
{
private:
	double x, y;//座標
	int EnemyImg[3];//画像格納配列

	int E_Width, E_Height;//画像幅　高さ

	int In_E, Out_E, Stop_E;//敵の出現、消滅、停止

	int E_count;
	int Enemy_flag;//敵が消滅し終わったかどうか
public:
	bool All();
	void Move();
	void Draw();
	ENEMY();
};

