#pragma once

#include "AbstractScene.h"
#include "../Actor/Bar.h"
#include "../Actor/Ball.h"

class GameMainScene : public AbstractScene
{
private:
	Bar* bar;
	Ball* ball;
public:
	GameMainScene();					// �R���X�g���N�^
	~GameMainScene();					// �f�X�g���N�^

	AbstractScene* Update() override;	// �X�V����
	void Draw() const override;			// �`�揈��
};

