#pragma once

#include "DxLib.h"

#define BUTTON_MAX		(16)
#define STICK_LEFT		(0)
#define STICK_RIGHT		(1)
#define STICK_MAX		(2)
#define TRIGGER_LEFT	(0)
#define TRIGGER_RIGHT	(1)
#define TRIGGER_MAX		(2)

enum INPUT_STATE : unsigned char
{
	E_NONE,
	E_CLICK,
	E_PRESS,
	E_RELEASED,
};

class InputControl
{
private:
	static INPUT_STATE button[BUTTON_MAX];
	static short stick[STICK_MAX];
	static unsigned char trigger[TRIGGER_MAX];

	static INPUT_STATE key_state[256];
public:
	void Update();

	bool GetKey(int key_code);
	bool GetKeyDown(int key_code);
};

