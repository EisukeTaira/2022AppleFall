#pragma once
#include "AbstractScene.h"
class EndingScene : public AbstractScene
{
private:

public:
	EndingScene();
	~EndingScene();

	AbstractScene* Update() override;
	void Draw() const override;
};

