#include "Player.h"

Player::Player()
{
	image = NULL;
	location.x = 400.0f;
	location.y = 240.0f;
	size.x = 30.0f;
	size.y = 75.0f;
	direction = 0.0f;
	speed = 0.0f;
}

Player::~Player()
{

}

void Player::Update()
{
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		direction = -1.0f;
		if (speed >= -1.0f)
		{
			speed += -0.005f;
		}
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		direction = 1.0f;
		if (speed <= 1.0f)
		{
			speed += 0.005f;
		}
	}
	else
	{
		if (speed < 0)
		{
			speed += 0.01f;
		}
		else if (speed > 0)
		{
			speed += -0.01f;
		}
	}

	location.x += speed;
}

void Player::Draw() const
{
	DrawBox((int)this->location.x, (int)this->location.y,
			(int)this->location.x + this->size.x, (int)this->location.y + this->size.y,
			GetColor(255, 255, 255), TRUE);
}
