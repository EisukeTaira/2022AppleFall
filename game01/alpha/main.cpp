#include "DxLib.h"
#include "SceneMgr.h"
#include "InputKey.h"
#include "FpsCtrl.h"

// �ϐ��錾
InputKey keyCtrl;
SceneMgr sceneMgr;
Fps f_ctrl;
bool loop_flg;

// �����֐�
bool loop_check();					// ���[�v�`�F�b�N

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	
	loop_flg = true;

	ChangeWindowMode(TRUE);			// �E�B���h�E���[�h�ŋN��
	// DX���C�u��������������
	if (DxLib_Init() == -1)
	{
		return -1;					// �G���[���N�����璼���ɏI��
	}
	// XInput�����̃R���g���[���[�`�F�b�N
	if (CheckJoypadXInput(DX_INPUT_PAD1) == -1)
	{
		return -1;
	}
	SetDrawScreen(DX_SCREEN_BACK);	// ����ʐݒ�
	
	sceneMgr.Initialize();			// ����������

	// �Q�[�����[�v
	while (loop_check())			
	{
		ClearDrawScreen();			// ��ʂ̏�����

		keyCtrl.KeyUpdate();		// �L�[���͍X�V
		sceneMgr.Update();			// �X�V����
		sceneMgr.Draw();			// �`�揈��
		f_ctrl.Update();			// FPS�`�F�b�N�X�V
		f_ctrl.Draw();				// FPS�`��
		DrawFormatString(0, 450, GetColor(255, 255, 255), "%d", keyCtrl.GetAxis(VERTICAL));
		ScreenFlip();				// ����ʂɕύX
		f_ctrl.Wait();				// FPS�̑��x����
	}

	sceneMgr.Finalize();			// �ŏI����

	DxLib_End();					// �c�w���C�u�����g�p�̏I������

	return 0;						// �\�t�g�̏I�� 
}
// ���[�v�`�F�b�N
bool loop_check()
{
	bool ret = true;
	
	// �E�C���h�E�̃��b�Z�[�W����������
	if (ProcessMessage() != 0)
	{
		ret = false;
	}
	// BACK�{�^���������ꂽ
	if (keyCtrl.GetButton(XINPUT_BUTTON_BACK))
	{
		ret = false;
	}
	// ESC�L�[�������ꂽ
	if (CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ret = false;
	}	
	// �O�I�v���Ń��[�v�̌p�����ł��Ȃ�
	if (loop_flg == false)
	{
		ret = false;
	}

	return ret;
}
// ���͏����擾
InputKey* Get_InputKey()
{
	return &keyCtrl;
}
// �O�I�v���Ń��[�v���I��������
void Set_LoopFlg(bool flg)
{
	loop_flg = flg;
}