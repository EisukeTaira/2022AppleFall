#include "Player.h"
#include "../Input/InputControl.h"

#define PLAYER_SPEED_MAX	(5.0f)		// �ړ��ō����x
#define PLAYER_SPEED_ADD	(0.25f)		// �ړ����Z��

#define PLAYER_IDLE			(0)			// �ҋ@���
#define PLAYER_RUN			(1)			// ���s���

#define FLASH_PERIOD		(20)		// �_�Ŏ���
#define FLASH_TIME			(120)		// �_�Ŏ���

// �R���X�g���N�^
Player::Player()
{
	// �摜�ǂݍ��ݏ���
	image = new int[2];
	image[PLAYER_IDLE] = LoadGraph("Resource/images/Player01.png");
	image[PLAYER_RUN] = LoadGraph("Resource/images/Player02.png");

	// �������W�̐ݒ�
	location.x = 250.0f;
	location.y = 430.0f;

	// �����蔻��̃T�C�Y�̐ݒ�
	size.x = 50.0f;
	size.y = 75.0f;

	// �����v���C���[�X�s�[�h�̐ݒ�
	speed = 0.0f;

	// �_�ŏ�Ԃ̐ݒ�
	flash_flg = false;
	flash_count = 0;
	disp_flg = true;
}

// �f�X�g���N�^
Player::~Player()
{
	// �摜�̉��
	DeleteGraph(image[PLAYER_IDLE]);
	DeleteGraph(image[PLAYER_RUN]);

	// ���I�������̉��
	delete[] image;
}

// �X�V����
void Player::Update()
{
	// �ړ�����
	Move();
	// �_�ŏ���
	Flashing();
}

// �`�揈��
void Player::Draw() const
{
	if (disp_flg)
	{
		if (speed < -0.001f)		// �ړ��ʂ��}�C�i�X�l�̏ꍇ�A�������ɂ���
		{
			DrawRotaGraphF(this->location.x, this->location.y, 0.5, 0.0, image[PLAYER_RUN], TRUE, FALSE, FALSE);
		}
		else if (speed > 0.001f)	// �ړ��ʂ��v���X�l�̏ꍇ�A�E�����ɂ���
		{
			DrawRotaGraphF(this->location.x, this->location.y, 0.5, 0.0, image[PLAYER_RUN], TRUE, TRUE, FALSE);
		}
		else						// �ҋ@��Ԃɂ���
		{
			DrawRotaGraphF(this->location.x, this->location.y, 0.5, 0.0, image[PLAYER_IDLE], TRUE, FALSE, FALSE);
		}
	}
}

// �ړ�����
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
	if (location.x < (size.x / 2.0f))
	{
		location.x = 0.0f;
		speed = 0.0f;
	}

	// ��ʉE���̈ړ�������݂���
	if (location.x > (500.0f - (size.x / 2.0f)))
	{
		location.x = 500.0f - size.x;
		speed = 0.0f;
	}
}

// �_�ŏ���
void Player::Flashing()
{
	// �_�Ńt���O��true�̎��A�_�ł���B
	if (flash_flg)
	{
		flash_count++;

		if (flash_count % FLASH_TIME == 0)				// �_�Ŏ��Ԃ̏ꍇ
		{
			disp_flg = true;
			flash_flg = false;
		}
		else if (flash_count % FLASH_PERIOD == 0)		// �_�ŊԊu�̏ꍇ
		{
			disp_flg = !disp_flg;
		}
	}
}