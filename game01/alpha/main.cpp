#include "DxLib.h"
#include "SceneMgr.h"
#include "InputKey.h"
#include "FpsCtrl.h"

// 変数宣言
InputKey keyCtrl;
SceneMgr sceneMgr;
Fps f_ctrl;
bool loop_flg;

// 内部関数
bool loop_check();					// ループチェック

// プログラムは WinMain から始まります
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	
	loop_flg = true;

	ChangeWindowMode(TRUE);			// ウィンドウモードで起動
	// DXライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		return -1;					// エラーが起きたら直ちに終了
	}
	// XInput方式のコントローラーチェック
	if (CheckJoypadXInput(DX_INPUT_PAD1) == -1)
	{
		return -1;
	}
	SetDrawScreen(DX_SCREEN_BACK);	// 裏画面設定
	
	sceneMgr.Initialize();			// 初期化処理

	// ゲームループ
	while (loop_check())			
	{
		ClearDrawScreen();			// 画面の初期化

		keyCtrl.KeyUpdate();		// キー入力更新
		sceneMgr.Update();			// 更新処理
		sceneMgr.Draw();			// 描画処理
		f_ctrl.Update();			// FPSチェック更新
		f_ctrl.Draw();				// FPS描画
		DrawFormatString(0, 450, GetColor(255, 255, 255), "%d", keyCtrl.GetAxis(VERTICAL));
		ScreenFlip();				// 裏画面に変更
		f_ctrl.Wait();				// FPSの速度調整
	}

	sceneMgr.Finalize();			// 最終処理

	DxLib_End();					// ＤＸライブラリ使用の終了処理

	return 0;						// ソフトの終了 
}
// ループチェック
bool loop_check()
{
	bool ret = true;
	
	// ウインドウのメッセージを処理する
	if (ProcessMessage() != 0)
	{
		ret = false;
	}
	// BACKボタンが押された
	if (keyCtrl.GetButton(XINPUT_BUTTON_BACK))
	{
		ret = false;
	}
	// ESCキーが押された
	if (CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ret = false;
	}	
	// 外的要因でループの継続ができない
	if (loop_flg == false)
	{
		ret = false;
	}

	return ret;
}
// 入力情報を取得
InputKey* Get_InputKey()
{
	return &keyCtrl;
}
// 外的要因でループを終了させる
void Set_LoopFlg(bool flg)
{
	loop_flg = flg;
}