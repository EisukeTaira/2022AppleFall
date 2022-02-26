#include "Title.h"
#include "SceneManager.h"
#include "InputManager.h"

//�@�}�N����`
#define	RINGO_EXTRATE	0.125		// �����S�摜�g�嗦

// �^��`

// �ϐ���`
int TitleImg[3];	// �摜�p�ϐ�
int TitleSnd[3];	// �����p�ϐ�

// �萔��`

// �����֐��v���g�^�C�v�錾



// �^�C�g���@�\����������
void TitleInit(void) {
	int i;

	for (i = 0; i < 3; i++) {
		TitleImg[i] = 0;
		TitleSnd[i] = 0;
	}
}
// �^�C�g���@�\�X�V����
void TitleUpdata(void) {
	
	int i;

	for (i = 0; i < 3; i++) {
		DrawRotaGraph(100 * (i + 1), 200, RINGO_EXTRATE, 0,TitleImg[i], TRUE);
	}

	if (GetInputKeyDown(PAD_INPUT_A)) {
		Set_SceneMng_Next(E_GAME_MODE::GINIT);
	}
}
// �^�C�g���@�\�摜�ǂݍ���
int LoadTitleImg(void) {
	
	int i = 0;
	
	TitleImg[0] = LoadGraph("../images/fruit_ringo.png");
	TitleImg[1] = LoadGraph("../images/fruit_apple_yellow.png");
	TitleImg[2] = LoadGraph("../images/fruit_apple_shiwashiwa.png");

	for (i = 0; i < 3; i++) {
		if (TitleImg[i] == -1) {
			return -1;
		}
	}

	return 0;
}
// �^�C�g���@�\�����ǂݍ���
int LoadTitleSnd(void) {
	return 0;
}