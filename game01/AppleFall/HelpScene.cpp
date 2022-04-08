#include "DxLib.h"
#include "HelpScene.h"
#include "InputManager.h"

// �ϐ���`
int HelpImg[2];

// �w���v�@�\����������
void Help_Init(void)
{

}
// �w���v�@�\�X�V����
void Help_Update(void)
{
	DrawRotaGraph((640 >> 1), (480 >> 1), 1, 0, HelpImg[0], TRUE);
	DrawRotaGraph(320, 100, 1, 0, HelpImg[1], TRUE);
}
// �w���v�@�\�摜�ǂݍ���
int LoadHelpImg(void)
{
	int ret = 0;

	HelpImg[0] = LoadGraph("../images/bg_natural_mori.png");
	HelpImg[1] = LoadGraph("../images/help/sousa.png");
	for (int i = 0; i < 2; i++) {
		if (HelpImg[i] == -1) {
			return -1;
		}
	}
	return ret;
}
// �w���v�@�\�����ǂݍ���
int LoadHelpSnd(void)
{
	return 0;
}