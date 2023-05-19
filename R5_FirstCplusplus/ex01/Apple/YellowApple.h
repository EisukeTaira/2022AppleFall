#pragma once
#include "AppleBase.h"
class YellowApple : public AppleBase
{
public:
	YellowApple()
	{
		this->location.x = 0;
		this->location.y = 0;
		image = NULL;
		radius = 10.0f;
		type = E_YELLOW;
	}
	YellowApple(float x, float y)
	{
		this->location.x = x;
		this->location.y = y;
		image = NULL;
		radius = 10.0f;
		type = E_YELLOW;
	}
	~YellowApple()
	{

	}

	void Update() override;
	void Draw() const override;
};

