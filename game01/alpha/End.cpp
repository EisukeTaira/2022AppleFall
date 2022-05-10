#include "End.h"
#include "DxLib.h"
#include "InputKey.h"

int wait_time;

End::End(SceneChanger* changer) : BaseScene(changer)
{

}
void End::Initialize()
{
	wait_time = 0;
}
void End::Update()
{
	InputKey* key = Get_InputKey();
	if (key->GetButtonDown(XINPUT_BUTTON_START))
	{
		mSceneChanger->ChangeScene(eScene_Menu);
	}
	wait_time++;
	if (wait_time > (60 * 3))
	{
		Set_LoopFlg(false);
	}

}
void End::Draw()
{
	BaseScene::Draw();
	DrawString(0, 0, "ƒGƒ“ƒh‰æ–Ê‚Å‚·B", GetColor(255, 255, 255));
}