#include "GameMainScene.h"
#include "ResultScene.h"
#include "DxLib.h"

// �R���X�g���N�^
GameMainScene::GameMainScene()
{
	bar = new Bar;
	ball = new Ball(bar->GetLocation());
}

// �f�X�g���N�^
GameMainScene::~GameMainScene()
{
	delete bar;
	delete ball;
}

// �X�V����
AbstractScene* GameMainScene::Update()
{
	bar->Update();

	if (ball->GetState() == Ball::E_STAY)
	{
		ball->SetLocation(bar->GetLocation());
	}
	ball->Update();

	if (ball->GetRemaining_Lives() < 0)
	{
		return dynamic_cast<AbstractScene*>(new ResultScene);
	}

	return dynamic_cast<AbstractScene*>(this);
}

// �`�揈��
void GameMainScene::Draw() const
{
#ifdef _DEBUG
	DrawFormatString(10, 10, GetColor(255, 255, 255), "�Q�[�����C�����");
#endif // _DEBUG
	bar->Draw();
	ball->Draw();
}