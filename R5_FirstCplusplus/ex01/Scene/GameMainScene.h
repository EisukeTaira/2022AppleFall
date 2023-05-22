#pragma once

#include "../Apple/RedApple.h"
#include "../Apple/GreenApple.h"
#include "../Apple/YellowApple.h"
#include "../Apple/PoisonApple.h"
#include "../Player/Player.h"

#define APPLE_MAX	(10)

class GameMainScene
{
private:
	Player* player;
	AppleBase* apple[APPLE_MAX];
	int generate_count;
	int score;
	bool pause_flg;
public:
	GameMainScene();
	~GameMainScene();

	void Update();
	void Draw() const;

	void CreateApple(void);
private:
	bool OnCollision(const Player* player, const AppleBase* apple);
	void AddScore(AppleBase::APPLE_TYPE type);
};

