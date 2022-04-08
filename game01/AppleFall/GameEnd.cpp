#include "DxLib.h"
#include "GameEnd.h"

// �ϐ���`
int EndImg;			// �G���h��ʉ摜

// �G���h�@�\����������
void GEnd_Init(void)
{

}
// �G���h�@�\�X�V����
void GEnd_Update(void)
{
	DrawRotaGraph(320, 240, 0.65, 0, EndImg, TRUE);
	SetFontSize(50);
	DrawFormatString(25, 50, 0x00000000, "Thank you for playing!!!");
}
// �G���h�@�\�摜�Ǎ�����
int LoadGEndImg(void)
{
	int ret = 0;

	// �摜�ǂݍ���
	EndImg = LoadGraph("../images/bg_natural_mori.png");

	if (EndImg == -1)
	{
		ret = -1;
	}
	return ret;
}
// �G���h�@�\�����Ǎ�����
int LoadGEndSnd(void)
{
	return 0;
}