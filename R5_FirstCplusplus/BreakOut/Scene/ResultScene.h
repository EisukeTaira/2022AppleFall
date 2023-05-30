#pragma once

#include "AbstractScene.h"

class ResultScene : public AbstractScene
{
private:

public:
	ResultScene();						// コンストラクタ
	~ResultScene();						// デストラクタ

	AbstractScene* Update() override;	// 更新処理
	void Draw() const override;			// 描画処理
};

