#pragma once

#include "../Collision/BoxCollision.h"

class Ball : public BoxCollision
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
	int remaining_lives;

public:
	Ball();
	~Ball();

	void Update();
	void Draw() const;

	STATE GetState() const;
	void SetLocation(Vector2 location);
	int GetRemaining_Lives() const;

	void ChangeDirection();
	void ChangeDirection(float angle);
};

