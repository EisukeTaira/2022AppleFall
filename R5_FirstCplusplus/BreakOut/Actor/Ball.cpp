#include "Ball.h"
#include "../Input/InputControl.h"
#include "DxLib.h"
#include <math.h>

// �R���X�g���N�^
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

// �f�X�g���N�^
Ball::~Ball()
{

}

// �X�V����
void Ball::Update()
{
	switch (state)
	{
		case Ball::E_STAY:
			// ���N���b�N�����͂��ꂽ��A�ړ����J�n����
			if (InputControl::MouseButtonDown(MOUSE_INPUT_LEFT))
			{
				ChangeDirection(0.625f);
				state = Ball::E_MOVE;
			}
			break;
		case Ball::E_MOVE:
			// �{�[���̈ړ�
			location.x += direction.x;
			location.y += direction.y;

			// �ǂɓ���������A���˂�����
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
			
			// �V��ɓ������Ă����甽�˂�����
			if (location.y < 1.0f)
			{
				location.y = 1.0f;
				ChangeDirection();
			}
			
			// �L��Y�ɓ��B������A���S��Ԃɂ���
			if (location.y > 640.0f)
			{
				state = Ball::E_DEATH;
			}
			
			break;
		case Ball::E_DEATH:
			// �ҋ@��Ԃɂ���
			state = Ball::E_STAY;
			// �c�@��1���炷
		//	remaining_lives--;
			break;
		default:
			break;
	}
}

// �`�揈��
void Ball::Draw() const
{
	DrawCircleAA(this->location.x + (size.x / 2.0f), this->location.y + (size.y / 2.0f), 7.5f, 150, GetColor(0xFF, 0xD7, 0x00), TRUE);
}

// �{�[���̏�Ԃ��擾����
Ball::STATE Ball::GetState() const
{
	return this->state;
}

// �{�[���̈ʒu����ݒ�
void Ball::SetLocation(Vector2 location)
{
	this->location.x = location.x + 50.0f;
	this->location.y = location.y - this->size.y;
}

// �c�@�����擾����
int Ball::GetRemaining_Lives() const
{
	return this->remaining_lives;
}

// �p�x�ύX����
void Ball::ChangeDirection()
{
	direction.y *= -1.0f;
}
void Ball::ChangeDirection(float angle)
{
	direction.x = speed * cosf(angle * DX_PI_F * 2.0f);
	direction.y = speed * sinf(angle * DX_PI_F * 2.0f);
}