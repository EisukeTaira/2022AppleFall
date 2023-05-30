#pragma once

#include "AbstractScene.h"

#define NAME_LENGTH			(10)		// ���O�̒���
#define RANKING_DATA_MAX	(5)			// �����L���O�f�[�^��

class RankingScene : public AbstractScene
{
private:
	enum RANKING_MODE
	{
		E_INPUT_MODE,
		E_DISP_MODE,
	};
	struct RANKING_DATA
	{
		int number;
		char name[NAME_LENGTH];
		int score;
	};
private:
	int back_ground;
	RANKING_MODE mode;
	RANKING_DATA data[RANKING_DATA_MAX];
	bool disp_flg;
	int flash_time;

public:
	RankingScene();
	RankingScene(int score);
	~RankingScene();

	AbstractScene* Update() override;
	void Draw() const override;
private:
	void ReadFile();
	void WriteFile();
	void SortRanking();
	void RankingDisp() const;
	void NameInput();
	void NameInputDisp() const;
};

