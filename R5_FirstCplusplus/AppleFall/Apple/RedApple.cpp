#include "RedApple.h"

RedApple::RedApple()
{
	image = LoadGraph("Resource/images/fruit_ringo.png");
	radius = 23.5f;
	type = E_RED;
}

void RedApple::Update()
{
	this->location.y += 1.0f;
}

void RedApple::Draw() const
{
	DrawRotaGraphF(this->location.x, this->location.y, 0.125, 0.0, image, TRUE);
}
