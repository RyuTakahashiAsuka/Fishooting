
class ENEMY
{
private:
	double x, y;//���W
	int EnemyImg[3];//�摜�i�[�z��

	int E_Width, E_Height;//�摜���@����

	int In_E, Out_E, Stop_E;//�G�̏o���A���ŁA��~

	int E_count;
	int Enemy_flag;//�G�����ł��I��������ǂ���
public:
	bool All();
	void Move();
	void Draw();
	ENEMY();
};

