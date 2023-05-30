#include "Ball.h"
#include "../Input/InputControl.h"
#include "DxLib.h"
#include <math.h>

Ball::Ball()
{
	radius = 15.0f;
	location.x = 320.0f;
	location.y = 240.0f;
	state = E_STAY;
	speed = 1.0f;
	direction.x = 0.0f;
	direction.y = 0.0f;
	remaining_lives = 2;
}

Ball::Ball(Vector2 location)
{
	radius = 7.5f;
	this->location.x = location.x + 50.0f;
	this->location.y = location.y - this->radius;
	state = Ball::E_STAY;
	speed = 1.0f;
	direction.x = cosf(0.625f * DX_PI_F * 2.0f);
	direction.y = sinf(0.625f * DX_PI_F * 2.0f);
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
				direction.x = cosf(0.625f * DX_PI_F * 2.0f);
				direction.y = sinf(0.625f * DX_PI_F * 2.0f);
				state = Ball::E_MOVE;
			}
			break;
		case Ball::E_MOVE:
			location.x += direction.x;
			location.y += direction.y;

			if (location.x < radius || (640.0f - radius) < location.x)
			{
				if (location.x < radius)
				{
					location.x = radius;
				}
				else
				{
					location.x = 640.0f - radius;
				}
				float angle = atan2f(direction.x, direction.y);
				ChangeDirection(angle);
			}

			if (location.y < (radius * 2.0f))
			{
				float angle = atan2f(-direction.y, direction.x);
				ChangeDirection(angle);
			}
			
			if (location.y >= 480.0f)
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
	DrawCircleAA(this->location.x, this->location.y, this->radius, 150, GetColor(0xFF, 0xD7, 0x00), TRUE);
}

Ball::STATE Ball::GetState() const
{
	return this->state;
}

void Ball::SetLocation(Vector2 location)
{
	this->location.x = location.x + 50.0f;
	this->location.y = location.y - this->radius;
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