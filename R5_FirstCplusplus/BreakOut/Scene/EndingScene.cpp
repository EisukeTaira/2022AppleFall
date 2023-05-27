#include "EndingScene.h"
#include "DxLib.h"

// �R���X�g���N�^
EndingScene::EndingScene()
{

}

// �f�X�g���N�^
EndingScene::~EndingScene()
{

}

// �X�V����
AbstractScene* EndingScene::Update()
{
	return dynamic_cast<AbstractScene*>(this);
}

// �`�揈��
void EndingScene::Draw() const
{
#ifdef _DEBUG
	DrawFormatString(10, 10, GetColor(255, 255, 255), "�G���h���");
#endif // _DEBUG
}