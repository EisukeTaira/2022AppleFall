#include "GreenApple.h"

// �R���X�g���N�^
GreenApple::GreenApple()
{
	image = LoadGraph("Resource/images/fruit_ao_ringo.png");
	radius = 23.5f;
	type = E_GREEN;
}

// �X�V����
void GreenApple::Update()
{
	this->location.y += 2.0f;
}

// �`�揈��
void GreenApple::Draw() const
{
	DrawRotaGraphF(this->location.x, this->location.y, 0.125, 0.0, image, TRUE);
}
