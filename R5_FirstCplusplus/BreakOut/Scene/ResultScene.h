#pragma once

#include "AbstractScene.h"

class ResultScene : public AbstractScene
{
private:

public:
	ResultScene();						// コンストラクタ
	~ResultScene();						// デストラクタ

	void Update() override;				// 更新処理
	void Draw() const override;			// 描画処理
	AbstractScene* Change() override;	// 更新処理
};

