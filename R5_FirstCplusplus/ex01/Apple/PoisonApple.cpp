#include "PoisonApple.h"

PoisonApple::PoisonApple()
{
	this->location.x = 0;
	this->location.y = 0;
	image = NULL;
	radius = 15.0f;
	type = E_POISON;
}

void PoisonApple::Update()
{
	this->location.y += 0.5f;
}

void PoisonApple::Draw() const
{
	DrawCircleAA(this->location.x, this->location.y, this->radius, 150, GetColor(136, 72, 152), TRUE);
	DrawCircleAA(this->location.x, this->location.y, this->radius, 150, GetColor(0, 0, 0), FALSE);
}
