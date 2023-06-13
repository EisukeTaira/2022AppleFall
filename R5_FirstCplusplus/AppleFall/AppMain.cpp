#include "DxLib.h"
#include "Scene/SceneManager.h"
#include "Scene/TitleScene.h"
#include "Scene/GameMainScene.h"
#include "Scene/RankingScene.h"
#include "Input/InputControl.h"

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
	
	SceneManager scemeMng(dynamic_cast<AbstractScene*>(new TitleScene()));
	
	// メインループ
	while (ProcessMessage() != -1)
	{
		

		// 入力機能：更新処理
		InputControl::Update();		
		
		// シーンマネージャー：更新処理
		if (scemeMng.Update() != nullptr)
		{
			// 画面の初期化
			ClearDrawScreen();
			// シーンマネージャー：描画処理
			scemeMng.Draw();
			// 裏画面と表画面の交換
			ScreenFlip();
		}
		else
		{
			break;
		}
		// ESCキー or BACKボタンが入力されたとき、終了
		if (CheckHitKey(KEY_INPUT_ESCAPE) || InputControl::ButtonDown(XINPUT_BUTTON_BACK))
		{
			break;
		}		
	}

	// DXライブラリの終了処理
	DxLib_End();

	return 0;
}
