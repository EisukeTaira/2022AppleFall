#include "Block.h"
#include "DxLib.h"

Block::Block()
{
	this->location.x = 0.0f;
	this->location.y = 0.0f;
	this->size.x = 60.0f;
	this->size.y = 12.0f;
	disp_flg = TRUE;
}

Block::~Block()
{

}

void Block::Draw() const
{
	if (disp_flg == TRUE)
	{
		DrawBox((int)this->location.x, (int)this->location.y,
			(int)(this->location.x + this->size.x), (int)(this->location.y + this->size.y),
			GetColor(255, 0, 0), TRUE);
		DrawBox((int)this->location.x, (int)this->location.y,
			(int)(this->location.x + this->size.x), (int)(this->location.y + this->size.y),
			GetColor(255, 255, 255), FALSE);
	}	
}

void Block::SetLocation(float x, float y)
{
	this->location.x = x;
	this->location.y = y;
}

void Block::SetDispFlg(int flg)
{
	this->disp_flg = flg;
}

int Block::GetDispFlg() const
{
	return this->disp_flg;
}
