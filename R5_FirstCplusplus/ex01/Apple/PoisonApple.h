#pragma once
#include "AppleBase.h"
class PoisonApple : public AppleBase
{
public:
	PoisonApple()
	{
		this->location.x = 0;
		this->location.y = 0;
		image = NULL;
		radius = 10.0f;
		type = E_POISON;
	}
	PoisonApple(float x, float y)
	{
		this->location.x = x;
		this->location.y = y;
		image = NULL;
		radius = 10.0f;
		type = E_POISON;
	}
	~PoisonApple()
	{

	}

	void Update() override;
	void Draw() const override;
};

