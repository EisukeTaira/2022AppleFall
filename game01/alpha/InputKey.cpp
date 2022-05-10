#include "InputKey.h"

#define DISABLE		(0U)
#define ENABLE		(1U)

InputKey::InputKey()
{	
	for (int i = 0; i < BUTTONS_MAX; i++)
	{
		old_state.Buttons[i] = DISABLE;
		key_flg[i] = DISABLE;
	}
	old_state.LeftTrigger = DISABLE;
	old_state.RightTrigger = DISABLE;
	old_state.ThumbLX = DISABLE;
	old_state.ThumbLY = DISABLE;
	old_state.ThumbRX = DISABLE;
	old_state.ThumbRY = DISABLE;

	now_state = old_state;

	SetJoypadDeadZone(DX_INPUT_PAD1, 0.01);
}
void InputKey::KeyUpdate()
{
	old_state = now_state;
	GetJoypadXInputState(DX_INPUT_PAD1, &now_state);

	for (int i = 0; i < BUTTONS_MAX; i++)
	{
		key_flg[i] = now_state.Buttons[i] & ~old_state.Buttons[i];
	}
	
}
bool InputKey::GetButton(unsigned char button)
{
	bool ret = false;
	if (this->now_state.Buttons[button] == ENABLE)
	{
		ret = true;
	}
	return ret;
}
bool InputKey::GetButtonDown(unsigned char button)
{
	bool ret = false;
	if (this->key_flg[button] == ENABLE)
	{
		ret = true;
	}
	return ret;
}
unsigned char InputKey::GetTrigger(unsigned char mode)
{
	unsigned char ret = 0;

	if (mode == L_TRIGGER)
	{
		ret = now_state.LeftTrigger;
	}
	else if (mode == R_TRIGGER)
	{
		ret = now_state.RightTrigger;
	}
	else
	{
		ret = 0;
	}

	return ret;
}
short InputKey::GetAxis(unsigned char mode)
{
	short ret = 0;

	switch (mode)
	{
		case VERTICAL:
			ret = now_state.ThumbLX;
			break;
		case VERTICAL_R:
			ret = now_state.ThumbRY;
			break;
		case HORIZONTAL:
			ret = now_state.ThumbLX;
			break;
		case HORIZONTAL_R:
			ret = now_state.ThumbRX;
			break;
		default:
			break;
	}

	return ret;
}
