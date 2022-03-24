#include <stdio.h>
#include "Ranking.h"

#define RANKING_DATA	(5)

T_RANKING RankData[RANKING_DATA];

int save_ranking(void);
void sort_ranking(void);

int GraphRanking(void)
{
}
int InputRanking(void)
{
	if (true) {
		sort_ranking();
		save_ranking();
	}
}

int ReadRanking(void)
{
	FILE* fp;
	int i;

	fopen_s(&fp, "../dat/rankingdata.txt", "r");

	if (fp == NULL) {
		return -1;
	}
	
	for (i = 0; i < RANKING_DATA; i++)
	{
		fscanf_s(fp, "%2d %-10s %10d", &RankData[i].rank, RankData[i].name, NAME_MAX, &RankData[i].score);
	}

	fclose(fp);
	return 0;
}

int save_ranking(void)
{
	FILE* fp;
	int i;

	fopen_s(&fp, "../dat/rankingdata.txt", "w");

	if (fp == NULL) {
		return -1;
	}

	for (i = 0; i < RANKING_DATA; i++)
	{
		fprintf(fp, "%2d %10s %10d", RankData[i].rank, RankData[i].name, RankData[i].score);
	}
	fclose(fp);
	return 0;
}

void sort_ranking(void)
{
	int i, j;
	T_RANKING work;

	// 選択法ソート
	for (i = 0; i < 4; i++)
	{
		for (j = i + 1; j < 5; j++)
		{
			if (RankData[i].score <= RankData[j].score)
			{
				work = RankData[i];
				RankData[i] = RankData[j];
				RankData[j] = work;
			}
		}
	}

	// 順位付け
	for (i = 0; i < 5; i++)
	{
		RankData[i].rank = 1;
	}
	// 得点が同じ場合は、同じ順位とする
	// 同順位があった場合の次の順位はデータ個数が加算された順位とする
	for (i = 0; i < 4; i++)
	{
		for (j = i + 1; j < 5; j++)
		{
			if (RankData[i].score > RankData[j].score)
			{
				RankData[j].rank++;
			}
		}
	}
}