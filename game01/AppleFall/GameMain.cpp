#include "GameMain.h"
#include "GMainConfig.h"
#include "InputManager.h"

//　マクロ定義



// 変数定義
int GMainImg[3] = {};							// 画像用変数
int GMainSnd[3] = {};							// 音源用変数
T_PLAYER Player;								// プレイヤー

// プロトタイプ宣言
void stage_background(void);					// 背景描画処理
void stage_ui_ctrl(void);						// UI描画処理
int hitcheck(int px, int py, int ex, int ey);	// 当たり判定

// ゲームメイン機能初期化処理
void GMainInit(void)
{
	Player.x = 0;
	Player.y = 0;
	Player.hitcheck = &hitcheck;
}
// ゲームメイン機能更新処理
void GMainUpdate(void)
{
	stage_background();
	
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
// 背景描画処理
void stage_background(void)
{
	//描画可能エリアを認定
	SetDrawArea(0, 0, 500, 480);
	// 背景画像の描画
	DrawRotaGraph(BG_POS_X, BG_POS_Y, 0.65, 0, GMainImg[BACK_GROUND], TRUE);

	//エリアを戻す
	SetDrawArea(0, 0, 640, 480);
	//	//ステージ背景
	DrawBox(500, 0, 640, 480, 0xFF66FF, TRUE);
}
// UI描画処理
void stage_ui_ctrl(void)
{
}
// 当たり判定チェック
int hitcheck(int px, int py, int ex, int ey)
{
	return FALSE;
}