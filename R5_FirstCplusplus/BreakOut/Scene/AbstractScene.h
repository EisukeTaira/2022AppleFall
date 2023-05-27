#pragma once

class AbstractScene
{
public:
	~AbstractScene() {};						// �f�X�g���N�^

	virtual AbstractScene* Update() = 0;		// �X�V����
	virtual void Draw() const = 0;				// �`�揈��
};