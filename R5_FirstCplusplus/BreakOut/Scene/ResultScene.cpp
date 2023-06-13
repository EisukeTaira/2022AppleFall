#include "ResultScene.h"
#include "DxLib.h"

// コンストラクタ
ResultScene::ResultScene()
{

}

// デストラクタ
ResultScene::~ResultScene()
{
}

// 更新処理
void ResultScene::Update()
{
	
}

// 描画処理
void ResultScene::Draw() const
{
#ifdef _DEBUG
	DrawFormatString(10, 10, GetColor(255, 255, 255), "リザルト画面");
#endif // _DEBUG

}

AbstractScene* ResultScene::Change()
{
	return nullptr;
}
