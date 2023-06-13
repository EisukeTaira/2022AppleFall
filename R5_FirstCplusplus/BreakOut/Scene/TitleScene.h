#pragma once

#include "AbstractScene.h"

class TitleScene : public AbstractScene
{
private:

public:
	TitleScene();							// コンストラクタ
	~TitleScene();							// デストラクタ

	void Update() override;					// 更新処理
	void Draw() const override;				// 描画処理
	AbstractScene* Change() override;		// シーン切り替え処理
};

