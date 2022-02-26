#include "Title.h"
#include "SceneManager.h"
#include "InputManager.h"

//　マクロ定義
#define	RINGO_EXTRATE	0.125		// リンゴ画像拡大率

// 型定義

// 変数定義
int TitleImg[3];	// 画像用変数
int TitleSnd[3];	// 音源用変数

// 定数定義

// 内部関数プロトタイプ宣言



// タイトル機能初期化処理
void TitleInit(void) {
	int i;

	for (i = 0; i < 3; i++) {
		TitleImg[i] = 0;
		TitleSnd[i] = 0;
	}
}
// タイトル機能更新処理
void TitleUpdata(void) {
	
	int i;

	for (i = 0; i < 3; i++) {
		DrawRotaGraph(100 * (i + 1), 200, RINGO_EXTRATE, 0,TitleImg[i], TRUE);
	}

	if (GetInputKeyDown(PAD_INPUT_A)) {
		Set_SceneMng_Next(E_GAME_MODE::GINIT);
	}
}
// タイトル機能画像読み込み
int LoadTitleImg(void) {
	
	int i = 0;
	
	TitleImg[0] = LoadGraph("../images/fruit_ringo.png");
	TitleImg[1] = LoadGraph("../images/fruit_apple_yellow.png");
	TitleImg[2] = LoadGraph("../images/fruit_apple_shiwashiwa.png");

	for (i = 0; i < 3; i++) {
		if (TitleImg[i] == -1) {
			return -1;
		}
	}

	return 0;
}
// タイトル機能音源読み込み
int LoadTitleSnd(void) {
	return 0;
}