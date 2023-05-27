#pragma once

class InputControl
{
private:
	static int x;			// �}�E�XX���W
	static int y;			// �}�E�XY���W
	static int now_input;	// ���݂̓��͒l
	static int old_input;	// �O��̓��͒l
public:
	static void Update();	// �X�V����

	// �擾�n
	static int GetMouseLocationX();
	static int GetMouseLocationY();
	static int MouseButtonPressed(const int checkButton);
	static int MouseButtonDown(const int checkButton);
	static int MouseButtonUp(const int checkButton);
};

