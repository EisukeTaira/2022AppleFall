#pragma once
#include "AppleBase.h"
class RedApple : public AppleBase
{
private:

public:
	RedApple();
	~RedApple()
	{

	}

	void Update() override;
	void Draw() const override;
};
