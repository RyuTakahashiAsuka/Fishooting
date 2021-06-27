#include "pch.h"
#include "BackGround.h"

BACK::BACK() {
	GameBackImg = LoadGraph("Img/Back/Main_BackGround.jpg");

	x = y = 0;
}

void BACK::Move() {
	y += SCROLL_SPEED;
}

void BACK::Draw() {
	DrawExtendGraph(x, y,MapWidth,y+MapHeight,GameBackImg, FALSE);

	DrawExtendGraph(x, y-700,MapWidth,(y-700)+MapHeight,GameBackImg, FALSE);

	if (y == MapHeight+10) {
		y = 0;
	}
}


void BACK::All() {
	Draw();
	Move();
}