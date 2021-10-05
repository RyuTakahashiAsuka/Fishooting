#include "pch.h"
#include "TitleScene.h"


TitleScene::TitleScene() {
	x = y = 0;
	SelectButton = 0;

	Col1 = GetColor(0, 0, 0);
	Col2 = GetColor(0, 0, 0);


	TitleBackImg = LoadGraph("Data/Img/Back/Main_BackGround.jpg");

	TitleStringWidth = GetDrawStringWidth("FISHOOTING", -1);
	StartStringWidth = GetDrawStringWidth("ゲームスタート", -1);
	EndStringWidth = GetDrawStringWidth("ゲーム終了", -1);
}

void TitleScene::ButtonSelect() {
	if (key[KEY_INPUT_UP] == 1) {
		SelectButton = 0;
	}
	else if(key[KEY_INPUT_DOWN]==1){
		SelectButton = 1;
	}
}

void TitleScene::NextScene() {
	if (key[KEY_INPUT_SPACE] == 1) {
		switch (SelectButton)
		{
		case 0:
			ClearDrawScreen();
			if (SceneCount == 0) {
				SceneCount = SceneCount + 1;
			}
			break;
		case 1:
			DxLib_End();
			break;
		}
		
	}
}

void TitleScene::Draw() {
	DrawExtendGraph(x, y, MapWidth, y + MapHeight, TitleBackImg, FALSE);

	DrawBox(175, 400, 324, 480,Col1, TRUE);
	DrawString((MapWidth - StartStringWidth) / 2, 435, "ゲームスタート", Col2);
	DrawBox(175, 580, 324, 660,Col2, TRUE);
	DrawString((MapWidth - EndStringWidth) / 2, 615, "ゲーム終了", Col1);

	DrawString((MapWidth - TitleStringWidth) / 2, 200, "FISHOOTING", GetColor(0, 0, 0));
	if(SelectButton == 0)
	{
		Col1 = GetColor(255, 0, 0);
		Col2 = GetColor(0, 0, 0);
	}else if(SelectButton == 1){
		Col1 = GetColor(0, 0, 0);
		Col2 = GetColor(255, 0, 0);
	}
}
void TitleScene::All() {
	Draw();
	ButtonSelect();
	NextScene();
}
