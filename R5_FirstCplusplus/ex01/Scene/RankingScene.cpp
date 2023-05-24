#include "RankingScene.h"
#include "TitleScene.h"
#include "../Input/InputControl.h"
#include "DxLib.h"

RankingScene::RankingScene()
{
	back_ground = LoadGraph("Resource/images/bg_natural_mori.png");
	ReadFile();
	this->mode = RankingScene::E_DISP_MODE;
	flash_time = 0;
	disp_flg = true;
}

RankingScene::RankingScene(int score)
{
	back_ground = LoadGraph("Resource/images/bg_natural_mori.png");
	ReadFile();
	flash_time = 0;
	disp_flg = true;

	if (score >= data[RANKING_DATA_MAX - 1].score)
	{
		this->mode = RankingScene::E_INPUT_MODE;
		data[RANKING_DATA_MAX - 1].score = score;
	}
	else
	{
		this->mode = RankingScene::E_DISP_MODE;
	}
}

RankingScene::~RankingScene()
{
	DeleteGraph(back_ground);
}

AbstractScene* RankingScene::Update()
{
	switch (mode)
	{
		case RankingScene::E_INPUT_MODE:
			NameInput();
			break;
		case RankingScene::E_DISP_MODE:
			flash_time++;
			if (flash_time % 30 == 0)
			{
				disp_flg = !disp_flg;
			}

			if (InputControl::ButtonDown(XINPUT_BUTTON_B))
			{
				return new TitleScene();
			}
			break;
	}
	return this;
}

void RankingScene::Draw() const
{
	DrawRotaGraph(420, 240, 0.6, 0.0, back_ground, TRUE);
	switch (mode)
	{
		case RankingScene::E_INPUT_MODE:
			NameInputDisp();
			break;
		case RankingScene::E_DISP_MODE:
			RankingDisp();
			break;
	}
}

void RankingScene::ReadFile()
{
	FILE* fp;
	errno_t error = fopen_s(&fp, "Resource/dat/rankingdata.csv", "r");

	if (error != 0)
	{
		OutputDebugString("Resource/dat/rankingdata.csvが開けない");
	}
	else
	{
		for (int i = 0; fscanf_s(fp,"%d,%[^,],%d",&data[i].number,data[i].name, NAME_LENGTH,&data[i].score) != EOF; i++)
		{
			;
		}
		fclose(fp);
	}
}

void RankingScene::WriteFile()
{
	FILE* fp;
	errno_t error = fopen_s(&fp, "Resource/dat/rankingdata.csv", "w");

	if (error != 0)
	{
		OutputDebugString("Resource/dat/rankingdata.csvが開けない");
	}
	else
	{
		fclose(fp);
	}
}

void RankingScene::SortRanking()
{

	WriteFile();
}

void RankingScene::RankingDisp() const
{
	SetFontSize(50);
	DrawFormatString(125, 20, GetColor(255, 255, 255), "** ランキング **");

	DrawBox(10, 75, 630, 375, GetColor(255, 0, 255), TRUE);

	for (int i = 0; i < RANKING_DATA_MAX; i++)
	{
		DrawFormatString(15, ((i * 50) + 100), GetColor(255, 255, 255), "%2d.", data[i].number);
		DrawFormatString(70, ((i * 50) + 100), GetColor(255, 255, 255), "%10s", data[i].name);
		DrawFormatString(350, ((i * 50) + 100), GetColor(255, 255, 255), "%10d", data[i].score);
	}
	SetFontSize(30);
	if (disp_flg)
	{
		DrawFormatString(50, 400, GetColor(255, 255, 255), "--Bボタンを押してタイトルに戻る--");
	}
	SetFontSize(20);
}

void RankingScene::NameInput()
{
}

void RankingScene::NameInputDisp() const
{
}
