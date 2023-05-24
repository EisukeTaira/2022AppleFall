#include "GreenApple.h"

// コンストラクタ
GreenApple::GreenApple()
{
	this->location.x = 0.0f;
	this->location.y = 0.0f;
	image = NULL;
	radius = 15.0f;
	type = E_GREEN;
}

// 更新処理
void GreenApple::Update()
{
	this->location.y += 2.0f;
}

// 描画処理
void GreenApple::Draw() const
{
	DrawCircleAA(this->location.x, this->location.y, this->radius, 150, GetColor(0, 255, 0), TRUE);
	DrawCircleAA(this->location.x, this->location.y, this->radius, 150, GetColor(0, 0, 0), FALSE);
}
