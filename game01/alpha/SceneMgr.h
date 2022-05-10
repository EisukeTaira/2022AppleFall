#pragma once

#include "SceneChanger.h"
#include "BaseScene.h"

class SceneMgr : public SceneChanger, Task
{
private:
	BaseScene* mScene;
	eScene mNextScene;
public:
	SceneMgr();
	void Initialize() override;
	void Finalize() override;
	void Update() override;
	void Draw() override;

	void ChangeScene(eScene next) override;
};