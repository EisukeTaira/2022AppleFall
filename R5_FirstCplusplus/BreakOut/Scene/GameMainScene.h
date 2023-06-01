#pragma once

#include "AbstractScene.h"
#include "../Actor/Bar.h"
#include "../Actor/Ball.h"
#include "../Actor/Block.h"

class GameMainScene : public AbstractScene
{
private:
	Bar* bar;
	Ball* ball;
	Block* block[10];

public:
	GameMainScene();											// コンストラクタ
	~GameMainScene();											// デストラクタ

	AbstractScene* Update() override;							// 更新処理
	void Draw() const override;									// 描画処理

private:
	int HitCheck_BB(const Ball* ball, const BoxCollision* b);	// 当たり判定処理
};

