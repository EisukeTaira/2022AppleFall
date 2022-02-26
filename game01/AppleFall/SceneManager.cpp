#include "SceneManager.h"
#include "InputManager.h"
#include "Title.h"

// マクロ定義

// 型定義

// 変数宣言
E_GAME_MODE now_scene;
// 定数宣言

// 内部関数プロトタイプ宣言
void scene_switch(void);


// シーンマネージャー初期化処理
int SceneMng_Init(void) {
	int ret = 0;

	now_scene = E_GAME_MODE::TITLE;	// ゲームモード初期化
	
	InputMng_Init();					// 入力機能初期化処理
	ret = LoadTitleImg();

	return ret;
}
// シーンマネージャー更新処理
void SceneMng_Updata(void) {
	InputMng_Updata();
	scene_switch();
}
// 現在のシーンを取得
E_GAME_MODE Get_SceneMng_Now(void) {
	return now_scene;
}
// 次のシーンに切り替え
void Set_SceneMng_Next(E_GAME_MODE scene) {
	now_scene = scene;
}

// シーンをスイッチする
void scene_switch(void) {

	if (GetInputKey(PAD_INPUT_START)) {
		Set_SceneMng_Next(E_GAME_MODE::EXIT);
	}

	switch (now_scene)
	{
		case E_GAME_MODE::OPENING:
			break;
		case E_GAME_MODE::TITLE:
			TitleUpdata();
			break;
		case E_GAME_MODE::GINIT:
			break;
		case E_GAME_MODE::RANKING:
			break;
		case E_GAME_MODE::HELP:
			break;
		case E_GAME_MODE::GEND:
			break;
		case E_GAME_MODE::GMAIN:
			break;
		case E_GAME_MODE::GOVER:
			break;
		case E_GAME_MODE::INRANK:
			break;
		default:
			break;
	}
}