#include "DxLib.h"
#include "Game.h"
#include "InputKey.h"

Game::Game(SceneChanger* changer) : BaseScene(changer)
{

}
void Game::Initialize()
{
	mImageHandle = LoadGraph("images/Scene_Game.png");	// 画像のロード
}
void Game::Update()
{
	InputKey* key = Get_InputKey();
	if (key->GetButtonDown(XINPUT_BUTTON_START))
	{
		mSceneChanger->ChangeScene(eScene_Menu);
	}
}
void Game::Draw()
{
	BaseScene::Draw();						//親クラスの描画メソッドを呼ぶ
	DrawString(0, 0, "ゲーム画面です。", GetColor(255, 255, 255));
	DrawString(0, 20, "Escキーを押すとメニュー画面に戻ります。", GetColor(255, 255, 255));

}