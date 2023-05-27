#pragma once

#include "../Collision/CircleCollision.h"

class Ball : public CircleCollision
{
public:
	enum STATE
	{
		E_STAY,
		E_MOVE,
		E_DEATH,
		E_STATE_MAX
	};
private:
	STATE state;
	Vector2 direction;
	float speed;
public:
	Ball();
	Ball(Vector2 location);
	~Ball();

	void Update();
	void Draw() const;

	STATE GetState() const;
	void SetLocation(Vector2 location);
};

