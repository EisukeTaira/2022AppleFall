#include "FpsCtrl.h"

Fps::Fps()
{
	start_time = 0;
	count = 0;
	fps = 0.0f;
}

bool Fps::Update()
{
	// 1�t���[���ڂȂ玞�����L��
	if (count == 0)
	{
		start_time = GetNowCount();
	}
	// 60�t���[���ڂȂ畽�ς��v�Z
	if (count == N)
	{
		int t = GetNowCount();
		fps = 1000.f / ((t - start_time) / (float)N);
		count = 0;
		start_time = t;
	}
	count++;
	return true;
}
void Fps::Draw()
{
	DrawFormatString(0, 400, GetColor(255, 255, 255), "%.2f", fps);
}

void Fps::Wait()
{
	int took = GetNowCount() - start_time;	// ������������
	int wait = count * 1000 / FPS - took;	// �҂ׂ�����
	if (wait > 0)
	{
		Sleep(wait);
	}
}