#include "Player.h"
#include "../Input/InputControl.h"

#define PLAYER_SPEED_MAX	(5.0f)		// 移動最高速度
#define PLAYER_SPEED_ADD	(0.25f)		// 移動加算量

#define PLAYER_IDLE			(0)			// 待機状態
#define PLAYER_RUN			(1)			// 走行状態

#define FLASH_PERIOD		(20)		// 点滅周期
#define FLASH_TIME			(120)		// 点滅時間

// コンストラクタ
Player::Player()
{
	// 画像読み込み処理
	image = new int[2];
	image[PLAYER_IDLE] = LoadGraph("images/Player01.png");
	image[PLAYER_RUN] = LoadGraph("images/Player02.png");

	// 初期座標の設定
	location.x = 400.0f;
	location.y = 420.0f;

	// 当たり判定のサイズの設定
	size.x = 50.0f;
	size.y = 75.0f;

	// 初期プレイヤースピードの設定
	speed = 0.0f;

	// 点滅状態の設定
	flash_flg = false;
	flash_count = 0;
	disp_flg = true;
}

// デストラクタ
Player::~Player()
{
	DeleteGraph(image[PLAYER_IDLE]);
	DeleteGraph(image[PLAYER_RUN]);
	delete[] image;
}

// 更新処理
void Player::Update()
{
	// 移動処理
	Move();
	// 点滅処理
	Flashing();
}

// 描画処理
void Player::Draw() const
{
	if (disp_flg)
	{
		if (speed < -0.001f)
		{
			DrawRotaGraphF(this->location.x, this->location.y, 0.5, 0.0, image[PLAYER_RUN], TRUE, FALSE, FALSE);
		}
		else if (speed > 0.001f)
		{
			DrawRotaGraphF(this->location.x, this->location.y, 0.5, 0.0, image[PLAYER_RUN], TRUE, TRUE, FALSE);
		}
		else
		{
			DrawRotaGraphF(this->location.x, this->location.y, 0.5, 0.0, image[PLAYER_IDLE], TRUE, FALSE, FALSE);
		}

		DrawBoxAA(this->location.x - (this->size.x / 2.0f), this->location.y - (this->size.y / 2.0f),
				this->location.x + (this->size.x / 2.0f), this->location.y + (this->size.y / 2.0f),
				GetColor(255, 0, 0), TRUE);
	}
}

#ifdef _DEBUG
// 移動処理
void Player::Move()
{
	if (CheckHitKey(KEY_INPUT_LEFT))
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
	else if (CheckHitKey(KEY_INPUT_RIGHT))
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
#else
// 移動処理
void Player::Move()
{
	// 左スティック or 十字ボタンで入力があった場合、移動を行う
	// 入力がない場合、減速させる
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
#endif // _DEBUG

// 点滅処理
void Player::Flashing()
{
	// 点滅フラグがtrueの時、点滅する。
	if (flash_flg)
	{

		flash_count++;

		if (flash_count % FLASH_TIME == 0)				// 点滅時間の場合
		{
			disp_flg = true;
			flash_flg = false;
		}
		else if (flash_count % FLASH_PERIOD == 0)		// 点滅間隔の場合
		{
			disp_flg = !disp_flg;
		}
	}
}
