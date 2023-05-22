#pragma once
#include "AppleBase.h"
class RedApple : public AppleBase
{
private:

public:
	RedApple()
	{
		this->location.x = 0;
		this->location.y = 0;
		image = NULL;
		radius = 15.0f;
		type = E_RED;
	}
	RedApple(float x, float y)
	{
		this->location.x = x;
		this->location.y = y;
		image = NULL;
		radius = 10.0f;
		type = E_RED;
	}
	~RedApple()
	{

	}

	void Update() override;
	void Draw() const override;
};
