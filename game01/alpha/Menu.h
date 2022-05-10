#pragma once

#include "BaseScene.h"

class Menu : public BaseScene
{
private:
	int menu_cursor;
public:
	Menu(SceneChanger* changer);
	void Initialize() override;
	void Update() override;
	void Draw() override;
};