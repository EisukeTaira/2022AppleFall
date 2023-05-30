#pragma once

#include "AbstractScene.h"
#include "../Apple/RedApple.h"
#include "../Apple/GreenApple.h"
#include "../Apple/YellowApple.h"
#include "../Apple/PoisonApple.h"
#include "../Player/Player.h"

#define APPLE_MAX	(10)

class GameMainScene : public AbstractScene
{
private:
	Player* player;
	AppleBase* apple[APPLE_MAX];
	int back_ground;
	int ui_image[4];
	int ui_count[4];
	int score;
	int time_limit;
	int generate_count;
	bool pause_flg;
public:
	GameMainScene();
	~GameMainScene();

	AbstractScene* Update() override;
	void Draw() const override;

private:
	void CreateApple(void);
	bool OnCollision(const Player* player, const AppleBase* apple);
	void AddScore(AppleBase::APPLE_TYPE type);
};

