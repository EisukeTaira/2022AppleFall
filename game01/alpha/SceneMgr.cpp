#include "DxLib.h"
#include "Config.h"
#include "Game.h"
#include "Menu.h"
#include "Ranking.h"
#include "End.h"
#include "SceneMgr.h"

// コンストラクタ
SceneMgr::SceneMgr() : mNextScene(eScene_None)
{
	mScene = (BaseScene*) new Menu(this);
}
// 初期化処理
void SceneMgr::Initialize()
{
	mScene->Initialize();
}
// 終了処理
void SceneMgr::Finalize()
{
	mScene->Finalize();
}
// 更新処理
void SceneMgr::Update()
{
	if (mNextScene != eScene_None) {						// 次のシーンがセットされていたら
		mScene->Finalize();									// 現在のシーンの終了処理を実行
		delete mScene;
		switch (mNextScene) {								// シーンによって処理を分岐
			case eScene_Menu:								// 次の画面がメニューなら
				mScene = (BaseScene*) new Menu(this);		// メニュー画面のインスタンスを生成する
				break;
			case eScene_Game:
				mScene = (BaseScene*) new Game(this);		// ゲーム画面のインスタンスを生成する
				break;
			case eScene_Config:
				mScene = (BaseScene*) new Config(this);		// 設定画面のインスタンスを生成する
				break;
			case eScene_Ranking:
				mScene = (BaseScene*) new Ranking(this);	// ランキング画面のインスタンスを生成する
				break;
			case eScene_End:
				mScene = (BaseScene*) new End(this);		// エンド画面のインスタンスを生成する
				break;
			default:
				break;
		}
		mNextScene = eScene_None;    //次のシーン情報をクリア
		mScene->Initialize();    //シーンを初期化
	}

	mScene->Update(); //シーンの更新
}
// 描画処理
void SceneMgr::Draw()
{
	mScene->Draw();
}
// シーン切り替え処理
void SceneMgr::ChangeScene(eScene next)
{
	mNextScene = next;
}