#pragma once

#include "AbstractScene.h"

class SceneManager : public AbstractScene
{
private:
	AbstractScene* mScene;

public:
	SceneManager(AbstractScene* scene);
	~SceneManager();

	AbstractScene* Update() override;
	void Draw() const override;
};