
class PLAYER
{
private:
	/*���l��*/
	bool Life;//�v���C���[�̐�������

	double X, Y;//�v���C���[�̍��W

	float move;//�ړ��W��

	int ImgCount;

	/*�摜*/
	int Result;//�摜�z��̗v�f
	int Width, Height;//�摜��

	int PlayerImg[3];//�摜�̃O���t�B�b�N�n���h���i�[�z��

private:
	void Move();//�ړ�
	void Draw();//�`��
public:
	PLAYER();
	void All();
};

