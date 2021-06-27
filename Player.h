
class PLAYER
{
private:
	/*数値類*/
	bool Life;//プレイヤーの生死判定

	double X, Y;//プレイヤーの座標

	float move;//移動係数

	int ImgCount;//画像アニメーション用

	/*画像*/
	int Result;//画像配列の要素
	int Width, Height;//画像幅

	int PlayerImg[3];//画像のグラフィックハンドル格納配列

	/*弾*/
	P_SHOT P_shot[P_SHOT_NUM];
	int Shot_count;//弾を発射する間隔用変数

	 
private:
	void Shot();//弾
	void Move();//移動
	void Draw();//描画
public:
	PLAYER();
	void All();
};

