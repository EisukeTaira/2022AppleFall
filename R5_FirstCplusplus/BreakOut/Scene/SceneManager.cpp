#include "SceneManager.h"

SceneManager::SceneManager(AbstractScene* scene)
{
	mScene = scene;
}

SceneManager::~SceneManager()
{
	delete mScene;
}

AbstractScene* SceneManager::Update()
{
	AbstractScene* p = mScene->Update();

	if (p != mScene)
	{
		delete mScene;
		mScene = p;
	}

	return p;
}

void SceneManager::Draw() const
{
	mScene->Draw();
}