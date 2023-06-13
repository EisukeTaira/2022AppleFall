#include "DxLib.h"
#include "Scene/SceneManager.h"
#include "Scene/TitleScene.h"
#include "Scene/GameMainScene.h"
#include "Scene/RankingScene.h"
#include "Input/InputControl.h"

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
	
	SceneManager scemeMng(dynamic_cast<AbstractScene*>(new TitleScene()));
	
	// ���C�����[�v
	while (ProcessMessage() != -1)
	{
		

		// ���͋@�\�F�X�V����
		InputControl::Update();		
		
		// �V�[���}�l�[�W���[�F�X�V����
		if (scemeMng.Update() != nullptr)
		{
			// ��ʂ̏�����
			ClearDrawScreen();
			// �V�[���}�l�[�W���[�F�`�揈��
			scemeMng.Draw();
			// ����ʂƕ\��ʂ̌���
			ScreenFlip();
		}
		else
		{
			break;
		}
		// ESC�L�[ or BACK�{�^�������͂��ꂽ�Ƃ��A�I��
		if (CheckHitKey(KEY_INPUT_ESCAPE) || InputControl::ButtonDown(XINPUT_BUTTON_BACK))
		{
			break;
		}		
	}

	// DX���C�u�����̏I������
	DxLib_End();

	return 0;
}
