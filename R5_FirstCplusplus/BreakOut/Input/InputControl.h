#pragma once

class InputControl
{
private:
	static int x;			// マウスX座標
	static int y;			// マウスY座標
	static int now_input;	// 現在の入力値
	static int old_input;	// 前回の入力値
public:
	static void Update();	// 更新処理

	// 取得系
	static int GetMouseLocationX();
	static int GetMouseLocationY();
	static int MouseButtonPressed(const int checkButton);
	static int MouseButtonDown(const int checkButton);
	static int MouseButtonUp(const int checkButton);
};

