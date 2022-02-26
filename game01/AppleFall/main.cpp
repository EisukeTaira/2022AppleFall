#include "DxLib.h"
#include "SceneManager.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1) {	// DX���C�u��������������
		return -1;				// ���������s
	}
	SetDrawScreen(DX_SCREEN_BACK);
	SetGraphMode(640, 480, 32);
	
	if (SceneMng_Init() == -1) {
		return -1;
	}

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && Get_SceneMng_Now() != E_GAME_MODE::EXIT) {
		SceneMng_Updata();
	}

	DxLib_End();	// DX���C�u�����g�p�̏I������

	return 0;		// �\�t�g�̏I��
}