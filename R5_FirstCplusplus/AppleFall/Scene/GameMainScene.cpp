#include "GameMainScene.h"
#include "DxLib.h"
#include "../Input/InputControl.h"

#define KILL_Y			(750.0f)	// キルＹ座標
#define GENERATE_TIME	(30)		// 生成時間
#define TIME_LIMIT		(60 * 28)	// 制限時間（28fで1減算）

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

	// 画像読み込み
	back_ground = LoadGraph("Resource/images/bg_natural_mori.png");
	ui_image[0] = LoadGraph("Resource/images/fruit_ringo.png");
	ui_image[1] = LoadGraph("Resource/images/fruit_ao_ringo.png");
	ui_image[2] = LoadGraph("Resource/images/fruit_apple_yellow.png");

	// UI描画変数の初期化
	score = 0;
	for (int i = 0; i < 3; i++)
	{
		ui_count[i] = 0;
	}

	// 生成時間の初期化
	generate_count = 0;

	// ポーズフラグの初期化
	pause_flg = false;

	// 制限時間の初期化
	time_limit = TIME_LIMIT;


}

//デストラクタ
GameMainScene::~GameMainScene()
{
	// 使用した画像の解放
	DeleteGraph(back_ground);
	for (int i = 0; i < 3; i++)
	{
		DeleteGraph(ui_image[i]);
	}	

	// 動的確保したメモリを解放
	delete player;
	for (int i = 0; i < APPLE_MAX; i++)
	{
		delete apple[i];
		apple[i] = nullptr;
	}
}

// 更新処理
AbstractScene* GameMainScene::Update()
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
		return this;
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
			// プレイヤーが点滅状態の場合、当たり判定の計算を行わない
			if (!(player->GetFlashFlg()) && OnCollision(player, apple[i]))
			{
				AddScore(apple[i]->GetType());
				delete apple[i];
				apple[i] = nullptr;
				continue;
			}			
		}
	}
	
	// 生成処理
	generate_count++;
	if (generate_count >= GENERATE_TIME)
	{
		generate_count = 0;
		CreateApple();
	}

	// 制限時間カウント処理
	time_limit--;
	if (time_limit <= 0)
	{
		return nullptr;
	}

	return this;
}

// 描画処理
void GameMainScene::Draw() const
{
	// 背景描画
	DrawRotaGraph(320, 240, 0.6, 0.0, back_ground, TRUE);

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

	// UIの描画
	DrawBox(500, 0, 640, 480, GetColor(255, 255, 255), TRUE);

	// 制限時間の描画
	SetFontSize(20);
	DrawFormatString(510, 20, GetColor(0, 0, 0), "制限時間");
	SetFontSize(75);
	DrawFormatString(525, 50, GetColor(0, 0, 0), "%d", time_limit / 28);
	SetFontSize(20);

	for (int i = 0; i < 3; i++)
	{
		DrawRotaGraph((i * 45 + 520), 300, 0.075, 0.0, ui_image[i], TRUE);
		DrawFormatString((i * 45 + 500), 320, GetColor(0, 0, 0), "[%02d]", ui_count[i]);
	}
}


// リンゴ生成処理
void GameMainScene::CreateApple(void)
{
	float location_x;
	AppleBase::APPLE_TYPE type;
	int generate_type = 0;
	int active_count = 0;

	// 有効なリンゴの数を取得
	for (int i = 0; i < APPLE_MAX; i++)
	{
		if (apple[i] != nullptr)
		{
			active_count++;
		}
	}

	// 生成できるリンゴの量を決定
	active_count = (APPLE_MAX - active_count) / 2;

	// リンゴの生成
	for (int i = 0; i < APPLE_MAX; i++)
	{
		// 生成できるリンゴ量が0未満なら生成しない
		if (active_count <= 0)
		{
			break;
		}

		if (apple[i] == nullptr)
		{
			// 生成するリンゴのX座標を決定
			location_x = (float)(rand() % 7) * 60.0f + 60.0f;

			// 生成するリンゴの種類を決定
			generate_type = rand() % 100;
			type = AppleBase::E_POISON;

			// リンゴの種類によって生成
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

			// 生成できるリンゴを減らす
			active_count--;
			
		}
	}
}

// 当たり判定処理（矩形と円）
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
	// 引数で渡された値によってスコアを加減算する
	switch (type)
	{
		case AppleBase::E_RED:
			score += 100;
			ui_count[0]++;
			break;
		case AppleBase::E_GREEN:
			score += 200;
			ui_count[1]++;
			break;
		case AppleBase::E_YELLOW:
			score += 500;
			ui_count[2]++;
			break;
		case AppleBase::E_POISON:
			score -= 750;
			// スコアが0未満にならないようにする。
			if (score <= 0)
			{
				score = 0;
			}
			// プレイヤーの点滅処理を開始する
			player->SetFlashFlg(true);
			break;
		default:
			break;
	}
}
