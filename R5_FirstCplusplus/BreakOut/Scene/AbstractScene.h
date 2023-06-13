#pragma once

class AbstractScene
{
public:
	~AbstractScene() {};						// �f�X�g���N�^

	virtual void Update() = 0;					// �X�V����
	virtual void Draw() const = 0;				// �`�揈��
	virtual AbstractScene* Change() = 0;		// �V�[���ύX����
};