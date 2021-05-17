#include <iostream>
#include <DxLib.h>
#include "main.h"

using namespace std;

struct Sample
{
	char c;

	short w;
};

struct Vector2{
	float x, y;
};

using Position2 = Vector2;

struct Rect{
	Position2 center;		// ��`�̒��S
	float w, h;				// ���S����̂��ꂼ��̕����ǂꂭ�炢����Ă��邩�܂�

	float Left()const {
		return center.x - w;
	}

	float Right()const {
		return center.x + w;
	}

	float Top()const {
		return center.y - w;
	}

	float Buttom()const {
		return center.y + w;
	}
};


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(true);
	DxLib_Init();

	SetWindowText(L"1916233_�o�ƗǑ�");
	SetDrawScreen(DX_SCREEN_BACK);

	Rect rc = { 200,200,50,100 };

	while (ProcessMessage() == 0 && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ClsDrawScreen();

		DrawBox(rc.Left(), rc.Top(), rc.Right(), rc.Left(), 0xffffff, true);

		ScreenFlip();
	}

	DxLib_End();
}