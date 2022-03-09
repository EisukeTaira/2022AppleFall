#include "GameMain.h"
#include "GMainConfig.h"
#include "InputManager.h"

//�@�}�N����`



// �ϐ���`
int GMainImg[3] = {};							// �摜�p�ϐ�
int GMainSnd[3] = {};							// �����p�ϐ�
T_PLAYER Player;								// �v���C���[
T_ENEMY Apple[APPLE_MAX] = {};							// �����S						
// �v���g�^�C�v�錾
void stage_background(void);					// �w�i�`�揈��
void stage_ui_ctrl(void);						// UI�`�揈��
int hitcheck(int px, int py, int ex, int ey);	// �����蔻��

// �Q�[�����C���@�\����������
void GMainInit(void)
{
	int i;

	Player.pos.x = 0;
	Player.pos.y = 0;
	Player.scale.x = 0;
	Player.scale.y = 0;
	Player.angle = 0.0f;
	Player.img = 0;
	Player.flg = false;
	for (i = 0; i < APPLE_MAX; i++)
	{
		Apple[i].pos.x = 0;
		Apple[i].pos.y = 0;
		Apple[i].scale.x = 0;
		Apple[i].scale.y = 0;
		Apple[i].angle = 0.0f;
		Apple[i].type = GetRand(TYPE_MAX - 1);
		Apple[i].img = 0;
		Apple[i].flg = false;
		Apple[i].hitcheck = &hitcheck;
	}
}
// �Q�[�����C���@�\�X�V����
void GMainUpdate(void)
{
	stage_background();
	
}
// �Q�[�����C���@�\�摜�ǂݍ��ݏ���
int  LoadGMainImg(void)
{
	int i;

	GMainImg[BACK_GROUND] = LoadGraph("../images/bg_natural_mori.png");

	for (i = 0; i < 3; i++) {
		if (GMainImg[i] == -1) {
			return -1;
		}
	}
	return 0;
}
// �Q�[�����C���@�\�����ǂݍ��ݏ���
int  LoadGMainSnd(void)
{
	return 0;
}
// �w�i�`�揈��
void stage_background(void)
{
	//�`��\�G���A��F��
	SetDrawArea(0, 0, 500, 480);
	// �w�i�摜�̕`��
	DrawRotaGraph(BG_POS_X, BG_POS_Y, 0.65, 0, GMainImg[BACK_GROUND], TRUE);

	//�G���A��߂�
	SetDrawArea(0, 0, 640, 480);
	//	//�X�e�[�W�w�i
	DrawBox(500, 0, 640, 480, 0xFF66FF, TRUE);
}
// UI�`�揈��
void stage_ui_ctrl(void)
{
}
// �����蔻��`�F�b�N
int hitcheck(int px, int py, int ex, int ey)
{
	return FALSE;
}
