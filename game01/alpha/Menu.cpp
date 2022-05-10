#include "Menu.h"
#include "DxLib.h"
#include "InputKey.h"



Menu::Menu(SceneChanger* changer) : BaseScene(changer)
{
	menu_cursor = 0;
}
void Menu::Initialize()
{
	mImageHandle = LoadGraph("images/Title.bmp");	// �w�i
}
void Menu::Update()
{
	InputKey* key = Get_InputKey();
	
	if (key->GetButtonDown(XINPUT_BUTTON_A))				// A�{�^���������ꂽ
	{
		mSceneChanger->ChangeScene((eScene)menu_cursor);
	}
	else if (key->GetButtonDown(XINPUT_BUTTON_DPAD_UP))		// �\���L�[(��)�������ꂽ
	{
		if (menu_cursor > eScene_Game)
		{
			menu_cursor--;
		}
	}
	else if (key->GetButtonDown(XINPUT_BUTTON_DPAD_DOWN))	// �\���L�[(��)�������ꂽ
	{
		if (menu_cursor < eScene_End)
		{
			menu_cursor++;
		}
	}
	else if (key->GetAxis(VERTICAL) > 0)
	{
		if (menu_cursor > eScene_Game)
		{
			menu_cursor--;
		}
	}
	else if (key->GetAxis(VERTICAL) < 0)
	{
		if (menu_cursor < eScene_End)
		{
			menu_cursor++;
		}
	}
	else
	{
		// �������Ȃ�
	}
}
void Menu::Draw()
{
	BaseScene::Draw();						//�e�N���X�̕`�惁�\�b�h���Ă�

	DrawString(0, 0, "�^�C�g����ʂł��B", GetColor(255, 255, 255));
	DrawTriangle(240, 255 + (menu_cursor * 52), 260, 270 + (menu_cursor * 52), 240, 285 + (menu_cursor * 52), GetColor(255, 0, 0), TRUE);
}
