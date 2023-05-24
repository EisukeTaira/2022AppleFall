#include "TitleScene.h"
#include "GameMainScene.h"
#include "RankingScene.h"
#include "EndingScene.h"
#include "../Input/InputControl.h"
#include "DxLib.h"

enum TITILE_STATE
{
	E_MAIN,
	E_RANKING,
	E_HELP,
	E_ENDING,
	E_STATE_MAX
};

TitleScene::TitleScene()
{
	back_ground = LoadGraph("Resource/images/bg_natural_mori.png");
	menu_image = LoadGraph("Resource/images/title_ui.png");
	cursor_image = LoadGraph("Resource/images/fruit_ringo.png");
	cursor_number = E_MAIN;
}

TitleScene::~TitleScene()
{
	DeleteGraph(back_ground);
	DeleteGraph(menu_image);
	DeleteGraph(cursor_image);
}

AbstractScene* TitleScene::Update()
{
	
	if (InputControl::ButtonDown(XINPUT_BUTTON_B))				// B�{�^�����������ꍇ�ɁA��ʑJ�ڂ��s��
	{
		// �J�ڐ�̌���
		switch (cursor_number)
		{
			case E_MAIN:
				return dynamic_cast<AbstractScene*>(new GameMainScene());
			case E_RANKING:
				return dynamic_cast<AbstractScene*>(new RankingScene());
			case E_HELP:
			case E_ENDING:
				return dynamic_cast<AbstractScene*>(new EndingScene());
			default:
				return nullptr;
		}
	}
	else if (InputControl::ButtonDown(XINPUT_BUTTON_DPAD_UP))	// �\�����{�^���ŃJ�[�\���ʒu�ύX
	{
		if (cursor_number == E_MAIN)
		{
			cursor_number = E_ENDING;
		}
		else
		{
			cursor_number--;
		}
	}
	else if (InputControl::ButtonDown(XINPUT_BUTTON_DPAD_DOWN))	// �\�����{�^���ŃJ�[�\���ʒu�ύX
	{
		if (cursor_number == E_ENDING)
		{
			cursor_number = E_MAIN;
		}
		else
		{
			cursor_number++;
		}
	}
	else if (InputControl::getThumbLY() > 0.5f)					// ���X�e�B�b�N�����ɓ|������
	{
		if (cursor_number == E_MAIN)
		{
			cursor_number = E_ENDING;
		}
		else
		{
			cursor_number--;
		}
	}
	else if (InputControl::getThumbLY() < -0.5f)				// ���X�e�B�b�N�����ɓ|������
	{
		if (cursor_number == E_ENDING)
		{
			cursor_number = E_MAIN;
		}
		else
		{
			cursor_number++;
		}
	}
	else
	{
		// �������Ȃ�
		;
	}

	return this;
}

void TitleScene::Draw() const
{
	// �w�i�`��
	DrawRotaGraph(320, 240, 0.6, 0.0, back_ground, TRUE);

	// �^�C�g�����S�ƃ��j���[��`��
	DrawRotaGraph(320, 240, 1.0, 0.0, menu_image, TRUE);

	// �J�[�\���̕`��
	DrawRotaGraph(365, ((cursor_number * 55) + 285), 0.125, 0.0, cursor_image, TRUE);
	
}
