
class ENEMY
{
private:
	double x, y;//���W
	int EnemyImg;//�摜�i�[�z��
	

	int InTime_E, OutTime_E, StopTime_E;//�G�̏o���A���ŁA��~�̃^�C�~���O�p

	int E_count;//�摜�A�j���[�V�����p

	int E_Type;//�G�̎��
	int E_Move_Pattern;//�ړ��p�^�[��

	int E_HP;


	bool Enemy_DeadFlag;//�G���S�t���O
	bool Enemy_endflag;//�G�N���X�폜�p�t���O

	bool breakEnemyPlus;

	/*�e*/
	E_SHOT E_shot[ENEMY_SHOT_NUM];
	int E_shot_Time;//���˃^�C�~���O
	int E_shot_Type;//�e�̎��
	int E_shot_Pattern;//�e�̃p�^�[��

	bool E_shotflag;//���ˉ\�t���O
	int E_shot_count;//���ˉ\��J�E���g

public:
	int E_Width, E_Height;//�摜���@����


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

