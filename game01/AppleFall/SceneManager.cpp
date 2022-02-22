#include "SceneManager.h"
#include "InputManager.h"

// マクロ定義

// 型定義

// 変数宣言
E_GAME_MODE now_scene;
// 定数宣言

// 内部関数プロトタイプ宣言

// シーンマネージャー初期化処理
int SceneMng_Init(void) {
	int ret = 0;

	now_scene = E_GAME_MODE::OPENING;	// ゲームモード初期化
	
	InputMng_Init();					// 入力機能初期化処理


	return ret;
}
// シーンマネージャー更新処理
void SceneMng_Updata(void) {
	InputMng_Updata();
}
E_GAME_MODE Get_SceneMng_Now(void) {
	return now_scene;
}
void Set_SceneMng_Next(E_GAME_MODE scene) {
	now_scene = scene;
}