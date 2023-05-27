#pragma once

#include "../Collision/BoxCollision.h"

class Bar : public BoxCollision
{
private:

public:
	Bar();
	~Bar();

	void Update();
	void Draw() const;
};

