#pragma once

#include "Vector2.h"

class BoxCollision
{
protected:
	Vector2 location;
	Vector2 size;

public:
	BoxCollision() = default;
	~BoxCollision() {}

	Vector2 GetLocation() const
	{
		return location;
	}
	Vector2 GetSize() const
	{
		return size;
	}
	float GetLocationX() const
	{
		return location.x;
	}
	float GetLocationY() const
	{
		return location.y;
	}
	float GetSizeX() const
	{
		return size.x;
	}
	float GetSizeY() const
	{
		return size.y;
	}
};

