#include "DxLib.h"
#include "Input/InputControl.h"
#include "Scene/SceneManager.h"
#include "Scene/TitleScene.h"

// ���C���֐�
int WINAPI WinMain(_In_ HINSTANCE ih, _In_opt_ HINSTANCE ioh, _In_ LPSTR il, _In_ int ii)
{
	// �E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	// DX���C�u�����̏�����
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	// �ϐ���`
	SceneManager scene_manager(new TitleScene);


	// ����ʂ���`����J�n����
	SetDrawScreen(DX_SCREEN_BACK);

	// �Q�[�����[�v
	while (ProcessMessage() != -1 && CheckHitKey(KEY_INPUT_ESCAPE) != TRUE)
	{
		// ��ʂ̏�����
		ClearDrawScreen();
		
		// ���͐���@�\�F�X�V����
		InputControl::Update();

		// �X�V�����̖߂�l��nullptr�����肷��
		if (scene_manager.Update() != nullptr)
		{
			// �`�揈�����s��
			scene_manager.Draw();
		}
		else
		{
			// ���[�v���I������
			break;
		}

		// ����ʂ̓��e��\��ʂɔ��f
		ScreenFlip();
	}

	// DX���C�u�����̏I������
	DxLib_End();

	return 0;
}