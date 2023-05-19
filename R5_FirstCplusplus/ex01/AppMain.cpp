#include "DxLib.h"
#include "Scene/GameMainScene.h"

// メイン関数
int WINAPI WinMain(_In_ HINSTANCE ih, _In_opt_ HINSTANCE ioh, _In_ LPSTR il, _In_ int ii)
{
	// ウィンドウモードで起動
	ChangeWindowMode(TRUE);

	// DXライブラリの初期化
	if (DxLib_Init() == -1)
	{
		return -1;
	}
	
	GameMainScene gms;

	// メインループ
	while (ProcessMessage() != -1)
	{
		// 画面の初期化
		ClearDrawScreen();
		
		gms.Update();
		gms.Draw();

		// 裏画面と表画面の交換
		ScreenFlip();
	}

	// DXライブラリの終了処理
	DxLib_End();

	return 0;
}
