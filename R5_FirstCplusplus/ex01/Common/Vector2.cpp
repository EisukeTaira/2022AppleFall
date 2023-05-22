#include "Vector2.h"

float Distance_Length(Vector2 a, Vector2 b)
{
	float dx = a.x - b.x;
	float dy = a.y - b.y;

	return ((dx * dx) + (dy * dy));
}
