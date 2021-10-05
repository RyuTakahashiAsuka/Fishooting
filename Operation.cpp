#include "pch.h"
#include "Operation.h"

OPERATION::OPERATION() {
	back = new BACK;//�w�i�N���X�쐬
	player = new PLAYER;//�v���C���[�N���X����

	titleScene = new TitleScene;
	GameOver = new GAMEOVER;
	GameClear = new GAMECLEAR;

	FILE* fp;
	ENEMYDATA data[ENEMY_NUM];
	char buf[100];
	int c;
	int col = 1;
	int row = 0;

	EnemyNum = ENEMY_NUM;
	BreakEnemyCount = 0;

	memset(buf, 0, sizeof(buf));
	fp = fopen("Data/EnemyData.csv", "r");
	SceneCount = 0;

	//�w�b�_�ǂݔ�΂�
	while (fgetc(fp) != '\n');

	while (1) {

		while (1) {

			c = fgetc(fp);

			//�����Ȃ烋�[�v�𔲂���B
			if (c == EOF)
				goto out;

			//�J���}�����s�łȂ���΁A�����Ƃ��ĂȂ���
			if (c != ',' && c != '\n')
				strcat(buf, (const char*)&c);
			//�J���}�����s�Ȃ烋�[�v������B
			else
				break;
		}
		//�����ɗ����Ƃ������Ƃ́A1�Z�����̕����񂪏o���オ�����Ƃ�������
		switch (col) {
			//1��ڂ͓G��ނ�\���Batoi�֐��Ő��l�Ƃ��đ���B
		case 1:	data[row].E_Type = atoi(buf); break;
			//2��ڂ͒e��ށB�ȍ~�ȗ��B
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
		//�o�b�t�@��������
		memset(buf, 0, sizeof(buf));
		//�񐔂𑫂�
		++col;

		//�����ǂݍ��񂾕��������s��������񐔂����������čs���𑝂₷
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

void OPERATION::CollisionAll() {
	double px, py, ex, ey;

	bool tempflag = false;

	//����L�����̒e�ƓG�Ƃ̓����蔻��
	for (int i = 0; i < P_SHOT_NUM; ++i) {
		if (player->GetShotPosition(i, &px, &py)) {
			for (int s = 0; s < ENEMY_NUM; ++s) {
				//�G�N���X�̃|�C���^��NULL����Ȃ��A����deadflag��false(����łȂ����A�҂��ĂȂ�)
				if (enemy[s] != NULL && !enemy[s]->GetDeadFlag()) {
					enemy[s]->GetPosition(&ex, &ey);
					//�����蔻��
					if (Collision(PSHOT_COLLISION, ENEMY1_COLLISION, px, ex, py, ey)) {
						//�������Ă���΁Adeadflag�𗧂Ă�
						enemy[s]->SetDeadFlag();
						EnemyNum = EnemyNum - 1;
						BreakEnemyCount = BreakEnemyCount + 1;
						//���������e�̃t���O��߂�
						player->SetShotFlag(i, false);
					}
				}
			}
		}
	}


	//�G�̒e�Ƒ���L�����Ƃ̓����蔻��
	//�v���C���[�������Ă��
	if (!player->GetDamageFlag()) {
		player->GetPosition(&px, &py);
		for (int i = 0; i < ENEMY_NUM; ++i) {
			if (enemy[i] != NULL) {
				for (int s = 0; s < ENEMY_SHOT_NUM; ++s) {
					//�e�t���O�������Ă����true��Ԃ�
					if (enemy[i]->GetShotPosition(s, &ex, &ey)) {
						//�e�ɂ���ē����蔻�肪�Ⴄ�̂�switch���ŕ���
							//�������Ă��
							if (Collision(PLAYER_COLLISION, ESHOT0_COLLISION, px, ex, py, ey)) {
								tempflag = true;
							}
						if (tempflag) {
							//����L������damageflag�𗧂Ă�
							player->SetDamageFlag();
							
							//�e������
							enemy[i]->SetShotFlag(s, false);
							//�ꎞ�t���O��߂�
							tempflag = false;
						}
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
	delete player;//�v���C���[�N���X�̉��
	delete back;

	for (int i = 0; i < ENEMY_NUM; ++i) {
		if (enemy[i] != NULL) {
			delete enemy[i];
		}
	}
}
void OPERATION::All() {


	switch (SceneCount)
	{
	case 0:
		titleScene->All();
		break;
	case 1:
		back->All();
		player->All();//�v���C���[�N���X��All�֐����s

		for (int i = 0; i < ENEMY_NUM; ++i) {
			if (enemy[i] != NULL) {
				if (enemy[i]->All()) {
					delete enemy[i];
					enemy[i] = NULL;
				}
			}
		}
		if (EnemyNum == 0) {
			if (BreakEnemyCount == 0) {
				SceneCount = 2;
			}
			else {
				SceneCount = 3;
			}
		}

		CollisionAll();
		++Game_Count;
		break;
	case 2:
		GameOver->All();
		break;
	case 3:
		GameClear->All();
		break;
	}

}