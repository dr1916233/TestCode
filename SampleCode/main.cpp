#include <iostream>
#include <DxLib.h>
#include "main.h"

using namespace std;

struct Sample
{
	char c;

	short w;
};


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(true);
	DxLib_Init();

	SetWindowText(L"1916233_èoâ∆ó«ëæ");
	SetDrawScreen(DX_SCREEN_BACK);

	while (ProcessMessage() == 0 && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ClsDrawScreen();



		ScreenFlip();
	}

	DxLib_End();
}