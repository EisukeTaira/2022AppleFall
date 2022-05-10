#pragma once

#include <math.h>
#include "DxLib.h"

#define	N	(60)		// 平均を取るサンプル数
#define	FPS	(60)		// 設定したFPS

class Fps
{
private:
	int start_time;		// 測定開始時間
	int count;			// カウンタ
	float fps;			// fps
public:
	Fps();
	bool Update();
	void Draw();
	void Wait();
};