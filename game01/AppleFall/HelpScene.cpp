#include "DxLib.h"
#include "HelpScene.h"
#include "InputManager.h"

// �ϐ���`
int HelpImg;

// �w���v�@�\����������
void Help_Init(void)
{

}
// �w���v�@�\�X�V����
void Help_Update(void)
{
	DrawRotaGraph((640 >> 1), (480 >> 1), 1, 1, HelpImg, TRUE);
}
// �w���v�@�\�摜�ǂݍ���
int LoadHelpImg(void)
{
	int ret = 0;

	HelpImg = LoadGraph("../images/fruit_ringo.png");
	if (HelpImg == -1) {
		ret = -1;
	}
	return ret;
}
// �w���v�@�\�����ǂݍ���
int LoadHelpSnd(void)
{
	return 0;
}