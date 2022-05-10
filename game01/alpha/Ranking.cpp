#include <stdio.h>
#include "Ranking.h"
#include "DxLib.h"
#include "InputKey.h"

Ranking::Ranking(SceneChanger* changer) : BaseScene(changer)
{
	
}
void Ranking::Initialize()
{
	mImageHandle = LoadGraph("images/Scene_Ranking.png");	// �摜�̃��[�h
}
void Ranking::Update()
{
	InputKey* key = Get_InputKey();
	if (key->GetButtonDown(XINPUT_BUTTON_START))
	{
		mSceneChanger->ChangeScene(eScene_Menu);
	}
}
void Ranking::Draw()
{
	BaseScene::Draw();						//�e�N���X�̕`�惁�\�b�h���Ă�
	DrawString(0, 0, "�����L���O��ʂł��B", GetColor(255, 255, 255));
	DrawString(0, 20, "BACK�{�^�� or A�{�^����������\n���j���[��ʂɖ߂�܂��B", GetColor(255, 255, 255));
}
void Ranking::ReadRanking()
{
	FILE* fp;
	fopen_s(&fp, "dat/rankingdata.txt", "r");

	if (fp == NULL) {
		// �Q�[���I��
		Set_LoopFlg(false);
		return;
	}


	fclose(fp);
}
void Ranking::SaveRanking()
{
	FILE* fp;
	fopen_s(&fp, "dat/rankingdata.txt", "w");

	if (fp == NULL) {
		// �Q�[���I��
		Set_LoopFlg(false);
		return;
	}


	fclose(fp);
}