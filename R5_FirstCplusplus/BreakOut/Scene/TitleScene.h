#pragma once

#include "AbstractScene.h"

class TitleScene : public AbstractScene
{
private:

public:
	TitleScene();							// コンストラクタ
	~TitleScene();							// デストラクタ

	AbstractScene* Update() override;		// 更新処理
	void Draw() const override;				// 描画処理
};

