#include "GameMainScene.h"
#include "ResultScene.h"
#include "DxLib.h"
#include <math.h>

// コンストラクタ
GameMainScene::GameMainScene()
{
	bar = new Bar;
	ball = new Ball(bar->GetLocation());

	for (int i = 0; i < 10; i++)
	{
		block[i] = new Block[16];

		for (int j = 0; j < 10; j++)
		{
			float x = (float)j * block[i][j].GetSizeX() + 10;
			float y = (float)i * (block[i][j].GetSizeY() * 2.0f) + 30.0f;
			block[i][j].SetLocation(x, y);
			block[i][j].SetDispFlg(TRUE);
		}
	}
}

// デストラクタ
GameMainScene::~GameMainScene()
{
	delete bar;
	delete ball;

	for (int i = 0; i < 10; i++)
	{
		delete[] block[i];
	}
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
	if (HitCheck_BB(ball, bar) == TRUE)
	{
		float angle = (0.3f * 60.f) * (ball->GetLocationX() - bar->GetLocationX()) + 0.6f;
		ball->ChangeDirection(angle);
	}

	// ボールとブロックの当たり判定の確認
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (HitCheck_BB(ball, &block[i][j]) == TRUE)
			{
				block[i][j].SetDispFlg(FALSE);
			}
		}
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

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			block[i][j].Draw();
		}
	}
}

// 当たり判定処理
int GameMainScene::HitCheck_BB(const Ball* ball, const BoxCollision* b)
{
	int ret = FALSE;

	if (ball->GetLocationX() <= (b->GetLocationX() + b->GetSizeX()) && (ball->GetLocationX() + ball->GetSizeX()) >= b->GetLocationX() &&
		ball->GetLocationY() <= (b->GetLocationY() + b->GetSizeY()) && (ball->GetLocationY() + ball->GetSizeY()) >= b->GetLocationY())
	{
		ret = TRUE;
	}

	return ret;
}
