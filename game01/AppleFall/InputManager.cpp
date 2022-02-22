#include "DxLib.h"
#include "InputManager.h"

// �}�N����`

// �^��`
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

// �ϐ��錾
T_KeyBoard	input_key;				// �L�[�{�[�h���͏��
T_Mouse		input_mouse;			// �}�E�X���͏��

// �萔��`

// �����֐��v���g�^�C�v

// ����������
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
// ���̓L�[�X�V����
void InputMng_Updata(void)
{
	// �L�[�{�[�h���� & �Q�[���p�b�h����
	input_key.oldkey = input_key.nowkey;
	input_key.nowkey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	input_key.keyflg = input_key.nowkey & ~input_key.oldkey;

	// �}�E�X����
	input_mouse.oldkey = input_mouse.nowkey;
	input_mouse.nowkey = GetMouseInput();;
	input_mouse.keyflg = input_mouse.nowkey & ~input_mouse.oldkey;
	//�}�E�X�̈ʒu���擾
	GetMousePoint(&input_mouse.x, &input_mouse.y);
}
// �L�[�{�[�h���͎擾����
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
// �}�E�X���͎擾����
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