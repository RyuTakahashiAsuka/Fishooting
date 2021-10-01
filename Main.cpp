#include"pch.h"
#include"Operation.h"

char key[256];//キー取得用配列
int Game_Count;//ゲームスタートから何ループしたか。
int SceneCount;

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetGraphMode(MapWidth,MapHeight, NULL);
	ChangeWindowMode(TRUE);//ウィンドウモードに変更

	SetWindowSize(MapWidth,MapHeight);//ウィンドウサイズ変更
	
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	OPERATION* operation = new OPERATION;//operationクラスのインスタンス作成
	

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && 
		ClearDrawScreen() == 0 && GetHitKeyStateAll(key) == 0) 
	{
		operation->All();
	}

	DxLib_End();			// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}