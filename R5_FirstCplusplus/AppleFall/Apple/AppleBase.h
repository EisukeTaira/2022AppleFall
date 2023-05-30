#pragma once

#include "../Common/Vector2.h"
#include "DxLib.h"

class AppleBase
{
public:
	enum APPLE_TYPE
	{
		E_RED,
		E_GREEN,
		E_YELLOW,
		E_POISON,
		E_APPLE_TYPE_MAX,
	};
protected:
	int image;			// �摜�f�[�^
	Vector2 location;	// ���S���W
	float radius;		// ���a
	APPLE_TYPE type;	// �����S�̎��

public:
	AppleBase()
	{
		image = NULL;
		location.x = 0.0f;
		location.y = 0.0f;
		radius = 0.0f;
		type = E_RED;
	}
	~AppleBase()
	{
	
	}

	virtual void Update() = 0;
	virtual void Draw() const = 0;

	void SetLocation(float x = 0.0f, float y = 0.0f)
	{
		this->location.x = x;
		this->location.y = y;
	}
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
	float GetRadius() const
	{
		return this->radius;
	}
	APPLE_TYPE GetType() const
	{
		return this->type;
	}
};
