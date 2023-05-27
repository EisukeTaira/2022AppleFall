#include "InputControl.h"
#include "DxLib.h"

int InputControl::x;			// マウスX座標
int InputControl::y;			// マウスY座標
int InputControl::now_input;	// 現在の入力値
int InputControl::old_input;	// 前回の入力値

void InputControl::Update()
{
	// 現在のマウスポインタ座標を取得
	GetMousePoint(&x, &y);

	// 入力値の更新
	old_input = now_input;
	now_input = GetMouseInput();
}

int InputControl::GetMouseLocationX()
{
	return static_cast<const int>(x);
}
int InputControl::GetMouseLocationY()
{
	return static_cast<const int>(y);
}
int InputControl::MouseButtonPressed(const int checkButton)
{
	int ret = FALSE;
	
	if ((now_input & checkButton) != 0)
	{
		ret = TRUE;
	}

	return ret;
}
int InputControl::MouseButtonDown(const int checkButton)
{
	int ret = FALSE;

	if ((~old_input & checkButton) && (now_input & checkButton) != 0)
	{
		ret = TRUE;
	}
	return ret;
}
int InputControl::MouseButtonUp(const int checkButton)
{
	int ret = FALSE;

	if ((old_input & checkButton) && (~now_input & checkButton) != 0)
	{
		ret = TRUE;
	}
	
	return ret;
}