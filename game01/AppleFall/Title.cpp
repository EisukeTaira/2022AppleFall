#include "Title.h"
#include "SceneManager.h"
#include "InputManager.h"

//�@�}�N����`
#define	RINGO_EXTRATE	0.125		// �����S�摜�g�嗦

// �^��`

// �ϐ���`
int TitleImg[3] = {};		// �摜�p�ϐ�
int TitleSnd[3] = {};		// �����p�ϐ�
int cursor;
// �萔��`

// �����֐��v���g�^�C�v�錾
void select_cursor(void);	// �J�[�\���ʒu��������


// �^�C�g���@�\����������
void TitleInit(void) {
	cursor = 0;
}
// �^�C�g���@�\�X�V����
void TitleUpdata(void) {
	
	E_GAME_MODE gm = E_GAME_MODE::GEND;

	DrawRotaGraph((640 >> 1), (480 >> 1), (0.65), (0), TitleImg[0], TRUE);
	DrawRotaGraph((640 >> 1), (480 >> 1), (1), (0), TitleImg[1], TRUE);
	select_cursor();
	if (GetInputKeyDown(PAD_INPUT_A)) {
		if (cursor == 0) {
			gm = E_GAME_MODE::GMAIN;
		}
		else if (cursor == 1) {
			gm = E_GAME_MODE::RANKING;
		}
		else if (cursor == 2) {
			gm = E_GAME_MODE::HELP;
		}
		else {
			gm = E_GAME_MODE::GEND;
		}
		Set_SceneMng_Next(gm);
	}
}
// �^�C�g���@�\�摜�ǂݍ���
int LoadTitleImg(void) {
	
	int i = 0;
	
	TitleImg[0] = LoadGraph("../images/bg_natural_mori.png");
	TitleImg[1] = LoadGraph("../images/title_ui.png");
	TitleImg[2] = LoadGraph("../images/fruit_ringo.png");

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
// �J�[�\���ʒu��������
void select_cursor(void) {
	if (GetInputKeyDown(PAD_INPUT_DOWN)) {
		if (++cursor > 3) {
			cursor = 3;
		}
	}
	if (GetInputKeyDown(PAD_INPUT_UP)) {
		if (--cursor < 0) {
			cursor = 0;
		}
	}
	DrawRotaGraph((360), (300 + (cursor * 50)), (0.125), (0), TitleImg[2], TRUE);
}