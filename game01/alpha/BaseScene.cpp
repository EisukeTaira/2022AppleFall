#include "BaseScene.h"
#include "DxLib.h"

BaseScene::BaseScene(SceneChanger* changer) : mImageHandle(0)
{
	mSceneChanger = changer;
}
BaseScene::~BaseScene()
{

}
void BaseScene::Initialize()
{

}
void BaseScene::Finalize()
{
	DeleteGraph(mImageHandle);
}
void BaseScene::Update()
{

}
void BaseScene::Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
}
