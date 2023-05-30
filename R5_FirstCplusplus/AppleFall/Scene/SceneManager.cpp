#include "SceneManager.h"

AbstractScene* SceneManager::Update()
{
	AbstractScene* p = now_scene->Update();

	if (p != now_scene)
	{
		delete now_scene;
		now_scene = p;
	}

	return p;
}

void SceneManager::Draw() const
{
	now_scene->Draw();
}
