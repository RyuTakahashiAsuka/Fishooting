#include "pch.h"
#include "GAMEOVER.h"

GAMEOVER::GAMEOVER() {
	x = y = 0;
	Col1 = GetColor(255, 255, 255);

	BackGroundImg = LoadGraph("Data/Img/Back/Over_BackGround.jpg");


	GameOverStringWidth = GetDrawStringWidth("GAMEOVER", -1);
	EndStringWidth = GetDrawStringWidth("ゲーム終了", -1);

}
void GAMEOVER::GameEnd() {
	if (key[KEY_INPUT_SPACE] == 1) 
	{
		DxLib_End();
	}

}
void GAMEOVER::Draw() {
	DrawExtendGraph(x, y, MapWidth, y + MapHeight, BackGroundImg, FALSE);

	DrawString((MapWidth - GameOverStringWidth) / 2, 200, "GAMEOVER", GetColor(0, 0, 0));

	DrawBox(150, 400, 349, 480, GetColor(0,0,0), TRUE);
	DrawString((MapWidth - EndStringWidth) / 2, 435, "ゲーム終了", Col1);
	DrawString(195, 500, "press Space", GetColor(0,0,0));
}


void GAMEOVER::All() {
	Draw();
	GameEnd();
}