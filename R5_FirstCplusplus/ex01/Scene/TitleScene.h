#pragma once

#include "AbstractScene.h"

class TitleScene : public AbstractScene
{
private:
	int back_ground;		// �w�i�摜
	int menu_image;			// ���j���[�摜
	int cursor_image;		// �J�[�\���摜
	int cursor_number;		// �J�[�\���i���o�[

public:
	TitleScene();
	~TitleScene();

	AbstractScene* Update() override;
	void Draw() const override;
};

