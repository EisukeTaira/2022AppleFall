#include "SceneManager.h"
#include "InputManager.h"

// �}�N����`

// �^��`

// �ϐ��錾
E_GAME_MODE now_scene;
// �萔�錾

// �����֐��v���g�^�C�v�錾

// �V�[���}�l�[�W���[����������
int SceneMng_Init(void) {
	int ret = 0;

	now_scene = E_GAME_MODE::OPENING;	// �Q�[�����[�h������
	
	InputMng_Init();					// ���͋@�\����������


	return ret;
}
// �V�[���}�l�[�W���[�X�V����
void SceneMng_Updata(void) {
	InputMng_Updata();
}
E_GAME_MODE Get_SceneMng_Now(void) {
	return now_scene;
}
void Set_SceneMng_Next(E_GAME_MODE scene) {
	now_scene = scene;
}