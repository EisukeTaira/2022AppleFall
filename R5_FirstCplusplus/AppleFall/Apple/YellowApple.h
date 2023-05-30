#pragma once
#include "AppleBase.h"
class YellowApple : public AppleBase
{
public:
	YellowApple();
	~YellowApple()
	{

	}

	void Update() override;
	void Draw() const override;
};

