
class PLAYER
{
private:
	/*���l��*/
	//�v���C���[�̃��C�t
	int life;
	bool damageflag;
	bool endflag;

	double X, Y;//�v���C���[�̍��W

	float move;//�ړ��W��

	int ImgCount;//�摜�A�j���[�V�����p

	//�_���[�W���̃J�E���g
	int dcount;
	/*�摜*/
	int Result;//�摜�z��̗v�f
	int Width, Height;//�摜��

	int PlayerImg[3];//�摜�̃O���t�B�b�N�n���h���i�[�z��

	/*�e*/
	P_SHOT P_shot[P_SHOT_NUM];
	int Shot_count;//�e�𔭎˂���Ԋu�p�ϐ�

	 
private:
	void Shot();//�e
	void Move();//�ړ�
	void Draw();//�`��
public:
	PLAYER();
	void GetPosition(double* x, double* y);
	bool GetShotPosition(int index, double* x, double* y);
	void SetShotFlag(int index, bool flag);
	void SetDamageFlag();
	bool GetDamageFlag();
	void All();
};

