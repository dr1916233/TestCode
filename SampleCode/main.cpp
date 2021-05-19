#include <iostream>
#include <DxLib.h>
#include "main.h"

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
		return center.y - h;
	}

	float Buttom()const {
		return center.y + h;
	}
};


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(true);
	DxLib_Init();

	SetWindowText(L"1916233_�o�ƗǑ�");
	SetDrawScreen(DX_SCREEN_BACK);

	Rect rc = { {200,200},50,100 };

	while (ProcessMessage() == 0 && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ClsDrawScreen();

		constexpr float speed = 4.0f;

		// �ړ�
		if (CheckHitKey(KEY_INPUT_LEFT))
		{
			rc.center.x -= speed;
		}
		if (CheckHitKey(KEY_INPUT_RIGHT))
		{
			rc.center.x += speed;
		}
		if (CheckHitKey(KEY_INPUT_UP))
		{
			rc.center.y -= speed;
		}
		if (CheckHitKey(KEY_INPUT_DOWN))
		{
			rc.center.y += speed;
		}

		DrawBox(rc.Left(), rc.Top(), rc.Right(), rc.Buttom(), 0xffffff, true);

		ScreenFlip();
	}

	DxLib_End();
}