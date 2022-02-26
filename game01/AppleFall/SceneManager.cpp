#include "SceneManager.h"
#include "InputManager.h"
#include "Title.h"

// �}�N����`

// �^��`

// �ϐ��錾
E_GAME_MODE now_scene;
// �萔�錾

// �����֐��v���g�^�C�v�錾
void scene_switch(void);


// �V�[���}�l�[�W���[����������
int SceneMng_Init(void) {
	int ret = 0;

	now_scene = E_GAME_MODE::TITLE;	// �Q�[�����[�h������
	
	InputMng_Init();					// ���͋@�\����������
	ret = LoadTitleImg();

	return ret;
}
// �V�[���}�l�[�W���[�X�V����
void SceneMng_Updata(void) {
	InputMng_Updata();
	scene_switch();
}
// ���݂̃V�[�����擾
E_GAME_MODE Get_SceneMng_Now(void) {
	return now_scene;
}
// ���̃V�[���ɐ؂�ւ�
void Set_SceneMng_Next(E_GAME_MODE scene) {
	now_scene = scene;
}

// �V�[�����X�C�b�`����
void scene_switch(void) {

	if (GetInputKey(PAD_INPUT_START)) {
		Set_SceneMng_Next(E_GAME_MODE::EXIT);
	}

	switch (now_scene)
	{
		case E_GAME_MODE::OPENING:
			break;
		case E_GAME_MODE::TITLE:
			TitleUpdata();
			break;
		case E_GAME_MODE::GINIT:
			break;
		case E_GAME_MODE::RANKING:
			break;
		case E_GAME_MODE::HELP:
			break;
		case E_GAME_MODE::GEND:
			break;
		case E_GAME_MODE::GMAIN:
			break;
		case E_GAME_MODE::GOVER:
			break;
		case E_GAME_MODE::INRANK:
			break;
		default:
			break;
	}
}