#include "Player.h"
#include "../Input/InputControl.h"

#define PLAYER_SPEED_MAX	(5.0f)
#define PLAYER_SPEED_ADD	(0.25f)

Player::Player()
{
	image = NULL;
	location.x = 400.0f;
	location.y = 400.0f;
	size.x = 50.0f;
	size.y = 75.0f;
	speed = 0.0f;
	flash_flg = false;
	flash_count = 0;
	disp_flg = true;
}

Player::~Player()
{

}

void Player::Update()
{
	Move();
	Flashing();
}

void Player::Draw() const
{
	if (disp_flg)
	{
		DrawBoxAA(this->location.x, this->location.y,
			this->location.x + this->size.x, this->location.y + this->size.y,
			GetColor(255, 255, 255), TRUE);
	}
}

void Player::Move()
{
	// ���X�e�B�b�N or �\���{�^���œ��͂��������ꍇ�A�ړ����s��
	// ���͂��Ȃ��ꍇ�A����������
	if (InputControl::getThumbLX() < -0.5f)
	{
		if (speed > -PLAYER_SPEED_MAX)
		{
			speed -= PLAYER_SPEED_ADD;
		}
		else
		{
			speed = -PLAYER_SPEED_MAX;
		}
	}
	else if (InputControl::getThumbLX() > 0.5f)
	{
		if (speed < PLAYER_SPEED_MAX)
		{
			speed += PLAYER_SPEED_ADD;
		}
		else
		{
			speed = PLAYER_SPEED_MAX;
		}
	}
	else if (InputControl::ButtonPressed(XINPUT_BUTTON_DPAD_LEFT))
	{
		if (speed > -PLAYER_SPEED_MAX)
		{
			speed -= PLAYER_SPEED_ADD;
		}
		else
		{
			speed = -PLAYER_SPEED_MAX;
		}
	}
	else if (InputControl::ButtonPressed(XINPUT_BUTTON_DPAD_RIGHT))
	{
		if (speed < PLAYER_SPEED_MAX)
		{
			speed += PLAYER_SPEED_ADD;
		}
		else
		{
			speed = PLAYER_SPEED_MAX;
		}
	}
	else
	{
		speed *= 0.9f;
		if (-0.001f < speed && speed < 0.001f)
		{
			speed = 0.0f;
		}
	}

	// ���W�ɉ����x�����Z����
	location.x += speed;

	// ��ʍ����̈ړ�������݂���
	if (location.x < 0.0f)
	{
		location.x = 0.0f;
		speed = 0.0f;
	}

	// ��ʉE���̈ړ�������݂���
	if (location.x > 640.0f - size.x)
	{
		location.x = 640.0f - size.x;
		speed = 0.0f;
	}
}

void Player::Flashing()
{
	if (flash_flg)
	{
		flash_count++;
		if (flash_count % 120 == 0)
		{
			disp_flg = true;
			flash_flg = false;
		}
		else if (flash_count % 20 == 0)
		{
			disp_flg = !disp_flg;
		}
	}
}
