#include "GameMainScene.h"
#include "DxLib.h"
#include "../Input/InputControl.h"

#define KILL_Y			(750.0f)	// �L���x���W
#define GENERATE_TIME	(30)		// ��������
#define TIME_LIMIT		(60 * 28)	// �������ԁi28f��1���Z�j

// �R���X�g���N�^
GameMainScene::GameMainScene()
{
	// �v���C���[�̐���
	player = new Player;
	
	// �����S�̐���
	for (int i = 0; i < APPLE_MAX; i++)
	{
		apple[i] = nullptr;
	}
	CreateApple();

	// �摜�ǂݍ���
	back_ground = LoadGraph("Resource/images/bg_natural_mori.png");
	ui_image[0] = LoadGraph("Resource/images/fruit_ringo.png");
	ui_image[1] = LoadGraph("Resource/images/fruit_ao_ringo.png");
	ui_image[2] = LoadGraph("Resource/images/fruit_apple_yellow.png");

	// UI�`��ϐ��̏�����
	score = 0;
	for (int i = 0; i < 3; i++)
	{
		ui_count[i] = 0;
	}

	// �������Ԃ̏�����
	generate_count = 0;

	// �|�[�Y�t���O�̏�����
	pause_flg = false;

	// �������Ԃ̏�����
	time_limit = TIME_LIMIT;


}

//�f�X�g���N�^
GameMainScene::~GameMainScene()
{
	// �g�p�����摜�̉��
	DeleteGraph(back_ground);
	for (int i = 0; i < 3; i++)
	{
		DeleteGraph(ui_image[i]);
	}	

	// ���I�m�ۂ��������������
	delete player;
	for (int i = 0; i < APPLE_MAX; i++)
	{
		delete apple[i];
		apple[i] = nullptr;
	}
}

// �X�V����
AbstractScene* GameMainScene::Update()
{
	// �Q�[���v���C��~/�ĊJ����
	if (InputControl::ButtonDown(XINPUT_BUTTON_START))
	{
		if (pause_flg)
		{
			pause_flg = false;
		}
		else
		{
			pause_flg = true;
		}
	}

	// �Q�[���v���C��~�Ȃ珈�����I����
	if (pause_flg)
	{
		return this;
	}

	// �v���C���[�@�\�F�X�V����
	if (player != nullptr)
	{
		player->Update();
	}	

	// �����S�@�\�F�X�V����
	for (int i = 0; i < APPLE_MAX; i++)
	{
		if (apple[i] != nullptr)
		{
			apple[i]->Update();

			// �L��Y�ɓ��B�������H
			if (apple[i]->GetLocationY() >= KILL_Y)
			{
				delete apple[i];
				apple[i] = nullptr;
				continue;
			}

			// �����蔻��m�F
			// �v���C���[���_�ŏ�Ԃ̏ꍇ�A�����蔻��̌v�Z���s��Ȃ�
			if (!(player->GetFlashFlg()) && OnCollision(player, apple[i]))
			{
				AddScore(apple[i]->GetType());
				delete apple[i];
				apple[i] = nullptr;
				continue;
			}			
		}
	}
	
	// ��������
	generate_count++;
	if (generate_count >= GENERATE_TIME)
	{
		generate_count = 0;
		CreateApple();
	}

	// �������ԃJ�E���g����
	time_limit--;
	if (time_limit <= 0)
	{
		return nullptr;
	}

	return this;
}

// �`�揈��
void GameMainScene::Draw() const
{
	// �w�i�`��
	DrawRotaGraph(320, 240, 0.6, 0.0, back_ground, TRUE);

	// �v���C���[�@�\�F�`�揈��
	if (player != nullptr)
	{
		player->Draw();
	}
	
	// �����S�@�\�F�`�揈��
	for (int i = 0; i < APPLE_MAX; i++)
	{
		if (apple[i] != nullptr) 
		{
			apple[i]->Draw();
		}		
	}

	// UI�̕`��
	DrawBox(500, 0, 640, 480, GetColor(255, 255, 255), TRUE);

	// �������Ԃ̕`��
	SetFontSize(20);
	DrawFormatString(510, 20, GetColor(0, 0, 0), "��������");
	SetFontSize(75);
	DrawFormatString(525, 50, GetColor(0, 0, 0), "%d", time_limit / 28);
	SetFontSize(20);

	for (int i = 0; i < 3; i++)
	{
		DrawRotaGraph((i * 45 + 520), 300, 0.075, 0.0, ui_image[i], TRUE);
		DrawFormatString((i * 45 + 500), 320, GetColor(0, 0, 0), "[%02d]", ui_count[i]);
	}
}


// �����S��������
void GameMainScene::CreateApple(void)
{
	float location_x;
	AppleBase::APPLE_TYPE type;
	int generate_type = 0;
	int active_count = 0;

	// �L���ȃ����S�̐����擾
	for (int i = 0; i < APPLE_MAX; i++)
	{
		if (apple[i] != nullptr)
		{
			active_count++;
		}
	}

	// �����ł��郊���S�̗ʂ�����
	active_count = (APPLE_MAX - active_count) / 2;

	// �����S�̐���
	for (int i = 0; i < APPLE_MAX; i++)
	{
		// �����ł��郊���S�ʂ�0�����Ȃ琶�����Ȃ�
		if (active_count <= 0)
		{
			break;
		}

		if (apple[i] == nullptr)
		{
			// �������郊���S��X���W������
			location_x = (float)(rand() % 7) * 60.0f + 60.0f;

			// �������郊���S�̎�ނ�����
			generate_type = rand() % 100;
			type = AppleBase::E_POISON;

			// �����S�̎�ނɂ���Đ���
			switch (type)
			{
				case AppleBase::E_RED:
					apple[i] = new RedApple;
					apple[i]->SetLocation(location_x, -150.0f);
					break;
				case AppleBase::E_GREEN:
					apple[i] = new GreenApple;
					apple[i]->SetLocation(location_x, -150.0f);
					break;
				case AppleBase::E_YELLOW:
					apple[i] = new YellowApple;
					apple[i]->SetLocation(location_x, -150.0f);
					break;
				case AppleBase::E_POISON:
					apple[i] = new PoisonApple;
					apple[i]->SetLocation(location_x, -150.0f);
					break;
				default:
					apple[i] = nullptr;
					break;
			}

			// �����ł��郊���S�����炷
			active_count--;
			
		}
	}
}

// �����蔻�菈���i��`�Ɖ~�j
bool GameMainScene::OnCollision(const Player* player, const AppleBase* apple)
{
	bool ret = false;
	float fl = 0.0f;
	float distance = 0.0f;
	Vector2 p_pos = {};

	// �l�p�`�̎l�ӂɑ΂��ĉ~�̔��a�������������Ƃ��A�~���d�Ȃ��Ă�����
	if ((apple->GetLocationX() > (player->GetLocationX() - (player->GetSizeX() / 2.0f) - apple->GetRadius())) &&
		(apple->GetLocationX() < (player->GetLocationX() + (player->GetSizeX() / 2.0f) + apple->GetRadius())) &&
		(apple->GetLocationY() > (player->GetLocationY() - (player->GetSizeX() / 2.0f) - apple->GetRadius())) &&
		(apple->GetLocationY() < (player->GetLocationY() + (player->GetSizeY() / 2.0f) + apple->GetRadius())))
	{
		ret = true;
		fl = apple->GetRadius() * apple->GetRadius();

		if (apple->GetLocationX() < (player->GetLocationX() - (player->GetSizeX() / 2.0f)))
		{
			
			if (apple->GetLocationY() < (player->GetLocationY() - (player->GetSizeY() / 2.0f)))
			{
				p_pos.x = player->GetLocationX() - (player->GetSizeX() / 2.0f);
				p_pos.y = player->GetLocationY() - (player->GetSizeY() / 2.0f);
				distance = Distance_Length(apple->GetLocation(), p_pos);
				if (distance >= fl)
				{
						ret = false;
				}
				else
				{
					ret = true;
				}
			}
			else if (apple->GetLocationY() > (player->GetLocationY() + (player->GetSizeY() / 2.0f)))
			{
				p_pos.x = player->GetLocationX() - (player->GetSizeX() / 2.0f);
				p_pos.y = player->GetLocationY() + (player->GetSizeY() / 2.0f);
				distance = Distance_Length(apple->GetLocation(), p_pos);
				if (distance >= fl)
				{
					ret = false;
				}
				else
				{
					ret = true;
				}
			}
			else
			{
				ret = true;
			}
		}
		else if (apple->GetLocationX() > (player->GetLocationX() + (player->GetSizeX() / 2.0f)))
		{
			if (apple->GetLocationY() < (player->GetLocationY() - (player->GetSizeY() / 2.0f)))
			{
				p_pos.x = player->GetLocationX() - (player->GetSizeX() / 2.0f);
				p_pos.y = player->GetLocationY() - (player->GetSizeY() / 2.0f);
				distance = Distance_Length(apple->GetLocation(), p_pos);
				if (distance >= fl)
				{
					ret = false;
				}
				else
				{
					ret = true;
				}
			}
			else if (apple->GetLocationY() > (player->GetLocationY() + (player->GetSizeY() / 2.0f)))
			{
				p_pos.x = player->GetLocationX() + (player->GetSizeX() / 2.0f);
				p_pos.y = player->GetLocationY() + (player->GetSizeY() / 2.0f);
				distance = Distance_Length(apple->GetLocation(), p_pos);
				if (distance >= fl)
				{
					ret = false;
				}
				else
				{
					ret = true;
				}
			}
			else
			{
				ret = true;
			}
		}
		else
		{
			ret = true;
		}
	}

	return ret;
}

// �X�R�A���Z����
void GameMainScene::AddScore(AppleBase::APPLE_TYPE type)
{
	// �����œn���ꂽ�l�ɂ���ăX�R�A�������Z����
	switch (type)
	{
		case AppleBase::E_RED:
			score += 100;
			ui_count[0]++;
			break;
		case AppleBase::E_GREEN:
			score += 200;
			ui_count[1]++;
			break;
		case AppleBase::E_YELLOW:
			score += 500;
			ui_count[2]++;
			break;
		case AppleBase::E_POISON:
			score -= 750;
			// �X�R�A��0�����ɂȂ�Ȃ��悤�ɂ���B
			if (score <= 0)
			{
				score = 0;
			}
			// �v���C���[�̓_�ŏ������J�n����
			player->SetFlashFlg(true);
			break;
		default:
			break;
	}
}
