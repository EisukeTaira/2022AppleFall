#include <stdio.h>
#include "Ranking.h"
#include "DxLib.h"
#include "InputKey.h"

Ranking::Ranking(SceneChanger* changer) : BaseScene(changer)
{
	
}
void Ranking::Initialize()
{
	mImageHandle = LoadGraph("images/Scene_Ranking.png");	// 画像のロード
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
	BaseScene::Draw();						//親クラスの描画メソッドを呼ぶ
	DrawString(0, 0, "ランキング画面です。", GetColor(255, 255, 255));
	DrawString(0, 20, "BACKボタン or Aボタンを押すと\nメニュー画面に戻ります。", GetColor(255, 255, 255));
}
void Ranking::ReadRanking()
{
	FILE* fp;
	fopen_s(&fp, "dat/rankingdata.txt", "r");

	if (fp == NULL) {
		// ゲーム終了
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
		// ゲーム終了
		Set_LoopFlg(false);
		return;
	}


	fclose(fp);
}