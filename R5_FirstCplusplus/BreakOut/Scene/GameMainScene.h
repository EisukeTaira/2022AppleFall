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
	Block* block;
	int block_count;
public:
	GameMainScene();											// コンストラクタ
	~GameMainScene();											// デストラクタ

	void Update() override;										// 更新処理
	void Draw() const override;									// 描画処理
	AbstractScene* Change() override;							// シーン遷移処理

private:
	int HitCheck_BB(const Ball* ball, const BoxCollision* target);	// 当たり判定処理
};

