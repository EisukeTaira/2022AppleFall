#pragma once

#include "../Common/Vector2.h"
#include "DxLib.h"

class Player
{
private:
	int image;
	Vector2 location;
	Vector2 size;
	float speed;
	bool flash_flg;
	int flash_count;
	bool disp_flg;
public:
	Player();
	~Player();

	void Update();
	void Draw() const;

	Vector2 GetLocation() const
	{
		return this->location;
	}
	float GetLocationX() const
	{
		return this->location.x;
	}
	float GetLocationY() const
	{
		return this->location.y;
	}
	Vector2 GetSize() const
	{
		return this->size;
	}
	float GetSizeX() const
	{
		return this->size.x;
	}
	float GetSizeY() const
	{
		return this->size.y;
	}

	bool GetFlashFlg() const
	{
		return flash_flg;
	}
	void SetFlashFlg(bool flg)
	{
		this->flash_flg = flg;
	}
private:
	void Move();
	void Flashing();
};

