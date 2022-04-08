#ifndef RANKING_H__

#define NAME_MAX		(10)

typedef struct {
	int rank;
	int score;
	char name[NAME_MAX];
}T_RANKING;

int InputRanking(void);
int ReadRanking(void);
int GraphRanking(void);
#endif