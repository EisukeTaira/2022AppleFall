#pragma once

#include "AbstractScene.h"

class ResultScene : public AbstractScene
{
public:

private:
	ResultScene();						// �R���X�g���N�^
	~ResultScene();						// �f�X�g���N�^

	AbstractScene* Update() override;	// �X�V����
	void Draw() const override;			// �`�揈��
};

