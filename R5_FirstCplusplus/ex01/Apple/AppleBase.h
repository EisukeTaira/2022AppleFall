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
		E_APPLE_STATE_MAX,
	};
protected:
	int image;			// 画像データ
	Vector2 location;	// 中心座標
	float radius;		// 半径
	APPLE_TYPE type;	// リンゴの種類

public:
	AppleBase() = default;
	~AppleBase() {}

	virtual void Update() = 0;
	virtual void Draw() const = 0;

	void SetLocation(float x, float y)
	{
		this->location.x = x;
		this->location.y = y;
	}
	Vector2 GetLocation() const
	{
		return this->location;
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
