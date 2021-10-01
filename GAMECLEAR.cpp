#include "pch.h"
#include "GAMECLEAR.h"

GAMECLEAR::GAMECLEAR() {
	x = y = 0;
	Col1 = GetColor(255, 255, 255);

	BackGroundImg = LoadGraph("Img/Back/Clear_BackGround.jpg");


	GameClearStringWidth = GetDrawStringWidth("GAMECLEAR", -1);
	EndStringWidth = GetDrawStringWidth("ゲーム終了", -1);

}
void GAMECLEAR::GameEnd() {
	if (key[KEY_INPUT_SPACE] == 1)
	{
		DxLib_End();
	}
}
void GAMECLEAR::Draw() {
	DrawExtendGraph(x, y, MapWidth, y + MapHeight, BackGroundImg, FALSE);

	DrawString((MapWidth - GameClearStringWidth) / 2, 200, "GAMECLEAR", GetColor(0, 0, 0));

	DrawBox(150, 400, 349, 480, GetColor(0, 0, 0), TRUE);
	DrawString((MapWidth - EndStringWidth) / 2, 435, "ゲーム終了", Col1);
	DrawString(195, 500, "press Space", Col1);
}
void GAMECLEAR::All() {
	Draw();
	GameEnd();
}