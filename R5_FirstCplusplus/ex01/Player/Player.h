#pragma once

#include "../Common/Vector2.h"
#include "DxLib.h"

class Player
{
private:
	int image;
	Vector2 location;
	Vector2 size;
	float direction;
	float speed;

public:
	Player();
	~Player();

	void Update();
	void Draw() const;

	Vector2 GetLocation() const
	{
		return this->location;
	}
	Vector2 GetSize() const
	{
		return this->size;
	}

};

