#include <windows.h>

//extern宣言でグローバルに
extern char key[256];

//メッセージボックス
#define MSG(m) {\
	MessageBox(NULL,m,"メッセージ",MB_OK);}

//プレイヤーの歩くスピード
#define PLAYER_WORK_SPEED 4;