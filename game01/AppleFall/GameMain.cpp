#include "GameMain.h"
#include "GMainConfig.h"
#include "InputManager.h"

//�@�}�N����`



// �ϐ���`
int GMainImg[3] = {};	// �摜�p�ϐ�
int GMainSnd[3] = {};	// �摜�p�ϐ�

// �Q�[�����C���@�\����������
void GMainInit(void)
{
	
}
// �Q�[�����C���@�\�X�V����
void GMainUpdate(void)
{
	DrawRotaGraph(BG_POS_X, BG_POS_Y, 0.65, 0, GMainImg[BACK_GROUND], TRUE);
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