#include "InputControl.h"
#include "DxLib.h"

int InputControl::x;			// �}�E�XX���W
int InputControl::y;			// �}�E�XY���W
int InputControl::now_input;	// ���݂̓��͒l
int InputControl::old_input;	// �O��̓��͒l

void InputControl::Update()
{
	// ���݂̃}�E�X�|�C���^���W���擾
	GetMousePoint(&x, &y);

	// ���͒l�̍X�V
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