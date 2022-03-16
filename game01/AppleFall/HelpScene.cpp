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

}
// ヘルプ機能画像読み込み
int Help_LoadImg(void)
{
	HelpImg = LoadGraph("../images/ringo.png");
	return 0;
}
// ヘルプ機能音源読み込み
int Help_LoadSmg(void)
{
	return 0;
}