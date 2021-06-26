#include <windows.h>

//extern宣言でグローバルに
extern char key[256];

//メッセージボックス
#define MSG(m) {\
	MessageBox(NULL,m,"メッセージ",MB_OK);}

/*プレイヤー*/
#define PLAYER_MOVE_MARGIN 10;//プレイヤーの移動制限用　幅

#define PLAYER_WORK_SPEED 6;//プレイヤーの移動速度
