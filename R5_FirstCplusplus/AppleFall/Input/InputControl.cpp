#include "DxLib.h"
#include "InputControl.h"

#define MAX_TRIGGER		(255.0f)									// XInput�g���K�[�̍ő���͒l
#define MAX_THUMB		(32767.0f)									// XInput�X�e�B�b�N�̍ő���͒l
#define MIN_THUMB		(-32768.0f)									// XInput�X�e�B�b�N�̍ŏ����͒l
#define BUTTON_PRESS	(1)											// XInput�{�^����������Ă��鎞�̒l
#define BUTTON_RELEASE	(0)											// XInput�{�^����������Ă��鎞�̒l

unsigned char InputControl::oldButtons[XINPUT_BUTTONS_MAX] = {};	// �O�t���[���̃{�^�����͏��
unsigned char InputControl::nowButtons[XINPUT_BUTTONS_MAX] = {};	// ���݃t���[���̃{�^�����͏��
float InputControl::leftTrigger = 0.0f;								// ���g���K�[( 0.0 �` 1.0 )
float InputControl::rightTrigger = 0.0f;							// �E�g���K�[( 0.0 �` 1.0 )	
float InputControl::thumbLX = 0.0f;									// ���X�e�B�b�N�̉����l( -1.0 �` 1.0 )
float InputControl::thumbLY = 0.0f;									// ���X�e�B�b�N�̏c���l( -1.0 �` 1.0 )
float InputControl::thumbRX = 0.0f;									// �E�X�e�B�b�N�̉����l( -1.0 �` 1.0 )
float InputControl::thumbRY = 0.0f;									// �E�X�e�B�b�N�̏c���l( -1.0 �` 1.0 )

int InputControl::CheckButtonIndex(const short checkXButton)
{
	// �����̒l��XInput�{�^�����͒�`�͈͓̔�(0�`15)���ǂ������ׂ�
	int ret = FALSE;
	if (0 <= checkXButton && checkXButton < XINPUT_BUTTONS_MAX)
	{
		ret = TRUE;
	}

	return ret;
}

int InputControl::CheckTriggerThumb(const float checkData, const float threshold, const int isMore)
{
	// ���ׂ�f�[�^�̒l���������l�Ɣ�r�����͂����邩���ׂ�
	int ret = FALSE;
	if (isMore == TRUE)
	{
		if (threshold <= checkData)
		{
			ret = TRUE;
		}
	}
	else
	{
		if (checkData <= threshold)
		{
			ret = TRUE;
		}
	}

	return ret;
}

void InputControl::Update()
{
	// XInput�̓��͏����X�V����
	// ���͏�Ԃ��擾����
	XINPUT_STATE input;
	int errGetJoypadXInputState = GetJoypadXInputState(DX_INPUT_PAD1, &input);
	if (errGetJoypadXInputState == -1)
	{
		// �擾�Ɏ��s�����ꍇ�֐��I��
		return;
	}

	// �{�^�����X�V
	for (int i = 0; i < XINPUT_BUTTONS_MAX; i++)
	{
		oldButtons[i] = nowButtons[i];
		nowButtons[i] = input.Buttons[i];
	}

	// ���g���K�[�̓��͏�������(0 �` 1.0)�ɕϊ�
	int lTrigger = static_cast<int>(input.LeftTrigger);
	leftTrigger = lTrigger / MAX_TRIGGER;

	// �E�g���K�[�̓��͏�������(0 �` 1.0)�ɕϊ�
	int rTrigger = static_cast<int>(input.RightTrigger);
	rightTrigger = rTrigger / MAX_TRIGGER;

	// ���X�e�B�b�N�����̓��͏�������(-1.0 �` 1.0)�ɕϊ�
	if (0 <= input.ThumbLX)
	{
		thumbLX = input.ThumbLX / MAX_THUMB;
	}
	else
	{
		thumbLX = -(input.ThumbLX / MIN_THUMB);
	}

	// ���X�e�B�b�N�c���̓��͏�������(-1.0 �` 1.0)�ɕϊ�
	if (0 <= input.ThumbLY)
	{
		thumbLY = input.ThumbLY / MAX_THUMB;
	}
	else
	{
		thumbLY = -(input.ThumbLY / MIN_THUMB);
	}

	// �E�X�e�B�b�N�����̓��͏�������(-1.0 �` 1.0)�ɕϊ�
	if (0 <= input.ThumbRX)
	{
		thumbRX = input.ThumbRX / MAX_THUMB;
	}
	else
	{
		thumbRX = -(input.ThumbRX / MIN_THUMB);
	}

	// �E�X�e�B�b�N�c���̓��͏�������(-1.0 �` 1.0)�ɕϊ�
	if (0 <= input.ThumbRY)
	{
		thumbRY = input.ThumbRY / MAX_THUMB;
	}
	else
	{
		thumbRY = -(input.ThumbRY / MIN_THUMB);
	}
}

int InputControl::ButtonPressed(const short checkXButton)
{
	// �����ɑΉ�����{�^����������Ă��邩���ׂ�
	int ret = FALSE;
	if (CheckButtonIndex(checkXButton) == TRUE)
	{
		if (nowButtons[checkXButton] == BUTTON_PRESS)
		{
			ret = TRUE;
		}
	}

	return ret;
}

int InputControl::ButtonDown(const short checkXButton)
{
	// �����ɑΉ�����{�^���������ꂽ�u�Ԃ����ׂ�
	int ret = FALSE;
	if (CheckButtonIndex(checkXButton) == TRUE)
	{
		if (oldButtons[checkXButton] == BUTTON_RELEASE
			&& nowButtons[checkXButton] == BUTTON_PRESS)
		{
			ret = TRUE;
		}
	}

	return ret;
}

int InputControl::ButtonReleased(const short checkXButton)
{
	// �����ɑΉ�����{�^����������Ă��邩���ׂ�
	int ret = FALSE;
	if (CheckButtonIndex(checkXButton) == TRUE)
	{
		if (nowButtons[checkXButton] == BUTTON_RELEASE)
		{
			ret = TRUE;
		}
	}

	return ret;
}

int InputControl::ButtonUp(const short checkXButton)
{
	// �����ɑΉ�����{�^���������ꂽ�u�Ԃ����ׂ�
	int ret = FALSE;
	if (CheckButtonIndex(checkXButton) == TRUE)
	{
		if (oldButtons[checkXButton] == BUTTON_PRESS
			&& nowButtons[checkXButton] == BUTTON_RELEASE)
		{
			ret = TRUE;
		}
	}
	return ret;
}

int InputControl::CheckLeftTrigger(const float threshold, const int isMore)
{
	// ���g���K�[�̓��͒l���������l�Ɣ�r�����͂����邩���ׂ�
	int ret = CheckTriggerThumb(leftTrigger, threshold, isMore);
	return ret;
}

int InputControl::CheckRightTrigger(const float threshold, const int isMore)
{
	// �E�g���K�[�̓��͒l���������l�Ɣ�r�����͂����邩���ׂ�
	int ret = CheckTriggerThumb(leftTrigger, threshold, isMore);
	return ret;
}

int InputControl::CheckThumbLX(const float threshold, const int isMore)
{
	// ���X�e�B�b�N�����̓��͒l���������l�Ɣ�r�����͂����邩���ׂ�
	int ret = CheckTriggerThumb(thumbLX, threshold, isMore);
	return ret;
}

int InputControl::CheckThumbLY(const float threshold, const int isMore)
{
	// ���X�e�B�b�N�c���̓��͒l���������l�Ɣ�r�����͂����邩���ׂ�
	int ret = CheckTriggerThumb(thumbLY, threshold, isMore);
	return ret;
}

int InputControl::CheckThumbRX(const float threshold, const int isMore)
{
	// �E�X�e�B�b�N�����̓��͒l���������l�Ɣ�r�����͂����邩���ׂ�
	int ret = CheckTriggerThumb(thumbRX, threshold, isMore);
	return ret;
}

int InputControl::CheckThumbRY(const float threshold, const int isMore)
{
	// �E�X�e�B�b�N�c���̓��͒l���������l�Ɣ�r�����͂����邩���ׂ�
	int ret = CheckTriggerThumb(thumbRY, threshold, isMore);
	return ret;
}

const unsigned char* InputControl::getOldButtons()
{
	// �O�t���[���̃{�^�����͏���Ԃ�
	return reinterpret_cast<const unsigned char*>(oldButtons);
}

const unsigned char* InputControl::getNowButtons()
{
	// ���݂̃t���[���̃{�^�����͏���Ԃ�
	return reinterpret_cast<const unsigned char*>(nowButtons);
}

const float InputControl::getLeftTrigger()
{
	// ���g���K�[�̓��͏���Ԃ�
	return static_cast<const float>(leftTrigger);
}

const float InputControl::getRightTrigger()
{
	// �E�g���K�[�̓��͏���Ԃ�
	return static_cast<const float>(rightTrigger);
}

const float InputControl::getThumbLX()
{
	// ���X�e�B�b�N�����̓��͏���Ԃ�
	return static_cast<const float>(thumbLX);
}

const float InputControl::getThumbLY()
{
	// ���X�e�B�b�N�c���̓��͏���Ԃ�
	return static_cast<const float>(thumbLY);
}

const float InputControl::getThumbRX()
{
	// �E�X�e�B�b�N�����̓��͏���Ԃ�
	return static_cast<const float>(thumbRX);
}

const float InputControl::getThumbRY()
{
	// �E�X�e�B�b�N�c���̓��͏���Ԃ�
	return static_cast<const float>(thumbRY);
}