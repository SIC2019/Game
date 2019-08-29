#include <Windows.h>

#include "DxLib.h"
#include "winmain.h" 

bool LoopSet() {
	return
	ScreenFlip() == 0
	&& ProcessMessage() == 0
	&& ClearDrawScreen() == 0;
}

enum {
	Set1,
	Set2,
	Set3,
	Set4,
	Set5,
	Set6,
	Set7,
	Set8,
	Set9,
};

void set1() {
	DrawString(250, 240 - 32, "Hello A World!",GetColor(0,255,255));
}
void set2() {
	DrawString(250, 240 - 32, "Hello B World!", GetColor(255, 0, 255));
}
void set3() {
	DrawString(250, 240 - 32, "Hello C World!", GetColor(255, 255, 0));
}
void set4() {
	DrawString(250, 240 - 32, "Hello D World!", GetColor(255, 255, 0));
}
void set5() {
	DrawString(250, 240 - 32, "Hello E World!", GetColor(255,0,255));
}
void set6() {
	DrawString(250, 240 - 32, "Hello F World!", GetColor(255, 255,0));
}
void set7() {
	DrawString(250, 240 - 32, "Hello G World!", GetColor(0, 255, 255));
}
void set8() {
	DrawString(250, 240 - 32, "Hello H World!", GetColor(255,0, 255));
}
void set9() {
	DxLib_End();				// ＤＸライブラリ使用の終了処理
}

void GameMode(int A) {
	GM += A;
	if (GM <= 0) {
		GM = 7;
	}
	if (GM >= 7) {
		GM = 0;
	}

	switch (GM) {
	case Set1:
		set1();
		break;
	case Set2:
		set2();
		break;
	case Set3:
		set3();
		break;
	case Set4:
		set4();
		break;
	case Set5:
		set5();
		break;
	case Set6:
		set6();
		break;
	case Set7:
		set7();
		break;
	case Set8:
		set8();
		break;
	}
}


// WinMain 
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);//ウィンドウモード設定
	SetMainWindowText("2019SIC"); //ウィンドウ名設定
	if (DxLib_Init() == -1)	{	// ＤＸライブラリ初期化処理
		return -1;			// エラーが起きたら直ちに終了
	}

	GameMode(Mode);  //初期設定(A)

	while (LoopSet){   //メインループ
		// 画面の初期化
		//ClearDrawScreen();

		if (CheckHitKey(KEY_INPUT_RSHIFT)) {
			ClearDrawScreen();
			Mode = 1;
			GameMode(Mode);
			
		}
		if (CheckHitKey(KEY_INPUT_LSHIFT)) {
			ClearDrawScreen();
			Mode = -1;
			GameMode(Mode);
		}

		if (CheckHitKey(KEY_INPUT_RETURN)) 	break; //エンターで終了

		/*if (CheckHitKey(KEY_INPUT_A)) {
			ClearDrawScreen();
			set1();
		}
		if (CheckHitKey(KEY_INPUT_B)) {
			ClearDrawScreen();
			set2();
		}
		if (CheckHitKey(KEY_INPUT_C)) {
			ClearDrawScreen();
			set3();
		}*/	
		}

		DxLib_End();				// ＤＸライブラリ使用の終了処理
		return 0;				// ソフトの終了 
}
