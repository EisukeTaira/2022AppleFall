#include "Bar.h"
#include "../Input/InputControl.h"
#include "DxLib.h"

Bar::Bar()
{
	location.x = 270.0f;
	location.y = 400.0f;
	size.x = 100.0f;
	size.y = 15.0f;
}

Bar::~Bar()
{

}

void Bar::Update()
{
	location.x = static_cast<float>(InputControl::GetMouseLocationX());
}

void Bar::Draw() const
{
	DrawBoxAA(this->location.x, this->location.y, (this->location.x + this->size.x), (this->location.y + this->size.y), GetColor(255, 255, 255), TRUE);
}
