#include "Ball.h"
#include "DxLib.h"

Ball::Ball()
{
	radius = 15.0f;
	location.x = 320.0f;
	location.y = 240.0f;
	state = E_STAY;
}

Ball::Ball(Vector2 location)
{
	radius = 7.5f;
	this->location.x = location.x + 50.0f;
	this->location.y = location.y - this->radius;
	state = E_STAY;
}

Ball::~Ball()
{
}

void Ball::Update()
{
}

void Ball::Draw() const
{
	DrawCircleAA(this->location.x, this->location.y, this->radius, 150, GetColor(255, 255, 255), TRUE);
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
