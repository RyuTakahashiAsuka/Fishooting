#include <windows.h>

//extern宣言でグローバルに
extern char key[256];
extern int Game_Count;

//メッセージボックス
#define MSG(m) {\
	MessageBox(NULL,m,"メッセージ",MB_OK);}

/*全体*/
#define MARGIN 10//幅

/*マップ*/
#define MapWidth 500
#define MapHeight 700

/*背景*/
#define SCROLL_SPEED 2//背景スクロールスピード

/*プレイヤー*/

#define PLAYER_WORK_SPEED 6//プレイヤーの移動速度

/*プレイヤーの弾*/
#define P_SHOT_NUM 20 //プレイヤーの弾数
#define SHOT_SPEED 14 //弾速

struct P_SHOT {
	bool P_NowShotFlag;//弾が発射中かどうか
	double P_ShotX;//弾の座標 x,y
	double P_ShotY;
	int P_ShotImg;//画像格納変数
	int ImgWidth, ImgHeight;//画像幅、高さ
};

/*エネミーの弾*/

#define ENEMY_SHOT_NUM 50//敵の弾数
struct E_SHOT{
	
};