#include "GreenApple.h"

GreenApple::GreenApple()
{
	this->location.x = 0;
	this->location.y = 0;
	image = NULL;
	radius = 15.0f;
	type = E_GREEN;
}

void GreenApple::Update()
{
	this->location.y += 2.0f;
}

void GreenApple::Draw() const
{
	DrawCircleAA(this->location.x, this->location.y, this->radius, 150, GetColor(0, 255, 0), TRUE);
}
