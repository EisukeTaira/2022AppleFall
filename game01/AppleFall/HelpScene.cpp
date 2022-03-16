#include "DxLib.h"
#include "HelpScene.h"
#include "InputManager.h"

// 変数定義
int HelpImg;

// ヘルプ機能初期化処理
void Help_Init(void)
{

}
// ヘルプ機能更新処理
void Help_Update(void)
{
	DrawRotaGraph((640 >> 1), (480 >> 1), 1, 1, HelpImg, TRUE);
}
// ヘルプ機能画像読み込み
int LoadHelpImg(void)
{
	int ret = 0;

	HelpImg = LoadGraph("../images/fruit_ringo.png");
	if (HelpImg == -1) {
		ret = -1;
	}
	return ret;
}
// ヘルプ機能音源読み込み
int LoadHelpSnd(void)
{
	return 0;
}