#pragma once

#include "AbstractScene.h"

class TitleScene : public AbstractScene
{
private:
	int back_ground;		// 背景画像
	int menu_image;			// メニュー画像
	int cursor_image;		// カーソル画像
	int cursor_number;		// カーソルナンバー

public:
	TitleScene();
	~TitleScene();

	AbstractScene* Update() override;
	void Draw() const override;
};

