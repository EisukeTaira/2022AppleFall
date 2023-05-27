#include "TitleScene.h"
#include "DxLib.h"
#include "../Input/InputControl.h"
#include "../Scene/GameMainScene.h"
#include "../Scene/EndingScene.h"

// �R���X�g���N�^
TitleScene::TitleScene()
{

}

// �f�X�g���N�^
TitleScene::~TitleScene()
{

}

// �X�V����
AbstractScene* TitleScene::Update()
{
	if (InputControl::MouseButtonDown(MOUSE_INPUT_LEFT))
	{
		return dynamic_cast<AbstractScene*>(new GameMainScene);
	}

	return dynamic_cast<AbstractScene*>(this);
}

// �`�揈��
void TitleScene::Draw() const
{
#ifdef _DEBUG
	DrawFormatString(10, 10, GetColor(255, 255, 255), "�^�C�g�����");
#endif // _DEBUG

	SetFontSize(125);
	DrawFormatString(10, 80, GetColor(255, 0, 0), "Break Out");
	SetFontSize(65);
	DrawFormatString(200, 300, GetColor(255, 255, 255), "Start");
	DrawFormatString(200, 365, GetColor(255, 255, 255), "End");
	SetFontSize(20);
}