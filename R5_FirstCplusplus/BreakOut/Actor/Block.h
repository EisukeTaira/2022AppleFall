#pragma once

#include "../Collision/BoxCollision.h"

class Block : public BoxCollision
{
private:
	int disp_flg;
public:
	Block();
	~Block();

	void Draw() const;

	void SetLocation(float x, float y);
	void SetDispFlg(int flg);
	int GetDispFlg() const;
};

