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

}
// �w���v�@�\�摜�ǂݍ���
int Help_LoadImg(void)
{
	HelpImg = LoadGraph("../images/ringo.png");
	return 0;
}
// �w���v�@�\�����ǂݍ���
int Help_LoadSmg(void)
{
	return 0;
}