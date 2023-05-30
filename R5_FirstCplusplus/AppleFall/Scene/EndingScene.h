#pragma once
#include "AbstractScene.h"
class EndingScene : public AbstractScene
{
private:
	int back_ground;
	int wait_time;

public:
	EndingScene();
	~EndingScene();

	AbstractScene* Update() override;
	void Draw() const override;
};

