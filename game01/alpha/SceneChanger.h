#pragma once
typedef enum {
    eScene_Game,    // �Q�[�����
    eScene_Ranking, // �����L���O���
    eScene_End,     // �G���h���
    eScene_Menu,    // ���j���[���
    eScene_Config,  // �ݒ���
    eScene_None,    // ����
} eScene;

//�V�[����ύX���邽�߂̃C���^�[�t�F�C�X�N���X
class SceneChanger {
public:
    virtual ~SceneChanger() = 0;
    virtual void ChangeScene(eScene NextScene) = 0;//�w��V�[���ɕύX����
};