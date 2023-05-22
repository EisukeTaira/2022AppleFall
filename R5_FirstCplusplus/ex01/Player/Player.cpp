#include "Player.h"
#include "../Input/InputControl.h"

#define PLAYER_SPEED_MAX	(7.0f)
#define PLAYER_SPEED_ADD	(0.05f)

Player::Player()
{
	image = NULL;
	location.x = 400.0f;
	location.y = 400.0f;
	size.x = 50.0f;
	size.y = 125.0f;
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

}

void Player::Draw() const
{
	if (disp_flg)
	{
		DrawBox((int)this->location.x, (int)this->location.y,
			(int)this->location.x + (int)this->size.x, (int)this->location.y + (int)this->size.y,
			GetColor(255, 255, 255), TRUE);
	}
}

void Player::Move()
{
#ifdef _DEBUG
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		if (speed > -PLAYER_SPEED_MAX)
		{
			speed += -PLAYER_SPEED_ADD;
		}
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		if (speed < PLAYER_SPEED_MAX)
		{
			speed += PLAYER_SPEED_ADD;
		}
	}
	else
	{
		speed *= (1.0f - PLAYER_SPEED_ADD);
		if (-0.001f < speed && speed < 0.001f)
		{
			speed = 0.0f;
		}
	}
#endif // _DEBUG

	// 左スティック or 十字ボタンで入力があった場合、移動を行う
	// 入力がない場合、減速させる
	if (InputControl::getThumbLX() < -0.5f)
	{
		if (speed > -PLAYER_SPEED_MAX)
		{
			speed += -PLAYER_SPEED_ADD;
		}
	}
	else if (InputControl::getThumbLX() > 0.5f)
	{
		if (speed < PLAYER_SPEED_MAX)
		{
			speed += PLAYER_SPEED_ADD;
		}
	}
	else if (InputControl::ButtonPressed(XINPUT_BUTTON_DPAD_LEFT))
	{
		if (speed > -PLAYER_SPEED_MAX)
		{
			speed += -PLAYER_SPEED_ADD;
		}
	}
	else if (InputControl::ButtonPressed(XINPUT_BUTTON_DPAD_RIGHT))
	{
		if (speed < PLAYER_SPEED_MAX)
		{
			speed += PLAYER_SPEED_ADD;
		}
	}
	else
	{
		speed *= (1.0f - PLAYER_SPEED_ADD);
		if (-0.001f < speed && speed < 0.001f)
		{
			speed = 0.0f;
		}
	}

	// 座標に加速度を加算する
	location.x += speed;

	// 画面左側の移動制限を設ける
	if (location.x < 0.0f)
	{
		location.x = 0.0f;
		speed = 0.0f;
	}

	// 画面右側の移動制限を設ける
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
