#include "EndingScene.h"
#include "DxLib.h"

// コンストラクタ
EndingScene::EndingScene()
{

}

// デストラクタ
EndingScene::~EndingScene()
{

}

// 更新処理
AbstractScene* EndingScene::Update()
{
	return dynamic_cast<AbstractScene*>(this);
}

// 描画処理
void EndingScene::Draw() const
{
#ifdef _DEBUG
	DrawFormatString(10, 10, GetColor(255, 255, 255), "エンド画面");
#endif // _DEBUG
}