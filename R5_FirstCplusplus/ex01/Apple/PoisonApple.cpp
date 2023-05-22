#include "PoisonApple.h"

void PoisonApple::Update()
{
	this->location.y += 0.5f;
}

void PoisonApple::Draw() const
{
	DrawCircle((int)this->location.x, (int)this->location.y, (int)this->radius, GetColor(136, 72, 152), TRUE);
}
