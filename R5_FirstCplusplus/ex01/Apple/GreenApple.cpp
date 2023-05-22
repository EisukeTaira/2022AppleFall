#include "GreenApple.h"

void GreenApple::Update()
{
	this->location.y += 2.0f;
}

void GreenApple::Draw() const
{
	DrawCircle((int)this->location.x, (int)this->location.y, (int)this->radius, GetColor(0, 255, 0), TRUE);
}
