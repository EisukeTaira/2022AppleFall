#include "GameMainScene.h"
#include "ResultScene.h"
#include "DxLib.h"
#include <math.h>

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

	// バーとボールの当たり判定を確認
	if (HitCheck_BB(bar, ball) == TRUE)
	{
		float angle = (0.3f * 60.f) * (ball->GetLocationX() - bar->GetLocationX()) + 0.6f;
		angle = angle * DX_PI_F * 2.0f;
		ball->ChangeDirection(angle);
	}

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

// 当たり判定処理
int GameMainScene::HitCheck_BB(const BoxCollision* a, const BoxCollision* b)
{
	int ret = FALSE;



	return ret;
}
