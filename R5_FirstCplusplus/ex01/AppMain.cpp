#include "DxLib.h"
#include "Scene/GameMainScene.h"
#include "Input/InputControl.h"
#include "Common/FrameRateControl.h"

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
	FrameRateControl frc;

	// メインループ
	while (ProcessMessage() != -1)
	{
		// 画面の初期化
		ClearDrawScreen();

		InputControl::Update();

		frc.Update();
		gms.Update();
	
		gms.Draw();

		if (CheckHitKey(KEY_INPUT_ESCAPE) || InputControl::ButtonDown(XINPUT_BUTTON_BACK))
		{
			break;
		}
#if _DEBUG
		frc.Draw();
#endif // _DEBUG	
		frc.Wait();
		// 裏画面と表画面の交換
		ScreenFlip();
	}

	// DXライブラリの終了処理
	DxLib_End();

	return 0;
}
