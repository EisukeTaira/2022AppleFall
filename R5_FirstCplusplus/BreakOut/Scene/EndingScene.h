#pragma once
#include "AbstractScene.h"
class EndingScene : public AbstractScene
{
private:
	int ending_count;
public:
	EndingScene();
	~EndingScene();

	void Update() override;
	void Draw() const override;
	AbstractScene* Change() override;
};

