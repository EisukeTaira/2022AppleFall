#pragma once

#include "AbstractScene.h"
#include "../Actor/Bar.h"
#include "../Actor/Ball.h"

class GameMainScene : public AbstractScene
{
private:
	Bar* bar;
	Ball* ball;
public:
	GameMainScene();					// コンストラクタ
	~GameMainScene();					// デストラクタ

	AbstractScene* Update() override;	// 更新処理
	void Draw() const override;			// 描画処理
};

