#include <windows.h>

//extern宣言でグローバルに
extern char key[256];

//メッセージボックス
#define MSG(m) {\
	MessageBox(NULL,m,"メッセージ",MB_OK);}

/*マップ*/
#define MapWidth 500
#define MapHeight 700

/*プレイヤー*/
#define PLAYER_MOVE_MARGIN 10//プレイヤーの移動制限用　幅

#define PLAYER_WORK_SPEED 6//プレイヤーの移動速度

/*プレイヤーの弾*/
#define P_SHOT_NUM 20 //プレイヤーの弾数
#define SHOT_SPEED 14 //弾速

struct P_SHOT {
	bool ShotFlag;//弾が発射中かどうか
	double Shotx;//弾の座標 x,y
	double Shoty;
	int ShotImg;//画像格納変数
	int width, height;//画像幅、高さ
};
