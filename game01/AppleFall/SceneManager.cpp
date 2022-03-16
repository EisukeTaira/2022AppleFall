#include "SceneManager.h"
#include "InputManager.h"
#include "Title.h"
#include "GameMain.h"
#include "HelpScene.h"


// �}�N����`

// �^��`

// �ϐ��錾
E_GAME_MODE now_scene;
// �萔�錾

// �����֐��v���g�^�C�v�錾
void scene_updata_switch(void);


// ����������
int SceneMng_Init(void) {
	int ret = 0;

	now_scene = E_GAME_MODE::TITLE;	// �Q�[�����[�h������
	
	InputMng_Init();					// ���͋@�\����������
	ret += LoadTitleImg();
	ret += LoadGMainImg();
	ret += LoadHelpImg();

	return ret;
}
// �V�[���}�l�[�W���[�X�V����
void SceneMng_Updata(void) {
	InputMng_Updata();
	scene_updata_switch();
}
// ���݂̃V�[�����擾
E_GAME_MODE Get_SceneMng_Now(void) {
	return now_scene;
}
// ���̃V�[���ɐ؂�ւ�
void Set_SceneMng_Next(E_GAME_MODE scene) {
	now_scene = scene;
	switch (now_scene)
	{
		case E_GAME_MODE::OPENING:
			break;
		case E_GAME_MODE::TITLE:
			TitleInit();
			break;
		case E_GAME_MODE::RANKING:
			break;
		case E_GAME_MODE::HELP:
			Help_Init();
			break;
		case E_GAME_MODE::GEND:
			break;
		case E_GAME_MODE::GMAIN:
			GMainInit();
			break;
		case E_GAME_MODE::GOVER:
			break;
		case E_GAME_MODE::INRANK:
			break;
		default:			
			break;
	}
}

// �V�[�����X�C�b�`����
void scene_updata_switch(void) {

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
		case E_GAME_MODE::RANKING:
			break;
		case E_GAME_MODE::HELP:
			Help_Update();
			break;
		case E_GAME_MODE::GEND:
			break;
		case E_GAME_MODE::GMAIN:
			GMainUpdate();
			break;
		case E_GAME_MODE::GOVER:
			break;
		case E_GAME_MODE::INRANK:
			break;
		default:
			Set_SceneMng_Next(E_GAME_MODE::EXIT);
			break;
	}
}