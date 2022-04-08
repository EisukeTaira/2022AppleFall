#include "DxLib.h"
#include "HelpScene.h"
#include "InputManager.h"

// 変数定義
int HelpImg[2];

// ヘルプ機能初期化処理
void Help_Init(void)
{

}
// ヘルプ機能更新処理
void Help_Update(void)
{
	DrawRotaGraph((640 >> 1), (480 >> 1), 1, 0, HelpImg[0], TRUE);
	DrawRotaGraph(320, 100, 1, 0, HelpImg[1], TRUE);
}
// ヘルプ機能画像読み込み
int LoadHelpImg(void)
{
	int ret = 0;

	HelpImg[0] = LoadGraph("../images/bg_natural_mori.png");
	HelpImg[1] = LoadGraph("../images/help/sousa.png");
	for (int i = 0; i < 2; i++) {
		if (HelpImg[i] == -1) {
			return -1;
		}
	}
	return ret;
}
// ヘルプ機能音源読み込み
int LoadHelpSnd(void)
{
	return 0;
}