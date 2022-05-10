#include "DxLib.h"
#include "Config.h"
#include "Game.h"
#include "Menu.h"
#include "Ranking.h"
#include "End.h"
#include "SceneMgr.h"

// �R���X�g���N�^
SceneMgr::SceneMgr() : mNextScene(eScene_None)
{
	mScene = (BaseScene*) new Menu(this);
}
// ����������
void SceneMgr::Initialize()
{
	mScene->Initialize();
}
// �I������
void SceneMgr::Finalize()
{
	mScene->Finalize();
}
// �X�V����
void SceneMgr::Update()
{
	if (mNextScene != eScene_None) {						// ���̃V�[�����Z�b�g����Ă�����
		mScene->Finalize();									// ���݂̃V�[���̏I�����������s
		delete mScene;
		switch (mNextScene) {								// �V�[���ɂ���ď����𕪊�
			case eScene_Menu:								// ���̉�ʂ����j���[�Ȃ�
				mScene = (BaseScene*) new Menu(this);		// ���j���[��ʂ̃C���X�^���X�𐶐�����
				break;
			case eScene_Game:
				mScene = (BaseScene*) new Game(this);		// �Q�[����ʂ̃C���X�^���X�𐶐�����
				break;
			case eScene_Config:
				mScene = (BaseScene*) new Config(this);		// �ݒ��ʂ̃C���X�^���X�𐶐�����
				break;
			case eScene_Ranking:
				mScene = (BaseScene*) new Ranking(this);	// �����L���O��ʂ̃C���X�^���X�𐶐�����
				break;
			case eScene_End:
				mScene = (BaseScene*) new End(this);		// �G���h��ʂ̃C���X�^���X�𐶐�����
				break;
			default:
				break;
		}
		mNextScene = eScene_None;    //���̃V�[�������N���A
		mScene->Initialize();    //�V�[����������
	}

	mScene->Update(); //�V�[���̍X�V
}
// �`�揈��
void SceneMgr::Draw()
{
	mScene->Draw();
}
// �V�[���؂�ւ�����
void SceneMgr::ChangeScene(eScene next)
{
	mNextScene = next;
}