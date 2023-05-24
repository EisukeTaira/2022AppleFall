#pragma once

#include "AbstractScene.h"

class SceneManager : public AbstractScene
{
private:
	AbstractScene* now_scene;
public:
	SceneManager(AbstractScene* Scene) : now_scene(Scene) {}
	~SceneManager()
	{
		delete now_scene;
	}

	AbstractScene* Update() override;
	void Draw() const override;
};

