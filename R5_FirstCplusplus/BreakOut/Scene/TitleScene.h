#pragma once

#include "AbstractScene.h"

class TitleScene : public AbstractScene
{
private:

public:
	TitleScene();							// �R���X�g���N�^
	~TitleScene();							// �f�X�g���N�^

	void Update() override;					// �X�V����
	void Draw() const override;				// �`�揈��
	AbstractScene* Change() override;		// �V�[���؂�ւ�����
};

