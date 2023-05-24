#include "GameMainScene.h"
#include "DxLib.h"
#include "../Input/InputControl.h"

#define KILL_Y (750.0f)			// �L���x���W
#define GENERATE_TIME (30)		// ��������

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


	generate_count = 0;
	pause_flg = false;
}

//�f�X�g���N�^
GameMainScene::~GameMainScene()
{
	delete player;

	for (int i = 0; i < APPLE_MAX; i++)
	{
		delete apple[i];
		apple[i] = nullptr;
	}
}

// �X�V����
void GameMainScene::Update()
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
		return;
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
			if (!(player->GetFlashFlg()) && OnCollision(player, apple[i]))
			{
				AddScore(apple[i]->GetType());
				delete apple[i];
				apple[i] = nullptr;
				continue;
			}			
		}
	}

	generate_count++;

	// ��������
	if (generate_count >= GENERATE_TIME)
	{
		generate_count = 0;
		CreateApple();
	}
}

// �`�揈��
void GameMainScene::Draw() const
{
	// �w�i�`��
	DrawBox(0, 0, 640, 480, GetColor(255, 255, 255), TRUE);

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
}

// �����S��������
void GameMainScene::CreateApple(void)
{
	float location_x;
	AppleBase::APPLE_TYPE type;
	int generate = 0;
	int active_count = 0;

	// �L���ȃ����S�̐����擾
	for (int i = 0; i < APPLE_MAX; i++)
	{
		if (apple[i] != nullptr)
		{
			active_count++;
		}
	}

	active_count = (APPLE_MAX - active_count) / 2;

	if (active_count <= 0)
	{
		return;
	}

	// �����S�̐���
	for (int i = 0; i < APPLE_MAX; i++)
	{
		if (apple[i] == nullptr)
		{
			location_x = (float)(rand() % 7) * 60.0f + 60.0f;

			generate = rand() % 100;
			if (generate < 60)
			{
				type = AppleBase::E_RED;
			}
			else if (generate < 85)
			{
				type = AppleBase::E_GREEN;
			}
			else if (generate < 95)
			{
				type = AppleBase::E_YELLOW;
			}
			else
			{
				type = AppleBase::E_POISON;
			}

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

			if (active_count-- <= 0)
			{
				break;
			}
		}
	}
}

// �����蔻�菈��
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
	switch (type)
	{
		case AppleBase::E_RED:
			score += 100;
			break;
		case AppleBase::E_GREEN:
			score += 200;
			break;
		case AppleBase::E_YELLOW:
			score += 500;
			break;
		case AppleBase::E_POISON:
			score -= 750;
			//player->SetFlashFlg(true);
			if (score <= 0)
			{
				score = 0;
			}
			break;
		default:
			break;
	}
}
