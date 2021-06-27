
class ENEMY
{
private:
	double x, y;//座標
	int EnemyImg[3];//画像格納配列

	int E_Width, E_Height;//画像幅　高さ

	int In_E, Out_E, Stop_E;//敵の出現、消滅、停止

	int E_count;//画像アニメーション用

	bool Enemy_Dead;//敵死亡フラグ
	bool Enemy_flag;//敵クラスが消滅し終わったかどうか

	/*弾*/
	

public:
	bool All();
	void Move();
	void Draw();
	void Shot();
	ENEMY();
};

