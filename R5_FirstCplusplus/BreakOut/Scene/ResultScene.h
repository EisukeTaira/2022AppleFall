#pragma once

#include "AbstractScene.h"

class ResultScene : public AbstractScene
{
private:

public:
	ResultScene();						// �R���X�g���N�^
	~ResultScene();						// �f�X�g���N�^

	void Update() override;				// �X�V����
	void Draw() const override;			// �`�揈��
	AbstractScene* Change() override;	// �X�V����
};

