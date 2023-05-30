#include "GreenApple.h"

// コンストラクタ
GreenApple::GreenApple()
{
	image = LoadGraph("Resource/images/fruit_ao_ringo.png");
	radius = 23.5f;
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
	DrawRotaGraphF(this->location.x, this->location.y, 0.125, 0.0, image, TRUE);
}
