#pragma once
#include "AppleBase.h"
class GreenApple : public AppleBase
{
public:
	GreenApple()
	{
		this->location.x = 0;
		this->location.y = 0;
		image = NULL;
		radius = 15.0f;
		type = E_GREEN;
	}
	~GreenApple()
	{

	}

	void Update() override;
	void Draw() const override;
};

