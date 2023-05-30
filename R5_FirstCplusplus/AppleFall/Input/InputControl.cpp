#include "DxLib.h"
#include "InputControl.h"

#define MAX_TRIGGER		(255.0f)									// XInputトリガーの最大入力値
#define MAX_THUMB		(32767.0f)									// XInputスティックの最大入力値
#define MIN_THUMB		(-32768.0f)									// XInputスティックの最小入力値
#define BUTTON_PRESS	(1)											// XInputボタンが押されている時の値
#define BUTTON_RELEASE	(0)											// XInputボタンが離されている時の値

unsigned char InputControl::oldButtons[XINPUT_BUTTONS_MAX] = {};	// 前フレームのボタン入力情報
unsigned char InputControl::nowButtons[XINPUT_BUTTONS_MAX] = {};	// 現在フレームのボタン入力情報
float InputControl::leftTrigger = 0.0f;								// 左トリガー( 0.0 ～ 1.0 )
float InputControl::rightTrigger = 0.0f;							// 右トリガー( 0.0 ～ 1.0 )	
float InputControl::thumbLX = 0.0f;									// 左スティックの横軸値( -1.0 ～ 1.0 )
float InputControl::thumbLY = 0.0f;									// 左スティックの縦軸値( -1.0 ～ 1.0 )
float InputControl::thumbRX = 0.0f;									// 右スティックの横軸値( -1.0 ～ 1.0 )
float InputControl::thumbRY = 0.0f;									// 右スティックの縦軸値( -1.0 ～ 1.0 )

int InputControl::CheckButtonIndex(const short checkXButton)
{
	// 引数の値がXInputボタン入力定義の範囲内(0～15)かどうか調べる
	int ret = FALSE;
	if (0 <= checkXButton && checkXButton < XINPUT_BUTTONS_MAX)
	{
		ret = TRUE;
	}

	return ret;
}

int InputControl::CheckTriggerThumb(const float checkData, const float threshold, const int isMore)
{
	// 調べるデータの値をしきい値と比較し入力があるか調べる
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
	// XInputの入力情報を更新する
	// 入力状態を取得する
	XINPUT_STATE input;
	int errGetJoypadXInputState = GetJoypadXInputState(DX_INPUT_PAD1, &input);
	if (errGetJoypadXInputState == -1)
	{
		// 取得に失敗した場合関数終了
		return;
	}

	// ボタン情報更新
	for (int i = 0; i < XINPUT_BUTTONS_MAX; i++)
	{
		oldButtons[i] = nowButtons[i];
		nowButtons[i] = input.Buttons[i];
	}

	// 左トリガーの入力情報を割合(0 ～ 1.0)に変換
	int lTrigger = static_cast<int>(input.LeftTrigger);
	leftTrigger = lTrigger / MAX_TRIGGER;

	// 右トリガーの入力情報を割合(0 ～ 1.0)に変換
	int rTrigger = static_cast<int>(input.RightTrigger);
	rightTrigger = rTrigger / MAX_TRIGGER;

	// 左スティック横軸の入力情報を割合(-1.0 ～ 1.0)に変換
	if (0 <= input.ThumbLX)
	{
		thumbLX = input.ThumbLX / MAX_THUMB;
	}
	else
	{
		thumbLX = -(input.ThumbLX / MIN_THUMB);
	}

	// 左スティック縦軸の入力情報を割合(-1.0 ～ 1.0)に変換
	if (0 <= input.ThumbLY)
	{
		thumbLY = input.ThumbLY / MAX_THUMB;
	}
	else
	{
		thumbLY = -(input.ThumbLY / MIN_THUMB);
	}

	// 右スティック横軸の入力情報を割合(-1.0 ～ 1.0)に変換
	if (0 <= input.ThumbRX)
	{
		thumbRX = input.ThumbRX / MAX_THUMB;
	}
	else
	{
		thumbRX = -(input.ThumbRX / MIN_THUMB);
	}

	// 右スティック縦軸の入力情報を割合(-1.0 ～ 1.0)に変換
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
	// 引数に対応するボタンが押されているか調べる
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
	// 引数に対応するボタンが押された瞬間か調べる
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
	// 引数に対応するボタンが離されているか調べる
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
	// 引数に対応するボタンが離された瞬間か調べる
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
	// 左トリガーの入力値をしきい値と比較し入力があるか調べる
	int ret = CheckTriggerThumb(leftTrigger, threshold, isMore);
	return ret;
}

int InputControl::CheckRightTrigger(const float threshold, const int isMore)
{
	// 右トリガーの入力値をしきい値と比較し入力があるか調べる
	int ret = CheckTriggerThumb(leftTrigger, threshold, isMore);
	return ret;
}

int InputControl::CheckThumbLX(const float threshold, const int isMore)
{
	// 左スティック横軸の入力値をしきい値と比較し入力があるか調べる
	int ret = CheckTriggerThumb(thumbLX, threshold, isMore);
	return ret;
}

int InputControl::CheckThumbLY(const float threshold, const int isMore)
{
	// 左スティック縦軸の入力値をしきい値と比較し入力があるか調べる
	int ret = CheckTriggerThumb(thumbLY, threshold, isMore);
	return ret;
}

int InputControl::CheckThumbRX(const float threshold, const int isMore)
{
	// 右スティック横軸の入力値をしきい値と比較し入力があるか調べる
	int ret = CheckTriggerThumb(thumbRX, threshold, isMore);
	return ret;
}

int InputControl::CheckThumbRY(const float threshold, const int isMore)
{
	// 右スティック縦軸の入力値をしきい値と比較し入力があるか調べる
	int ret = CheckTriggerThumb(thumbRY, threshold, isMore);
	return ret;
}

const unsigned char* InputControl::getOldButtons()
{
	// 前フレームのボタン入力情報を返す
	return reinterpret_cast<const unsigned char*>(oldButtons);
}

const unsigned char* InputControl::getNowButtons()
{
	// 現在のフレームのボタン入力情報を返す
	return reinterpret_cast<const unsigned char*>(nowButtons);
}

const float InputControl::getLeftTrigger()
{
	// 左トリガーの入力情報を返す
	return static_cast<const float>(leftTrigger);
}

const float InputControl::getRightTrigger()
{
	// 右トリガーの入力情報を返す
	return static_cast<const float>(rightTrigger);
}

const float InputControl::getThumbLX()
{
	// 左スティック横軸の入力情報を返す
	return static_cast<const float>(thumbLX);
}

const float InputControl::getThumbLY()
{
	// 左スティック縦軸の入力情報を返す
	return static_cast<const float>(thumbLY);
}

const float InputControl::getThumbRX()
{
	// 右スティック横軸の入力情報を返す
	return static_cast<const float>(thumbRX);
}

const float InputControl::getThumbRY()
{
	// 右スティック縦軸の入力情報を返す
	return static_cast<const float>(thumbRY);
}