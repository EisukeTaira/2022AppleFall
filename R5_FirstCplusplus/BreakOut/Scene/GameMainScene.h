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
	Block* block;
	int block_count;
public:
	GameMainScene();											// �R���X�g���N�^
	~GameMainScene();											// �f�X�g���N�^

	void Update() override;										// �X�V����
	void Draw() const override;									// �`�揈��
	AbstractScene* Change() override;							// �V�[���J�ڏ���

private:
	int HitCheck_BB(const Ball* ball, const BoxCollision* target);	// �����蔻�菈��
};

