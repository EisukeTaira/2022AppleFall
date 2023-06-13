#include "GameMainScene.h"
#include "ResultScene.h"
#include "DxLib.h"
#include <math.h>

#define BLOCK_WIDTH		(10)
#define BLOCK_HEIGHT	(10)
#define BLOCK_MAX		(BLOCK_WIDTH * BLOCK_HEIGHT)

// �R���X�g���N�^
GameMainScene::GameMainScene()
{
	bar = new Bar;
	ball = new Ball;
	block_count = BLOCK_MAX;
	block = new Block[BLOCK_MAX];

	for (int i = 0; i < BLOCK_MAX; i++)
	{
		float x = ((i % BLOCK_WIDTH) * block[i].GetSizeX()) + 20.0f;
		float y = ((i / BLOCK_WIDTH) * block[i].GetSizeY() * 1.5f) + 20.0f;
		block[i].SetDispFlg(TRUE);
		block[i].SetLocation(x, y);
	}
}

// �f�X�g���N�^
GameMainScene::~GameMainScene()
{
	delete bar;
	delete ball;
	delete[] block;
}

// �X�V����
void GameMainScene::Update()
{
	// �o�[�X�V����
	bar->Update();
	// �{�[���X�V����
	ball->Update();

	
	if (ball->GetState() == Ball::E_STAY)				// �{�[�����X�e�C��ԂȂ�{�[���Ƀo�[�̈ʒu����������
	{
		ball->SetLocation(bar->GetLocation());
	}
	else if (ball->GetState() == Ball::E_MOVE)			// �{�[���������ԂȂ�o�[�ƃu���b�N�̓����蔻�菈�����s��
	{
		// �o�[�ƃ{�[���̓����蔻����m�F
		if (HitCheck_BB(ball, bar) == TRUE)
		{
			// �������Ă���Ȃ�A���˂�����
			float angle = (18.0f) * (ball->GetLocationX() - bar->GetLocationX()) + 0.6f;
			ball->ChangeDirection(angle);
		}

		// �{�[���ƃu���b�N�̓����蔻��̊m�F
		for (int i = 0; i < BLOCK_MAX; i++)
		{
			if (block[i].GetDispFlg() != TRUE)
			{
				continue;
			}
			if (HitCheck_BB(ball, &block[i]) == TRUE)
			{
				// �������Ă���Ȃ�A���˂�����
				ball->ChangeDirection();
				block[i].SetDispFlg(FALSE);
				block_count--;
			}
		}
	}
	else
	{
		;
	}
}

// �`�揈��
void GameMainScene::Draw() const
{
	// �o�[�̕`�揈��
	bar->Draw();
	// �{�[���̕`�揈��
	ball->Draw();
	// �u���b�N�̕`�揈��
	for (int i = 0; i < BLOCK_MAX; i++)
	{
		block[i].Draw();
	}
}

AbstractScene* GameMainScene::Change()
{
	// �c�@���Ȃ��Ȃ�����A���U���g�ɑJ�ڂ���
	if (ball->GetRemaining_Lives() < 0)
	{
		return nullptr;
	}
	if (block_count <= 0)
	{
		return dynamic_cast<AbstractScene*>(new ResultScene);
	}

	return dynamic_cast<AbstractScene*>(this);
}

// �����蔻�菈��
int GameMainScene::HitCheck_BB(const Ball* ball, const BoxCollision* target)
{
	int ret = FALSE;

	if (ball->GetLocationX() <= (target->GetLocationX() + target->GetSizeX()) && (ball->GetLocationX() + ball->GetSizeX()) >= target->GetLocationX() &&
		ball->GetLocationY() <= (target->GetLocationY() + target->GetSizeY()) && (ball->GetLocationY() + ball->GetSizeY()) >= target->GetLocationY())
	{
		ret = TRUE;
	}

	return ret;
}
