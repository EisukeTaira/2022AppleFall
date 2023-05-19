#include "DxLib.h"
#include "Scene/GameMainScene.h"

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

	// ���C�����[�v
	while (ProcessMessage() != -1)
	{
		// ��ʂ̏�����
		ClearDrawScreen();
		
		gms.Update();
		gms.Draw();

		// ����ʂƕ\��ʂ̌���
		ScreenFlip();
	}

	// DX���C�u�����̏I������
	DxLib_End();

	return 0;
}
