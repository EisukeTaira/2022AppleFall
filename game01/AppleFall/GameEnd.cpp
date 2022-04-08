#include "DxLib.h"
#include "GameEnd.h"

// 変数定義
int EndImg;			// エンド画面画像

// エンド機能初期化処理
void GEnd_Init(void)
{

}
// エンド機能更新処理
void GEnd_Update(void)
{
	DrawRotaGraph(320, 240, 0.65, 0, EndImg, TRUE);
	SetFontSize(50);
	DrawFormatString(25, 50, 0x00000000, "Thank you for playing!!!");
}
// エンド機能画像読込処理
int LoadGEndImg(void)
{
	int ret = 0;

	// 画像読み込み
	EndImg = LoadGraph("../images/bg_natural_mori.png");

	if (EndImg == -1)
	{
		ret = -1;
	}
	return ret;
}
// エンド機能音源読込処理
int LoadGEndSnd(void)
{
	return 0;
}