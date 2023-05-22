#pragma once
#include "AppleBase.h"
class GreenApple : public AppleBase
{
public:
	GreenApple();
	~GreenApple()
	{

	}

	void Update() override;
	void Draw() const override;
};

