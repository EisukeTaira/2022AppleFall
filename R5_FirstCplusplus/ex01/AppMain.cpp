#include "DxLib.h"
#include "Scene/GameMainScene.h"
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
	
	GameMainScene gms;
	FrameRateControl frc;

	// ���C�����[�v
	while (ProcessMessage() != -1)
	{
		// ��ʂ̏�����
		ClearDrawScreen();

		InputControl::Update();

		frc.Update();
		gms.Update();
	
		gms.Draw();

		if (CheckHitKey(KEY_INPUT_ESCAPE) || InputControl::ButtonDown(XINPUT_BUTTON_BACK))
		{
			break;
		}
#if _DEBUG
		frc.Draw();
#endif // _DEBUG	
		frc.Wait();
		// ����ʂƕ\��ʂ̌���
		ScreenFlip();
	}

	// DX���C�u�����̏I������
	DxLib_End();

	return 0;
}
