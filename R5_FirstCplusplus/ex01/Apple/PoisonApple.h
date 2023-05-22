#pragma once
#include "AppleBase.h"
class PoisonApple : public AppleBase
{
public:
	PoisonApple();
	~PoisonApple()
	{

	}

	void Update() override;
	void Draw() const override;
};

