#include "GameMainScene.h"
#include "DxLib.h"

// コンストラクタ
GameMainScene::GameMainScene()
{
	player = new Player;
	for (int i = 0; i < APPLE_MAX; i++)
	{
		apple[i] = nullptr;
	}
	CreateApple();
	generate_count = 0;
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
	// プレイヤー機能：更新処理
	player->Update();
	// リンゴ機能：更新処理
	for (int i = 0; i < APPLE_MAX; i++)
	{
		if (apple[i] != nullptr)
		{
			apple[i]->Update();
			if (apple[i]->GetLocationY() >= 750.0f)
			{
				delete apple[i];
				apple[i] = nullptr;
			}
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

	if (generate_count >= 25)
	{
		generate_count = 0;
		CreateApple();
	}
}

void GameMainScene::Draw() const
{
	// プレイヤー機能：描画処理
	player->Draw();
	// リンゴ機能：描画処理
	for (int i = 0; i < APPLE_MAX; i++)
	{
		if (apple[i] != nullptr)
		{
			apple[i]->Draw();
		}		
	}
}

void GameMainScene::CreateApple(void)
{
	float location_x;
	AppleBase::APPLE_TYPE type;
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
			type = (AppleBase::APPLE_TYPE)(rand() % (int)AppleBase::E_APPLE_TYPE_MAX);

			switch (type)
			{
				case AppleBase::E_RED:
					apple[i] = new RedApple;
					apple[i]->SetLocation(location_x, -100.0f);
					break;
				case AppleBase::E_GREEN:
					apple[i] = new GreenApple;
					apple[i]->SetLocation(location_x, -100.0f);
					break;
				case AppleBase::E_YELLOW:
					apple[i] = new YellowApple;
					apple[i]->SetLocation(location_x, -100.0f);
					break;
				case AppleBase::E_POISON:
					apple[i] = new PoisonApple;
					apple[i]->SetLocation(location_x, -100.0f);
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

bool GameMainScene::OnCollision(const Player* player, const AppleBase* apple)
{
	bool ret = false;
	float fl = 0.0f;
	float distance = 0.0f;
	Vector2 p_pos = {};

	// 四角形の四辺に対して円の半径文だけ足したとき、円が重なっていたら
	if ((apple->GetLocationX() > (player->GetLocationX() - apple->GetRadius())) &&
		(apple->GetLocationX() < (player->GetLocationX() + player->GetSizeX() - apple->GetRadius())) &&
		(apple->GetLocationY() > (player->GetLocationY() - apple->GetRadius())) &&
		(apple->GetLocationY() < (player->GetLocationY() + player->GetSizeY() - apple->GetRadius())))
	{
		ret = true;
		fl = apple->GetRadius() * apple->GetRadius();

		if (apple->GetLocationX() < player->GetLocationX())
		{
			
			if (apple->GetLocationY() < player->GetLocationY())
			{
				p_pos.x = player->GetLocationX();
				p_pos.y = player->GetLocationY();
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
			else if (apple->GetLocationY() > (player->GetLocationY() + player->GetSizeY()))
			{
				p_pos.x = player->GetLocationX();
				p_pos.y = player->GetLocationY() + player->GetSizeY();
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
		else if (apple->GetLocationX() > (player->GetLocationX() + player->GetSizeX()))
		{
			if (apple->GetLocationY() < player->GetLocationY())
			{
				p_pos.x = player->GetLocationX() + player->GetSizeX();
				p_pos.y = player->GetLocationY();
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
			else if (apple->GetLocationY() > (player->GetLocationY() + player->GetSizeY()))
			{
				p_pos.x = player->GetLocationX() + player->GetSizeX();
				p_pos.y = player->GetLocationY() + player->GetSizeY();
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
		player->SetFlashFlg(true);
		if (score < 0)
		{
			score = 0;
		}
		break;
	default:
		break;
	}
}
