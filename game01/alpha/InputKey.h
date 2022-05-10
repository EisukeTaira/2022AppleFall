#pragma once

#include "DxLib.h"

#define	BUTTONS_MAX		(16U)
#define L_TRIGGER		(0U)
#define R_TRIGGER		(1U)
#define HORIZONTAL		(0U)
#define	VERTICAL		(1U)
#define HORIZONTAL_R	(2U)
#define VERTICAL_R		(3U)

class InputKey
{
private:
	XINPUT_STATE old_state;
	XINPUT_STATE now_state;
	unsigned char key_flg[BUTTONS_MAX];
public:
	InputKey();
	void KeyUpdate();
	bool GetButton(unsigned char);
	bool GetButtonDown(unsigned char);
	unsigned char GetTrigger(unsigned char);
	short GetAxis(unsigned char);
};

InputKey* Get_InputKey();
void Set_LoopFlg(bool);