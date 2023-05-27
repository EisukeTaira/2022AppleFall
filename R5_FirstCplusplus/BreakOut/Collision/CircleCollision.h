#pragma once

#include "Vector2.h"

class CircleCollision
{
protected:
	Vector2 location;
	float radius;

public:
	CircleCollision() = default;
	~CircleCollision() {}

	Vector2 GetLocation() const
	{
		return location;
	}
	float GetLocationX() const
	{
		return location.x;
	}
	float GetLocationY() const
	{
		return location.y;
	}
	float GetRadius() const
	{
		return radius;
	}
};

