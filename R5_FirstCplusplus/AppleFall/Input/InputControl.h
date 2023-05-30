#pragma once

#define XINPUT_BUTTONS_MAX	(16)		// XINPUT�{�^���ő吔

class InputControl
{
private:
	static unsigned char oldButtons[XINPUT_BUTTONS_MAX];	// �O�t���[���̃{�^�����͏��
	static unsigned char nowButtons[XINPUT_BUTTONS_MAX];	// ���݃t���[���̃{�^�����͏��
	static float leftTrigger;	// ���g���K�[( 0.0 �` 1.0 )
	static float rightTrigger;	// �E�g���K�[( 0.0 �` 1.0 )	
	static float thumbLX;		// ���X�e�B�b�N�̉����l( -1.0 �` 1.0 )
	static float thumbLY;		// ���X�e�B�b�N�̏c���l( -1.0 �` 1.0 )
	static float thumbRX;		// �E�X�e�B�b�N�̉����l( -1.0 �` 1.0 )
	static float thumbRY;		// �E�X�e�B�b�N�̏c���l( -1.0 �` 1.0 )

private:
	/**
	* static int CheckButtonIndex(const short)
	* �����F
	* �@const short checkXButton�@���ׂ���XInput�{�^���̓��͒�`
	* �߂�l�F
	* �@TRUE�@���Ȃ�
	* �@FLASE�@�G���[
	* �������e�F
	* �@�����̒l��XInput�{�^�����͒�`�͈͓̔�(0�`15)���ǂ������ׂ�
	*/
	static int CheckButtonIndex(const short);

	/**
	* static int CheckTriggerThumb(const float, const float, const int)
	* �����F
	* �@const float checkData�@���ׂ�f�[�^
	* �@const float threshold�@�������l
	* �@const int isMore�F
	* �@�@TRUE�@�������l�ȏ�
	* �@�@FALSE�@�������l�ȉ�
	* �߂�l�F
	* �@TRUE�@���͂���
	* �@FLASE�@���͂Ȃ�
	* �������e�F
	* �@���ׂ�f�[�^�̒l���������l�Ɣ�r�����͂����邩���ׂ�
	*/
	static int CheckTriggerThumb(const float, const float, const int);

public:
	/**
	* static void Update()
	* �����F�Ȃ�
	* �߂�l�F�Ȃ�
	* �������e�F
	* �@XInput�̓��͏����X�V����
	*/
	static void Update();

	/**
	* static int ButtonPressed(const short)
	* �����F
	* �@const short checkXButton�@���ׂ���XInput�{�^���̓��͒�`
	* �߂�l�F
	* �@TRUE�@���͂���
	* �@FLASE�@���͂Ȃ�
	* �������e�F
	* �@�����ɑΉ�����{�^����������Ă��邩���ׂ�
	*/
	static int ButtonPressed(const short);

	/**
	* static int ButtonDown(const short)
	* �����F
	* �@const short checkXButton�@���ׂ���XInput�{�^���̓��͒�`
	* �߂�l�F
	* �@TRUE�@���͂���
	* �@FLASE�@���͂Ȃ�
	* �������e�F
	* �@�����ɑΉ�����{�^���������ꂽ�u�Ԃ����ׂ�
	*/
	static int ButtonDown(const short);

	/**
	* static int ButtonReleased(const short)
	* �����F
	* �@const short checkXButton�@���ׂ���XInput�{�^���̓��͒�`
	* �߂�l�F
	* �@TRUE�@���͂Ȃ�
	* �@FLASE�@���͂���
	* �������e�F
	* �@�����ɑΉ�����{�^����������Ă��邩���ׂ�
	*/
	static int ButtonReleased(const short);

	/**
	* static int ButtonUp(const short)
	* �����F
	* �@const short checkXButton�@���ׂ���XInput�{�^���̓��͒�`
	* �߂�l�F
	* �@TRUE�@���͂Ȃ�
	* �@FLASE�@���͂���
	* �������e�F
	* �@�����ɑΉ�����{�^���������ꂽ�u�Ԃ����ׂ�
	*/
	static int ButtonUp(const short);

	/**
	* static int CheckLeftTrigger(const float, const int)
	* �����F
	* �@const float threshold�@�������l
	* �@const int isMore�F
	* �@�@TRUE�@�������l�ȏ�
	* �@�@FALSE�@�������l�ȉ�
	* �߂�l�F
	* �@TRUE�@���͂���
	* �@FLASE�@���͂Ȃ�
	* �������e�F
	* �@���g���K�[�̓��͒l���������l�Ɣ�r�����͂����邩���ׂ�
	*/
	static int CheckLeftTrigger(const float, const int);

	/**
	* static int CheckRightTrigger(const float, const int)
	* �����F
	* �@const float threshold�@�������l
	* �@const int isMore�F
	* �@�@TRUE�@�������l�ȏ�
	* �@�@FALSE�@�������l�ȉ�
	* �߂�l�F
	* �@TRUE�@���͂���
	* �@FLASE�@���͂Ȃ�
	* �������e�F
	* �@�E�g���K�[�̓��͒l���������l�Ɣ�r�����͂����邩���ׂ�
	*/
	static int CheckRightTrigger(const float, const int);

	/**
	* static int CheckThumbLX(const float, const int)
	* �����F
	* �@const float threshold�@�������l
	* �@const int isMore�F
	* �@�@TRUE�@�������l�ȏ�
	* �@�@FALSE�@�������l�ȉ�
	* �߂�l�F
	* �@TRUE�@���͂���
	* �@FLASE�@���͂Ȃ�
	* �������e�F
	* �@���X�e�B�b�N�����̓��͒l���������l�Ɣ�r�����͂����邩���ׂ�
	*/
	static int CheckThumbLX(const float, const int);

	/**
	* static int CheckThumbLY(const float, const int)
	* �����F
	* �@const float threshold�@�������l
	* �@const int isMore�F
	* �@�@TRUE�@�������l�ȏ�
	* �@�@FALSE�@�������l�ȉ�
	* �߂�l�F
	* �@TRUE�@���͂���
	* �@FLASE�@���͂Ȃ�
	* �������e�F
	* �@���X�e�B�b�N�c���̓��͒l���������l�Ɣ�r�����͂����邩���ׂ�
	*/
	static int CheckThumbLY(const float, const int);

	/**
	* static int CheckThumbRX(const float, const int)
	* �����F
	* �@const float threshold�@�������l
	* �@const int isMore�F
	* �@�@TRUE�@�������l�ȏ�
	* �@�@FALSE�@�������l�ȉ�
	* �߂�l�F
	* �@TRUE�@���͂���
	* �@FLASE�@���͂Ȃ�
	* �������e�F
	* �@�E�X�e�B�b�N�����̓��͒l���������l�Ɣ�r�����͂����邩���ׂ�
	*/
	static int CheckThumbRX(const float, const int);

	/**
	* static int CheckThumbRY(const float, const int)
	* �����F
	* �@const float threshold�@�������l
	* �@const int isMore�F
	* �@�@TRUE�@�������l�ȏ�
	* �@�@FALSE�@�������l�ȉ�
	* �߂�l�F
	* �@TRUE�@���͂���
	* �@FLASE�@���͂Ȃ�
	* �������e�F
	* �@�E�X�e�B�b�N�c���̓��͒l���������l�Ɣ�r�����͂����邩���ׂ�
	*/
	static int CheckThumbRY(const float, const int);

public:
	/**
	* static const unsigned char* getOldButtons()
	* �����F�Ȃ�
	* �߂�l�F
	* �@InputControl::oldButtons�@�O�t���[���̃{�^�����͏��
	* �������e�F
	* �@�O�t���[���̃{�^�����͏���Ԃ�
	*/
	static const unsigned char* getOldButtons();

	/**
	* static const unsigned char* getNowButtons()
	* �����F�Ȃ�
	* �߂�l�F
	* �@InputControl::nowButtons�@���݂̃{�^�����͏��
	* �������e�F
	* �@���݂̃t���[���̃{�^�����͏���Ԃ�
	*/
	static const unsigned char* getNowButtons();

	/**
	* static const float getLeftTrigger()
	* �����F�Ȃ�
	* �߂�l�F
	* �@InputControl::leftTrigger(0.0f�`1.0f)�@���g���K�[�̓��͏��
	* �������e�F
	* �@���g���K�[�̓��͏���Ԃ�
	*/
	static const float getLeftTrigger();

	/**
	* static const float getRightTrigger()
	* �����F�Ȃ�
	* �߂�l�F
	* �@InputControl::rightTrigger(0.0f�`1.0f)�@�E�g���K�[�̓��͏��
	* �������e�F
	* �@�E�g���K�[�̓��͏���Ԃ�
	*/
	static const float getRightTrigger();

	/**
	* static const float getThumbLX()
	* �����F�Ȃ�
	* �߂�l�F
	* �@InputControl::thumbLX(-1.0f�`1.0f)�@���X�e�B�b�N�����̓��͏��
	* �������e�F
	* �@���X�e�B�b�N�����̓��͏���Ԃ�
	*/
	static const float getThumbLX();

	/**
	* static const float getThumbLY()
	* �����F�Ȃ�
	* �߂�l�F
	* �@InputControl::thumbLY(-1.0f�`1.0f)�@���X�e�B�b�N�c���̓��͏��
	* �������e�F
	* �@���X�e�B�b�N�c���̓��͏���Ԃ�
	*/
	static const float getThumbLY();

	/**
	* static const float getThumbRX()
	* �����F�Ȃ�
	* �߂�l�F
	* �@InputControl::thumbRX(-1.0f�`1.0f)�@�E�X�e�B�b�N�����̓��͏��
	* �������e�F
	* �@�E�X�e�B�b�N�����̓��͏���Ԃ�
	*/
	static const float getThumbRX();

	/**
	* static const float getThumbRY()
	* �����F�Ȃ�
	* �߂�l�F
	* �@InputControl::thumbRY(-1.0f�`1.0f)�@�E�X�e�B�b�N�c���̓��͏��
	* �������e�F
	* �@�E�X�e�B�b�N�c���̓��͏���Ԃ�
	*/
	static const float getThumbRY();
};