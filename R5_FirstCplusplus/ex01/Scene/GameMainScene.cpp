#include "GameMainScene.h"
#include "DxLib.h"
#include "../Input/InputControl.h"

#define KILL_Y (750.0f)			// キルＹ座標
#define GENERATE_TIME (30)		// 生成時間

// コンストラクタ
GameMainScene::GameMainScene()
{
	// プレイヤーの生成
	player = new Player;
	
	// リンゴの生成
	for (int i = 0; i < APPLE_MAX; i++)
	{
		apple[i] = nullptr;
	}
	CreateApple();


	generate_count = 0;
	pause_flg = false;
}

//デストラクタ
GameMainScene::~GameMainScene()
{
	delete player;

	for (int i = 0; i < APPLE_MAX; i++)
	{
		delete apple[i];
		apple[i] = nullptr;
	}
}

// 更新処理
void GameMainScene::Update()
{
	// ゲームプレイ停止/再開処理
	if (InputControl::ButtonDown(XINPUT_BUTTON_START))
	{
		if (pause_flg)
		{
			pause_flg = false;
		}
		else
		{
			pause_flg = true;
		}
	}

	// ゲームプレイ停止なら処理を終える
	if (pause_flg)
	{
		return;
	}

	// プレイヤー機能：更新処理
	if (player != nullptr)
	{
		player->Update();
	}	

	// リンゴ機能：更新処理
	for (int i = 0; i < APPLE_MAX; i++)
	{
		if (apple[i] != nullptr)
		{
			apple[i]->Update();

			// キルYに到達したか？
			if (apple[i]->GetLocationY() >= KILL_Y)
			{
				delete apple[i];
				apple[i] = nullptr;
				continue;
			}

			// 当たり判定確認
			if (!(player->GetFlashFlg()) && OnCollision(player, apple[i]))
			{
				AddScore(apple[i]->GetType());
				delete apple[i];
				apple[i] = nullptr;
				continue;
			}			
		}
	}

	generate_count++;

	// 生成処理
	if (generate_count >= GENERATE_TIME)
	{
		generate_count = 0;
		CreateApple();
	}
}

// 描画処理
void GameMainScene::Draw() const
{
	// 背景描画
	DrawBox(0, 0, 640, 480, GetColor(255, 255, 255), TRUE);

	// プレイヤー機能：描画処理
	if (player != nullptr)
	{
		player->Draw();
	}
	
	// リンゴ機能：描画処理
	for (int i = 0; i < APPLE_MAX; i++)
	{
		if (apple[i] != nullptr) 
		{
			apple[i]->Draw();
		}		
	}
}

// リンゴ生成処理
void GameMainScene::CreateApple(void)
{
	float location_x;
	AppleBase::APPLE_TYPE type;
	int generate = 0;
	int active_count = 0;

	// 有効なリンゴの数を取得
	for (int i = 0; i < APPLE_MAX; i++)
	{
		if (apple[i] != nullptr)
		{
			active_count++;
		}
	}

	active_count = (APPLE_MAX - active_count) / 2;

	if (active_count <= 0)
	{
		return;
	}

	// リンゴの生成
	for (int i = 0; i < APPLE_MAX; i++)
	{
		if (apple[i] == nullptr)
		{
			location_x = (float)(rand() % 7) * 60.0f + 60.0f;

			generate = rand() % 100;
			if (generate < 60)
			{
				type = AppleBase::E_RED;
			}
			else if (generate < 85)
			{
				type = AppleBase::E_GREEN;
			}
			else if (generate < 95)
			{
				type = AppleBase::E_YELLOW;
			}
			else
			{
				type = AppleBase::E_POISON;
			}

			switch (type)
			{
				case AppleBase::E_RED:
					apple[i] = new RedApple;
					apple[i]->SetLocation(location_x, -150.0f);
					break;
				case AppleBase::E_GREEN:
					apple[i] = new GreenApple;
					apple[i]->SetLocation(location_x, -150.0f);
					break;
				case AppleBase::E_YELLOW:
					apple[i] = new YellowApple;
					apple[i]->SetLocation(location_x, -150.0f);
					break;
				case AppleBase::E_POISON:
					apple[i] = new PoisonApple;
					apple[i]->SetLocation(location_x, -150.0f);
					break;
				default:
					apple[i] = nullptr;
					break;
			}

			if (active_count-- <= 0)
			{
				break;
			}
		}
	}
}

// 当たり判定処理
bool GameMainScene::OnCollision(const Player* player, const AppleBase* apple)
{
	bool ret = false;
	float fl = 0.0f;
	float distance = 0.0f;
	Vector2 p_pos = {};

	// 四角形の四辺に対して円の半径文だけ足したとき、円が重なっていたら
	if ((apple->GetLocationX() > (player->GetLocationX() - (player->GetSizeX() / 2.0f) - apple->GetRadius())) &&
		(apple->GetLocationX() < (player->GetLocationX() + (player->GetSizeX() / 2.0f) + apple->GetRadius())) &&
		(apple->GetLocationY() > (player->GetLocationY() - (player->GetSizeX() / 2.0f) - apple->GetRadius())) &&
		(apple->GetLocationY() < (player->GetLocationY() + (player->GetSizeY() / 2.0f) + apple->GetRadius())))
	{
		ret = true;
		fl = apple->GetRadius() * apple->GetRadius();

		if (apple->GetLocationX() < (player->GetLocationX() - (player->GetSizeX() / 2.0f)))
		{
			
			if (apple->GetLocationY() < (player->GetLocationY() - (player->GetSizeY() / 2.0f)))
			{
				p_pos.x = player->GetLocationX() - (player->GetSizeX() / 2.0f);
				p_pos.y = player->GetLocationY() - (player->GetSizeY() / 2.0f);
				distance = Distance_Length(apple->GetLocation(), p_pos);
				if (distance >= fl)
				{
						ret = false;
				}
				else
				{
					ret = true;
				}
			}
			else if (apple->GetLocationY() > (player->GetLocationY() + (player->GetSizeY() / 2.0f)))
			{
				p_pos.x = player->GetLocationX() - (player->GetSizeX() / 2.0f);
				p_pos.y = player->GetLocationY() + (player->GetSizeY() / 2.0f);
				distance = Distance_Length(apple->GetLocation(), p_pos);
				if (distance >= fl)
				{
					ret = false;
				}
				else
				{
					ret = true;
				}
			}
			else
			{
				ret = true;
			}
		}
		else if (apple->GetLocationX() > (player->GetLocationX() + (player->GetSizeX() / 2.0f)))
		{
			if (apple->GetLocationY() < (player->GetLocationY() - (player->GetSizeY() / 2.0f)))
			{
				p_pos.x = player->GetLocationX() - (player->GetSizeX() / 2.0f);
				p_pos.y = player->GetLocationY() - (player->GetSizeY() / 2.0f);
				distance = Distance_Length(apple->GetLocation(), p_pos);
				if (distance >= fl)
				{
					ret = false;
				}
				else
				{
					ret = true;
				}
			}
			else if (apple->GetLocationY() > (player->GetLocationY() + (player->GetSizeY() / 2.0f)))
			{
				p_pos.x = player->GetLocationX() + (player->GetSizeX() / 2.0f);
				p_pos.y = player->GetLocationY() + (player->GetSizeY() / 2.0f);
				distance = Distance_Length(apple->GetLocation(), p_pos);
				if (distance >= fl)
				{
					ret = false;
				}
				else
				{
					ret = true;
				}
			}
			else
			{
				ret = true;
			}
		}
		else
		{
			ret = true;
		}
	}

	return ret;
}

// スコア加算処理
void GameMainScene::AddScore(AppleBase::APPLE_TYPE type)
{
	switch (type)
	{
		case AppleBase::E_RED:
			score += 100;
			break;
		case AppleBase::E_GREEN:
			score += 200;
			break;
		case AppleBase::E_YELLOW:
			score += 500;
			break;
		case AppleBase::E_POISON:
			score -= 750;
			//player->SetFlashFlg(true);
			if (score <= 0)
			{
				score = 0;
			}
			break;
		default:
			break;
	}
}
