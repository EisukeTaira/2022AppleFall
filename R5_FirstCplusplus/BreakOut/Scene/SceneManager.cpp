#include "SceneManager.h"
#include "../Input/InputControl.h"
#include "DxLib.h"

SceneManager::SceneManager(AbstractScene* scene)
{
	mScene = scene;
}

SceneManager::~SceneManager()
{
	delete mScene;
}

void SceneManager::Update()
{
	// 入力制御機能：更新処理
	InputControl::Update();
	// シーンの更新処理
	mScene->Update();
}

void SceneManager::Draw() const
{
	// 画面の初期化
	ClearDrawScreen();
	// シーンの描画処理
	mScene->Draw();
	// 裏画面の内容を表画面に反映
	ScreenFlip();
}

AbstractScene* SceneManager::Change()
{
	AbstractScene* p = mScene->Change();

	if (p != mScene)
	{
		delete mScene;
		mScene = p;
	}

	return mScene;
}
