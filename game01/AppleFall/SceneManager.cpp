#include "SceneManager.h"
#include "InputManager.h"
#include "Title.h"
#include "GameMain.h"
#include "HelpScene.h"
#include "GameEnd.h"


// マクロ定義

// 型定義

// 変数宣言
E_GAME_MODE now_scene;
// 定数宣言

// 内部関数プロトタイプ宣言
void scene_updata_switch(void);


// 初期化処理
int SceneMng_Init(void) {
	int ret = 0;

	now_scene = E_GAME_MODE::TITLE;	// ゲームモード初期化
	
	InputMng_Init();					// 入力機能初期化処理
	ret += LoadTitleImg();				// タイトル機能画像読込処理
	ret += LoadGMainImg();				// ゲームメイン機能画像読込処理
	ret += LoadHelpImg();				// ヘルプ機能画像読込処理
	ret += LoadGEndImg();				// エンド機能画像読込処理

	return ret;
}
// シーンマネージャー更新処理
void SceneMng_Updata(void) {
	InputMng_Updata();
	scene_updata_switch();
}
// 現在のシーンを取得
E_GAME_MODE Get_SceneMng_Now(void) {
	return now_scene;
}
// 次のシーンに切り替え
void Set_SceneMng_Next(E_GAME_MODE scene) {
	now_scene = scene;
	switch (now_scene)
	{
		case E_GAME_MODE::OPENING:
			break;
		case E_GAME_MODE::TITLE:
			TitleInit();
			break;
		case E_GAME_MODE::RANKING:
			break;
		case E_GAME_MODE::HELP:
			Help_Init();
			break;
		case E_GAME_MODE::GEND:
			GEnd_Init();
			break;
		case E_GAME_MODE::GMAIN:
			GMainInit();
			break;
		case E_GAME_MODE::GOVER:
			break;
		case E_GAME_MODE::INRANK:
			break;
		default:			
			break;
	}
}

// シーンをスイッチする
void scene_updata_switch(void) {

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
		case E_GAME_MODE::RANKING:
			break;
		case E_GAME_MODE::HELP:
			Help_Update();
			break;
		case E_GAME_MODE::GEND:
			GEnd_Update();
			break;
		case E_GAME_MODE::GMAIN:
			GMainUpdate();
			break;
		case E_GAME_MODE::GOVER:
			break;
		case E_GAME_MODE::INRANK:
			break;
		default:
			Set_SceneMng_Next(E_GAME_MODE::EXIT);
			break;
	}
}