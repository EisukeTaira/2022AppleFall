#include "Menu.h"
#include "DxLib.h"
#include "InputKey.h"



Menu::Menu(SceneChanger* changer) : BaseScene(changer)
{
	menu_cursor = 0;
}
void Menu::Initialize()
{
	mImageHandle = LoadGraph("images/Title.bmp");	// 背景
}
void Menu::Update()
{
	InputKey* key = Get_InputKey();
	
	if (key->GetButtonDown(XINPUT_BUTTON_A))				// Aボタンが押された
	{
		mSceneChanger->ChangeScene((eScene)menu_cursor);
	}
	else if (key->GetButtonDown(XINPUT_BUTTON_DPAD_UP))		// 十字キー(上)が押された
	{
		if (menu_cursor > eScene_Game)
		{
			menu_cursor--;
		}
	}
	else if (key->GetButtonDown(XINPUT_BUTTON_DPAD_DOWN))	// 十字キー(下)が押された
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
		// 何もしない
	}
}
void Menu::Draw()
{
	BaseScene::Draw();						//親クラスの描画メソッドを呼ぶ

	DrawString(0, 0, "タイトル画面です。", GetColor(255, 255, 255));
	DrawTriangle(240, 255 + (menu_cursor * 52), 260, 270 + (menu_cursor * 52), 240, 285 + (menu_cursor * 52), GetColor(255, 0, 0), TRUE);
}
