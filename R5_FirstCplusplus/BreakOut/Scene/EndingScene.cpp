#include "EndingScene.h"
#include "DxLib.h"

// コンストラクタ
EndingScene::EndingScene()
{
	ending_count = 0;
}

// デストラクタ
EndingScene::~EndingScene()
{

}

// 更新処理
void EndingScene::Update()
{
	ending_count++;
}

// 描画処理
void EndingScene::Draw() const
{
#ifdef _DEBUG
	DrawFormatString(10, 10, GetColor(255, 255, 255), "エンド画面");
#endif // _DEBUG

	DrawFormatString(10, 100, GetColor(255, 255, 255), "ゲームを終了します");
}

AbstractScene* EndingScene::Change()
{
	if (ending_count > 300)
	{
		return nullptr;
	}

	return dynamic_cast<AbstractScene*>(this);
}
