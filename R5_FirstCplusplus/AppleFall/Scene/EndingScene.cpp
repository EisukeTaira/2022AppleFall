#include "EndingScene.h"
#include "DxLib.h"

#define FINISH_TIME		(60 * 5)	// I—¹ŽžŠÔ

EndingScene::EndingScene()
{
	back_ground = LoadGraph("Resource/images/bg_natural_mori.png");
	wait_time = 0;
}

EndingScene::~EndingScene()
{
	// Žg—p‚µ‚½‰æ‘œ‚ð‰ð•ú
	DeleteGraph(back_ground);
}

AbstractScene* EndingScene::Update()
{

	wait_time++;

	if (wait_time > FINISH_TIME)
	{
		return nullptr;
	}

	return this;
}

void EndingScene::Draw() const
{
	// ”wŒi•`‰æ
	DrawRotaGraph(320, 240, 0.6, 0.0, back_ground, TRUE);

	// Š´ŽÓ‚ð“`‚¦‚é
	SetFontSize(50);
	DrawFormatString(15, 100, GetColor(255, 255, 255), "Thank you for playing!!");
	SetFontSize(20);
}
