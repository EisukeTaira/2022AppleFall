#include "TitleScene.h"
#include "DxLib.h"
#include "../Input/InputControl.h"
#include "../Scene/GameMainScene.h"
#include "../Scene/EndingScene.h"

// コンストラクタ
TitleScene::TitleScene()
{

}

// デストラクタ
TitleScene::~TitleScene()
{

}

// 更新処理
AbstractScene* TitleScene::Update()
{
	if (InputControl::MouseButtonDown(MOUSE_INPUT_LEFT))
	{
		return dynamic_cast<AbstractScene*>(new GameMainScene);
	}

	return dynamic_cast<AbstractScene*>(this);
}

// 描画処理
void TitleScene::Draw() const
{
#ifdef _DEBUG
	DrawFormatString(10, 10, GetColor(255, 255, 255), "タイトル画面");
#endif // _DEBUG

	SetFontSize(125);
	DrawFormatString(10, 80, GetColor(255, 0, 0), "Break Out");
	SetFontSize(65);
	DrawFormatString(200, 300, GetColor(255, 255, 255), "Start");
	DrawFormatString(200, 365, GetColor(255, 255, 255), "End");
	SetFontSize(20);
}