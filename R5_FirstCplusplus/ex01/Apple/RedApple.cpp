#include "RedApple.h"

void RedApple::Update()
{
	this->location.y += 1.0f;
}

void RedApple::Draw() const
{
	DrawCircle((int)this->location.x, (int)this->location.y, (int)this->radius, GetColor(255, 0, 0), TRUE);
}
