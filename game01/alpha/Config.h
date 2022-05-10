#pragma once

#include "BaseScene.h"

class Config : public BaseScene
{
public:
	Config(SceneChanger* changer);
	void Initialize() override;
	void Update() override;
	void Draw() override;
};