#pragma once

class AbstractScene
{
public:
	~AbstractScene() {};						// デストラクタ

	virtual AbstractScene* Update() = 0;		// 更新処理
	virtual void Draw() const = 0;				// 描画処理
};