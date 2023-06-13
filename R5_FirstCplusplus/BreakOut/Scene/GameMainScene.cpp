#include "GameMainScene.h"
#include "ResultScene.h"
#include "DxLib.h"
#include <math.h>

#define BLOCK_WIDTH		(10)
#define BLOCK_HEIGHT	(10)
#define BLOCK_MAX		(BLOCK_WIDTH * BLOCK_HEIGHT)

// コンストラクタ
GameMainScene::GameMainScene()
{
	bar = new Bar;
	ball = new Ball;
	block_count = BLOCK_MAX;
	block = new Block[BLOCK_MAX];

	for (int i = 0; i < BLOCK_MAX; i++)
	{
		float x = ((i % BLOCK_WIDTH) * block[i].GetSizeX()) + 20.0f;
		float y = ((i / BLOCK_WIDTH) * block[i].GetSizeY() * 1.5f) + 20.0f;
		block[i].SetDispFlg(TRUE);
		block[i].SetLocation(x, y);
	}
}

// デストラクタ
GameMainScene::~GameMainScene()
{
	delete bar;
	delete ball;
	delete[] block;
}

// 更新処理
void GameMainScene::Update()
{
	// バー更新処理
	bar->Update();
	// ボール更新処理
	ball->Update();

	
	if (ball->GetState() == Ball::E_STAY)				// ボールがステイ状態ならボールにバーの位置情報を教える
	{
		ball->SetLocation(bar->GetLocation());
	}
	else if (ball->GetState() == Ball::E_MOVE)			// ボールが動作状態ならバーとブロックの当たり判定処理を行う
	{
		// バーとボールの当たり判定を確認
		if (HitCheck_BB(ball, bar) == TRUE)
		{
			// 当たっているなら、反射させる
			float angle = (18.0f) * (ball->GetLocationX() - bar->GetLocationX()) + 0.6f;
			ball->ChangeDirection(angle);
		}

		// ボールとブロックの当たり判定の確認
		for (int i = 0; i < BLOCK_MAX; i++)
		{
			if (block[i].GetDispFlg() != TRUE)
			{
				continue;
			}
			if (HitCheck_BB(ball, &block[i]) == TRUE)
			{
				// 当たっているなら、反射させる
				ball->ChangeDirection();
				block[i].SetDispFlg(FALSE);
				block_count--;
			}
		}
	}
	else
	{
		;
	}
}

// 描画処理
void GameMainScene::Draw() const
{
	// バーの描画処理
	bar->Draw();
	// ボールの描画処理
	ball->Draw();
	// ブロックの描画処理
	for (int i = 0; i < BLOCK_MAX; i++)
	{
		block[i].Draw();
	}
}

AbstractScene* GameMainScene::Change()
{
	// 残機がなくなったら、リザルトに遷移する
	if (ball->GetRemaining_Lives() < 0)
	{
		return nullptr;
	}
	if (block_count <= 0)
	{
		return dynamic_cast<AbstractScene*>(new ResultScene);
	}

	return dynamic_cast<AbstractScene*>(this);
}

// 当たり判定処理
int GameMainScene::HitCheck_BB(const Ball* ball, const BoxCollision* target)
{
	int ret = FALSE;

	if (ball->GetLocationX() <= (target->GetLocationX() + target->GetSizeX()) && (ball->GetLocationX() + ball->GetSizeX()) >= target->GetLocationX() &&
		ball->GetLocationY() <= (target->GetLocationY() + target->GetSizeY()) && (ball->GetLocationY() + ball->GetSizeY()) >= target->GetLocationY())
	{
		ret = TRUE;
	}

	return ret;
}
