#pragma once

#include "BaseScene.h"

class Ranking : public BaseScene
{
public:
	Ranking(SceneChanger* changer);
	void Initialize() override;
	void Update() override;
	void Draw() override;
private:
	void ReadRanking();
	void SaveRanking();
};