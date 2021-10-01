

class TitleScene
{
private:
	double x, y;//âÊëúç∂è„
	int TitleBackImg;
	int Col1, Col2;

	int TitleStringWidth;
	int StartStringWidth;
	int EndStringWidth;


	int SelectButton;

	void Draw();
	void ButtonSelect();
	void NextScene();
public:
	void All();
	TitleScene();
};

