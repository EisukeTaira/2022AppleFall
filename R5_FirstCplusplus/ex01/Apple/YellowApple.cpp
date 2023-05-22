#include "YellowApple.h"

YellowApple::YellowApple()
{
	this->location.x = 0;
	this->location.y = 0;
	image = NULL;
	radius = 15.0f;
	type = E_YELLOW;
}

void YellowApple::Update()
{
	this->location.y += 3.5f;
}

void YellowApple::Draw() const
{
	DrawCircleAA(this->location.x, this->location.y, this->radius, 150, GetColor(255, 217, 0), TRUE);
}
