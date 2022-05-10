#pragma once

#include "BaseScene.h"

class Game : public BaseScene
{
public:
	Game(SceneChanger* changer);
	void Initialize() override;
	void Update() override;
	void Draw() override;
};