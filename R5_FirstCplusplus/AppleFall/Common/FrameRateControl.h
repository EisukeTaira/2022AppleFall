#pragma once

#include "DxLib.h"

#define FRAME_PER_SECONED (60)

class FrameRateControl
{
private:
	int start_time;
	int count;
	float fps;

public:
	FrameRateControl()
	{
		start_time = 0;
		count = 0;
		fps = 0.0f;
	}
	void Update()
	{
		// 1�t���[���ڂȂ玞�����L��
		if (count == 0)
		{
			start_time = GetNowCount();
		}
		// 60�t���[���ڂȂ畽�ς��v�Z
		if (count == FRAME_PER_SECONED)
		{
			int t = GetNowCount();
			fps = 1000.0f / ((t - start_time) / (float)FRAME_PER_SECONED);
			count = 0;
			start_time = t;
		}
		count++;
	}
	void Draw()
	{
		DrawFormatString(10, 10, GetColor(0, 0, 0), "%.2f", fps);
	}
	void Wait()
	{
		int took = GetNowCount() - start_time;	// ������������
		int wait = count * 1000 / FRAME_PER_SECONED - took;	// �҂ׂ�����
		if (wait > 0)
		{
			Sleep(wait);
		}
	}
};

