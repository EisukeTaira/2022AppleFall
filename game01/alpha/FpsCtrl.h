#pragma once

#include <math.h>
#include "DxLib.h"

#define	N	(60)		// ���ς����T���v����
#define	FPS	(60)		// �ݒ肵��FPS

class Fps
{
private:
	int start_time;		// ����J�n����
	int count;			// �J�E���^
	float fps;			// fps
public:
	Fps();
	bool Update();
	void Draw();
	void Wait();
};