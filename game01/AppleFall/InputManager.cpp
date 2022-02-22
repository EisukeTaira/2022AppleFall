#include "DxLib.h"
#include "InputManager.h"

// マクロ定義

// 型定義
typedef struct {
	int nowkey;
	int keyflg;
	int oldkey;
}T_KeyBoard;
typedef struct {
	int nowkey;
	int keyflg;
	int oldkey;
	int x;
	int y;
}T_Mouse;

// 変数宣言
T_KeyBoard	input_key;				// キーボード入力状態
T_Mouse		input_mouse;			// マウス入力状態

// 定数定義

// 内部関数プロトタイプ

// 初期化処理
void InputMng_Init(void) {
	input_key.keyflg = 0;
	input_key.nowkey = 0;
	input_key.oldkey = 0;
	input_mouse.keyflg = 0;
	input_mouse.nowkey = 0;
	input_mouse.oldkey = 0;
	input_mouse.x = 0;
	input_mouse.y = 0;
}
// 入力キー更新処理
void InputMng_Updata(void)
{
	// キーボード入力 & ゲームパッド入力
	input_key.oldkey = input_key.nowkey;
	input_key.nowkey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	input_key.keyflg = input_key.nowkey & ~input_key.oldkey;

	// マウス入力
	input_mouse.oldkey = input_mouse.nowkey;
	input_mouse.nowkey = GetMouseInput();;
	input_mouse.keyflg = input_mouse.nowkey & ~input_mouse.oldkey;
	//マウスの位置を取得
	GetMousePoint(&input_mouse.x, &input_mouse.y);
}
// キーボード入力取得処理
bool GetInputKey(int key) {
	bool ret = false;

	if ((key & input_key.nowkey) != 0) {
		ret = true;
	}

	return ret;
}
bool GetInputKeyDown(int key) {
	bool ret = false;

	if ((key & input_key.keyflg) != 0) {
		ret = true;
	}

	return ret;
}
// マウス入力取得処理
bool GetInputMouse(int key) {
	bool ret = false;

	if ((key & input_mouse.nowkey) != 0) {
		ret = true;
	}

	return ret;
}
bool GetInputMouseDown(int key) {
	bool ret = false;

	if ((key & input_mouse.keyflg) != 0) {
		ret = true;
	}

	return ret;
}
int GetMouseX(void) {
	return input_mouse.x;
}
int GetMouseY(void) {
	return input_mouse.y;
}