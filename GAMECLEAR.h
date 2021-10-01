#pragma once
class GAMECLEAR
{

private:
	double x, y;//âÊëúç∂è„
	int BackGroundImg;
	int Col1;

	int GameClearStringWidth;
	int EndStringWidth;

	void GameEnd();
	void Draw();
public:
	void All();
	GAMECLEAR();
};

