#pragma once

#include "BaseScene.h"

class End : public BaseScene
{
public:
	End(SceneChanger* changer);
	void Initialize() override;
	void Update() override;
	void Draw() override;
};