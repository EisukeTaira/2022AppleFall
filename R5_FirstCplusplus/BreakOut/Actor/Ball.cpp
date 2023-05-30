#include "Ball.h"
#include "../Input/InputControl.h"
#include "DxLib.h"
#include <math.h>

Ball::Ball()
{
	location.x = 320.0f;
	location.y = 240.0f;
	size.x = 15.0f;
	size.y = 15.0f;
	state = E_STAY;
	speed = 5.0f;
	direction.x = 0.0f;
	direction.y = 0.0f;
	angle = 0.625f;
	remaining_lives = 2;
}

Ball::Ball(Vector2 location)
{
	location.x = 320.0f;
	location.y = 240.0f;
	size.x = 15.0f;
	size.y = 15.0f;
	state = E_STAY;
	speed = 5.0f;
	direction.x = 0.0f;
	direction.y = 0.0f;
	angle = 0.625f;
	remaining_lives = 2;
}

Ball::~Ball()
{
}

void Ball::Update()
{
	switch (state)
	{
		case Ball::E_STAY:
			if (InputControl::MouseButtonDown(MOUSE_INPUT_LEFT))
			{
				direction.x = speed * cosf(this->angle * DX_PI_F * 2.0f);
				direction.y = speed * sinf(this->angle * DX_PI_F * 2.0f);
				state = Ball::E_MOVE;
			}
			break;
		case Ball::E_MOVE:
			location.x += direction.x;
			location.y += direction.y;

			if (location.x < 0.1f || (640.0f - size.x) < location.x)
			{
				this->angle = (1.0f - this->angle) + 0.5f;
				if (this->angle > 1.0f)
				{
					this->angle -= 1.0f;
				}
				ChangeDirection(angle);
			}

			if (location.y < 0.1f)
			{
				this->angle = (1.0f - this->angle);
				ChangeDirection(angle);
			}
			
			if (location.y > 480.0f)
			{
				state = Ball::E_DEATH;
			}

			break;
		case Ball::E_DEATH:
			state = Ball::E_STAY;
			//remaining_lives--;
			break;
		default:
			break;
	}
}

void Ball::Draw() const
{
	DrawCircleAA(this->location.x + (size.x / 2.0f), this->location.y + (size.y / 2.0f), 7.5f, 150, GetColor(0xFF, 0xD7, 0x00), TRUE);
}

Ball::STATE Ball::GetState() const
{
	return this->state;
}

void Ball::SetLocation(Vector2 location)
{
	this->location.x = location.x + 50.0f;
	this->location.y = location.y - this->size.y;
}

int Ball::GetRemaining_Lives() const
{
	return this->remaining_lives;
}

void Ball::ChangeDirection(float angle)
{
	direction.x = speed * cosf(angle * DX_PI_F * 2.0f);
	direction.y = speed * sinf(angle * DX_PI_F * 2.0f);
}