#include "DxLib.h"
#include "Game.h"
#include "InputKey.h"

Game::Game(SceneChanger* changer) : BaseScene(changer)
{

}
void Game::Initialize()
{
	mImageHandle = LoadGraph("images/Scene_Game.png");	// �摜�̃��[�h
}
void Game::Update()
{
	InputKey* key = Get_InputKey();
	if (key->GetButtonDown(XINPUT_BUTTON_START))
	{
		mSceneChanger->ChangeScene(eScene_Menu);
	}
}
void Game::Draw()
{
	BaseScene::Draw();						//�e�N���X�̕`�惁�\�b�h���Ă�
	DrawString(0, 0, "�Q�[����ʂł��B", GetColor(255, 255, 255));
	DrawString(0, 20, "Esc�L�[�������ƃ��j���[��ʂɖ߂�܂��B", GetColor(255, 255, 255));

}