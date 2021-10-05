
class ENEMY
{
private:
	double x, y;//座標
	int EnemyImg;//画像格納配列
	

	int InTime_E, OutTime_E, StopTime_E;//敵の出現、消滅、停止のタイミング用

	int E_count;//画像アニメーション用

	int E_Type;//敵の種類
	int E_Move_Pattern;//移動パターン

	int E_HP;


	bool Enemy_DeadFlag;//敵死亡フラグ
	bool Enemy_endflag;//敵クラス削除用フラグ

	bool breakEnemyPlus;

	/*弾*/
	E_SHOT E_shot[ENEMY_SHOT_NUM];
	int E_shot_Time;//発射タイミング
	int E_shot_Type;//弾の種類
	int E_shot_Pattern;//弾のパターン

	bool E_shotflag;//発射可能フラグ
	int E_shot_count;//発射可能後カウント

public:
	int E_Width, E_Height;//画像幅　高さ


	bool All();
	void Move();
	void Draw();
	void Shot();

	void GetPosition(double* x, double* y);
	bool GetShotPosition(int index, double* x, double* y);
	void SetShotFlag(int index, bool flag);
	void SetDeadFlag();
	bool GetDeadFlag();
	ENEMY(int E_Type, int E_shot_Type, int E_Move_Pattern, int E_shot_Pattern, int InTime_E, int StopTime_E,
		int E_shot_Time, int OutTime_E,int x,int y,int shotSpeed,int E_HP);
};

