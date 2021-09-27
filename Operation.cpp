#include "pch.h"
#include "Operation.h"


OPERATION::OPERATION() {
	back = new BACK;//背景クラス作成
	player = new PLAYER;//プレイヤークラス生成

	FILE* fp;
	ENEMYDATA data[ENEMY_NUM];
	char buf[100];
	int c;
	int col = 1;
	int row = 0;

	memset(buf, 0, sizeof(buf));
	fp = fopen("EnemyData.csv", "r");

	//ヘッダ読み飛ばし
	while (fgetc(fp) != '\n');

	while (1) {

		while (1) {

			c = fgetc(fp);

			//末尾ならループを抜ける。
			if (c == EOF)
				goto out;

			//カンマか改行でなければ、文字としてつなげる
			if (c != ',' && c != '\n')
				strcat(buf, (const char*)&c);
			//カンマか改行ならループ抜ける。
			else
				break;
		}
		//ここに来たということは、1セル分の文字列が出来上がったということ
		switch (col) {
			//1列目は敵種類を表す。atoi関数で数値として代入。
		case 1:	data[row].E_Type = atoi(buf); break;
			//2列目は弾種類。以降省略。
		case 2: data[row].E_shot_Type = atoi(buf); break;
		case 3: data[row].E_Move_Pattern = atoi(buf); break;
		case 4: data[row].E_shot_Pattern = atoi(buf); break;
		case 5: data[row].InTime_E = atoi(buf); break;
		case 6: data[row].StopTime_E = atoi(buf); break;
		case 7: data[row].E_shot_Time = atoi(buf); break;
		case 8: data[row].OutTime_E = atoi(buf); break;
		case 9: data[row].x = atoi(buf); break;
		case 10: data[row].y = atoi(buf); break;
		case 11: data[row].Speed = atoi(buf); break;
		case 12: data[row].HP = atoi(buf); break;
		}
		//バッファを初期化
		memset(buf, 0, sizeof(buf));
		//列数を足す
		++col;

		//もし読み込んだ文字が改行だったら列数を初期化して行数を増やす
		if (c == '\n') {
			col = 1;
			++row;
		}
	}
out:

	for (int i = 0; i < ENEMY_NUM; ++i) {
		enemy[i] = new ENEMY(data[i].E_Type, data[i].E_shot_Type, data[i].E_Move_Pattern, data[i].E_shot_Pattern, data[i].InTime_E, 
			data[i].StopTime_E, data[i].E_shot_Time,data[i].OutTime_E, data[i].x, data[i].y, data[i].Speed, data[i].HP);
	}
}

void OPERATION::EnemyCollisionAll() {
	double px, py, ex, ey;
	//操作キャラの弾と敵との当たり判定
	for (int i = 0; i < P_SHOT_NUM; ++i) {
		if (player->GetShotPosition(i, &px, &py)) {
			for (int s = 0; s < ENEMY_NUM; ++s) {
				//敵クラスのポインタがNULLじゃない、かつdeadflagがfalse(死んでない＆帰還してない)
				if (enemy[s] != NULL && !enemy[s]->GetDeadFlag()) {
					enemy[s]->GetPosition(&ex, &ey);
					//当たり判定
					if (Collision(PSHOT_COLLISION, ENEMY1_COLLISION, px, ex, py, ey)) {
						//当たっていれば、deadflagを立てる
						enemy[s]->SetDeadFlag();
						//当たった弾のフラグを戻す
						player->SetShotFlag(i, false);
					}
				}
			}
		}
	}
}


bool OPERATION::Collision(double c1, double c2, double cx1, double cx2, double cy1, double cy2) {

	double hlength = c1 + c2;
	double xlength = cx1 - cx2;
	double ylength = cy1 - cy2;

	if (hlength * hlength >= xlength * xlength + ylength * ylength) {
		return true;
	}
	else {
		return false;
	}
}


OPERATION::~OPERATION() {
	delete player;//プレイヤークラスの解放
	delete back;

	for (int i = 0; i < ENEMY_NUM; ++i) {
		if (enemy[i] != NULL) {
			delete enemy[i];
		}
	}
}
void OPERATION::All() {
	back->All();
	player->All();//プレイヤークラスのAll関数実行

	for (int i = 0; i < ENEMY_NUM; ++i) {
		if (enemy[i] != NULL) {
			if (enemy[i]->All()) {
				delete enemy[i];
				enemy[i] = NULL;
			}
		}
	}

	EnemyCollisionAll();

	++Game_Count;
}