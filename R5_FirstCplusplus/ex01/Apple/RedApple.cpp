#include "RedApple.h"

RedApple::RedApple()
{
	this->location.x = 0;
	this->location.y = 0;
	image = NULL;
	radius = 15.0f;
	type = E_RED;
}

void RedApple::Update()
{
	this->location.y += 1.0f;
}

void RedApple::Draw() const
{
	DrawCircleAA(this->location.x, this->location.y, this->radius, 150, GetColor(255, 0, 0), TRUE);
}
