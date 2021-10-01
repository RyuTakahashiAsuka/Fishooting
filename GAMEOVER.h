#pragma once
class GAMEOVER
{
private:
	double x, y;//âÊëúç∂è„
	int BackGroundImg;
	int Col1;

	int GameOverStringWidth;
	int EndStringWidth;

	void GameEnd();
	void Draw();
public:
	void All();
	GAMEOVER();
};

