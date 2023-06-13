#pragma once

class AbstractScene
{
public:
	~AbstractScene() {};						// デストラクタ

	virtual void Update() = 0;					// 更新処理
	virtual void Draw() const = 0;				// 描画処理
	virtual AbstractScene* Change() = 0;		// シーン変更処理
};