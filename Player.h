
class PLAYER
{
private:
	/*���l��*/
	bool Life;//�v���C���[�̐�������

	double X, Y;//�v���C���[�̍��W

	float move;//�ړ��W��

	int ImgCount;//�摜�A�j���[�V�����p

	/*�摜*/
	int Result;//�摜�z��̗v�f
	int Width, Height;//�摜��

	int PlayerImg[3];//�摜�̃O���t�B�b�N�n���h���i�[�z��

	/*�e*/
	P_SHOT shot[P_SHOT_NUM];
	int S_count;//�e�𔭎˂��銴�o�p�ϐ�
private:
	void Shot();//�e
	void Move();//�ړ�
	void Draw();//�`��
public:
	PLAYER();
	void All();
};

