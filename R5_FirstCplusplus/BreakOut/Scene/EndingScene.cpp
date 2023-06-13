#include "EndingScene.h"
#include "DxLib.h"

// �R���X�g���N�^
EndingScene::EndingScene()
{
	ending_count = 0;
}

// �f�X�g���N�^
EndingScene::~EndingScene()
{

}

// �X�V����
void EndingScene::Update()
{
	ending_count++;
}

// �`�揈��
void EndingScene::Draw() const
{
#ifdef _DEBUG
	DrawFormatString(10, 10, GetColor(255, 255, 255), "�G���h���");
#endif // _DEBUG

	DrawFormatString(10, 100, GetColor(255, 255, 255), "�Q�[�����I�����܂�");
}

AbstractScene* EndingScene::Change()
{
	if (ending_count > 300)
	{
		return nullptr;
	}

	return dynamic_cast<AbstractScene*>(this);
}
