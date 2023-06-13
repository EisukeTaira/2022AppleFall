#include "Ball.h"
#include "../Input/InputControl.h"
#include "DxLib.h"
#include <math.h>

// コンストラクタ
Ball::Ball()
{
	location.x = 320.0f;
	location.y = 240.0f;
	size.x = 15.0f;
	size.y = 15.0f;
	state = E_STAY;
	speed = 2.5f;
	direction.x = 0.0f;
	direction.y = 0.0f;
	remaining_lives = 2;
}

// デストラクタ
Ball::~Ball()
{

}

// 更新処理
void Ball::Update()
{
	switch (state)
	{
		case Ball::E_STAY:
			// 左クリックが入力されたら、移動を開始する
			if (InputControl::MouseButtonDown(MOUSE_INPUT_LEFT))
			{
				ChangeDirection(0.625f);
				state = Ball::E_MOVE;
			}
			break;
		case Ball::E_MOVE:
			// ボールの移動
			location.x += direction.x;
			location.y += direction.y;

			// 壁に当たったら、反射させる
			if (location.x < 1.0f || location.x > (640.0f - size.x))
			{
				if (location.x < 1.0f)
				{
					location.x = 1.0f;
				}
				else
				{
					location.x = (640.0f - size.x);
				}
				direction.x *= -1.0f;
			}
			
			// 天井に当たっていたら反射させる
			if (location.y < 1.0f)
			{
				location.y = 1.0f;
				ChangeDirection();
			}
			
			// キルYに到達したら、死亡状態にする
			if (location.y > 640.0f)
			{
				state = Ball::E_DEATH;
			}
			
			break;
		case Ball::E_DEATH:
			// 待機状態にする
			state = Ball::E_STAY;
			// 残機を1つ減らす
		//	remaining_lives--;
			break;
		default:
			break;
	}
}

// 描画処理
void Ball::Draw() const
{
	DrawCircleAA(this->location.x + (size.x / 2.0f), this->location.y + (size.y / 2.0f), 7.5f, 150, GetColor(0xFF, 0xD7, 0x00), TRUE);
}

// ボールの状態を取得する
Ball::STATE Ball::GetState() const
{
	return this->state;
}

// ボールの位置情報を設定
void Ball::SetLocation(Vector2 location)
{
	this->location.x = location.x + 50.0f;
	this->location.y = location.y - this->size.y;
}

// 残機数を取得する
int Ball::GetRemaining_Lives() const
{
	return this->remaining_lives;
}

// 角度変更処理
void Ball::ChangeDirection()
{
	direction.y *= -1.0f;
}
void Ball::ChangeDirection(float angle)
{
	direction.x = speed * cosf(angle * DX_PI_F * 2.0f);
	direction.y = speed * sinf(angle * DX_PI_F * 2.0f);
}