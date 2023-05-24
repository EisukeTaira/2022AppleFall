#include "PoisonApple.h"

PoisonApple::PoisonApple()
{
	image = LoadGraph("Resource/images/fruit_apple_shiwashiwa.png");
	radius = 18.5f;
	type = E_POISON;
}

void PoisonApple::Update()
{
	this->location.y += 0.5f;
}

void PoisonApple::Draw() const
{
	DrawRotaGraphF(this->location.x, this->location.y, 0.125, 0.0, image, TRUE);
}
