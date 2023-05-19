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
	AppleBase* apple[10];
public:
	GameMainScene();
	~GameMainScene();

	void Update();
	void Draw() const;
};

