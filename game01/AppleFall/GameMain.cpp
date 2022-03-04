#include "GameMain.h"
#include "GMainConfig.h"
#include "InputManager.h"

//　マクロ定義



// 変数定義
int GMainImg[3] = {};	// 画像用変数
int GMainSnd[3] = {};	// 画像用変数

// ゲームメイン機能初期化処理
void GMainInit(void)
{
	
}
// ゲームメイン機能更新処理
void GMainUpdate(void)
{
	DrawRotaGraph(BG_POS_X, BG_POS_Y, 0.65, 0, GMainImg[BACK_GROUND], TRUE);
}
// ゲームメイン機能画像読み込み処理
int  LoadGMainImg(void)
{
	int i;

	GMainImg[BACK_GROUND] = LoadGraph("../images/bg_natural_mori.png");

	for (i = 0; i < 3; i++) {
		if (GMainImg[i] == -1) {
			return -1;
		}
	}
	return 0;
}
// ゲームメイン機能音源読み込み処理
int  LoadGMainSnd(void)
{
	return 0;
}