
class ENEMY
{
private:
	double x, y;//���W
	int EnemyImg[3];//�摜�i�[�z��

	int E_Width, E_Height;//�摜���@����

	int In_E, Out_E, Stop_E;//�G�̏o���A���ŁA��~

	int E_count;//�摜�A�j���[�V�����p

	bool Enemy_Dead;//�G���S�t���O
	bool Enemy_flag;//�G�N���X�����ł��I��������ǂ���

	/*�e*/
	

public:
	bool All();
	void Move();
	void Draw();
	void Shot();
	ENEMY();
};

