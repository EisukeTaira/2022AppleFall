#include "GameMainScene.h"
#include "DxLib.h"

GameMainScene::GameMainScene()
{
	player = new Player;
	for (AppleBase* x : apple)
	{
		x = nullptr;
	}
}

GameMainScene::~GameMainScene()
{
	delete player;

	for (AppleBase* x : apple)
	{
		delete x;
	}
}

void GameMainScene::Update()
{
	player->Update();
	for (AppleBase* x : apple)
	{
		if (x == nullptr)
		{
			continue;
		}
		x->Update();
	}
}

void GameMainScene::Draw() const
{
	player->Draw();
	for (AppleBase* x : apple)
	{
		x->Draw();
	}
}
