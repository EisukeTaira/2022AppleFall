#include "ResultScene.h"
#include "DxLib.h"

// �R���X�g���N�^
ResultScene::ResultScene()
{

}

// �f�X�g���N�^
ResultScene::~ResultScene()
{
}

// �X�V����
AbstractScene* ResultScene::Update()
{
	return dynamic_cast<AbstractScene*>(this);
}

// �`�揈��
void ResultScene::Draw() const
{
#ifdef _DEBUG
	DrawFormatString(10, 10, GetColor(255, 255, 255), "���U���g���");
#endif // _DEBUG

}
