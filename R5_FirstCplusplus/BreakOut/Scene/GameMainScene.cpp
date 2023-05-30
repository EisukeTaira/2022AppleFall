#include "GameMainScene.h"
#include "ResultScene.h"
#include "DxLib.h"

// コンストラクタ
GameMainScene::GameMainScene()
{
	bar = new Bar;
	ball = new Ball(bar->GetLocation());
}

// デストラクタ
GameMainScene::~GameMainScene()
{
	delete bar;
	delete ball;
}

// 更新処理
AbstractScene* GameMainScene::Update()
{
	bar->Update();

	if (ball->GetState() == Ball::E_STAY)
	{
		ball->SetLocation(bar->GetLocation());
	}
	ball->Update();

	if (ball->GetRemaining_Lives() < 0)
	{
		return dynamic_cast<AbstractScene*>(new ResultScene);
	}

	return dynamic_cast<AbstractScene*>(this);
}

// 描画処理
void GameMainScene::Draw() const
{
#ifdef _DEBUG
	DrawFormatString(10, 10, GetColor(255, 255, 255), "ゲームメイン画面");
#endif // _DEBUG
	bar->Draw();
	ball->Draw();
}