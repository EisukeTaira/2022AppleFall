#include "SceneManager.h"
#include "../Input/InputControl.h"
#include "DxLib.h"

SceneManager::SceneManager(AbstractScene* scene)
{
	mScene = scene;
}

SceneManager::~SceneManager()
{
	delete mScene;
}

void SceneManager::Update()
{
	// ���͐���@�\�F�X�V����
	InputControl::Update();
	// �V�[���̍X�V����
	mScene->Update();
}

void SceneManager::Draw() const
{
	// ��ʂ̏�����
	ClearDrawScreen();
	// �V�[���̕`�揈��
	mScene->Draw();
	// ����ʂ̓��e��\��ʂɔ��f
	ScreenFlip();
}

AbstractScene* SceneManager::Change()
{
	AbstractScene* p = mScene->Change();

	if (p != mScene)
	{
		delete mScene;
		mScene = p;
	}

	return mScene;
}
