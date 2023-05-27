#include "DxLib.h"
#include "Input/InputControl.h"
#include "Scene/SceneManager.h"
#include "Scene/TitleScene.h"

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

	// 変数定義
	SceneManager scene_manager(new TitleScene);


	// 裏画面から描画を開始する
	SetDrawScreen(DX_SCREEN_BACK);

	// ゲームループ
	while (ProcessMessage() != -1 && CheckHitKey(KEY_INPUT_ESCAPE) != TRUE)
	{
		// 画面の初期化
		ClearDrawScreen();
		
		// 入力制御機能：更新処理
		InputControl::Update();

		// 更新処理の戻り値がnullptrか判定する
		if (scene_manager.Update() != nullptr)
		{
			// 描画処理を行う
			scene_manager.Draw();
		}
		else
		{
			// ループを終了する
			break;
		}

		// 裏画面の内容を表画面に反映
		ScreenFlip();
	}

	// DXライブラリの終了処理
	DxLib_End();

	return 0;
}