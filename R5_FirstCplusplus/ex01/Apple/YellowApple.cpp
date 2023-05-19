#include "YellowApple.h"

void YellowApple::Update()
{
	this->location.y += 1.0f;
}

void YellowApple::Draw() const
{
	DrawCircle((int)this->location.x, (int)this->location.y, (int)this->radius, GetColor(255, 217, 0), TRUE);
}
