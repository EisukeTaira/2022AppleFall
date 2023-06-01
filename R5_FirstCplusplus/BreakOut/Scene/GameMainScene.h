#pragma once

#include "AbstractScene.h"
#include "../Actor/Bar.h"
#include "../Actor/Ball.h"
#include "../Actor/Block.h"

class GameMainScene : public AbstractScene
{
private:
	Bar* bar;
	Ball* ball;
	Block* block[10];

public:
	GameMainScene();											// �R���X�g���N�^
	~GameMainScene();											// �f�X�g���N�^

	AbstractScene* Update() override;							// �X�V����
	void Draw() const override;									// �`�揈��

private:
	int HitCheck_BB(const Ball* ball, const BoxCollision* b);	// �����蔻�菈��
};

