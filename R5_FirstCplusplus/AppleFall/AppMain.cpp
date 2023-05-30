#include "DxLib.h"
#include "Scene/SceneManager.h"
#include "Scene/TitleScene.h"
#include "Scene/GameMainScene.h"
#include "Scene/RankingScene.h"
#include "Input/InputControl.h"
#include "Common/FrameRateControl.h"

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
	FrameRateControl frc;

	// ���C�����[�v
	while (ProcessMessage() != -1)
	{
		// ��ʂ̏�����
		ClearDrawScreen();

		// ���͋@�\�F�X�V����
		InputControl::Update();		
		
		// �V�[���}�l�[�W���[�F�X�V����
		if (scemeMng.Update() != nullptr)
		{
			// �V�[���}�l�[�W���[�F�`�揈��
			scemeMng.Draw();
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

		// �t���[�����[�g����@�\�F�X�V����
		frc.Update();
		// �t���[�����[�g�ҋ@����
		frc.Wait();

		// ����ʂƕ\��ʂ̌���
		ScreenFlip();
	}

	// DX���C�u�����̏I������
	DxLib_End();

	return 0;
}
