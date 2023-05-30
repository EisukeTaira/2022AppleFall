#include "YellowApple.h"

YellowApple::YellowApple()
{
	image = LoadGraph("Resource/images/fruit_apple_yellow.png");
	radius = 23.5f;
	type = E_YELLOW;
}

void YellowApple::Update()
{
	this->location.y += 3.5f;
}

void YellowApple::Draw() const
{
	DrawRotaGraphF(this->location.x, this->location.y, 0.125, 0.0, image, TRUE);
}
