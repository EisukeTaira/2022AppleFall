#ifndef GAME_MAIN_CONFIG_H__

// �摜�z��Y����
enum {
	APPLE_RED,
	APPLE_YLW,
	APPLE_GRN,
	APPLE_AST,
	BACK_GROUND,
	PLAYER_STD,
	PLAYER_RUN,
	IMG_MAX
};
// �����z��Y����
enum {
	GET_APL,
	SND_MAX
};
// �摜�`��֘A
#define	BG_POS_X		(640 >> 1)	// �w�i�摜�FX���W
#define	BG_POS_Y		(480 >> 1)	// �w�i�摜�FY���W
#define	BG_EXT			(0.65)		// �w�i�摜�g�嗦
#define BG_AREA_X		(500)		// �w�i�`��\�G���AX
#define BG_AREA_Y		(480)		// �w�i�`��\�G���AY

// �����S�֘A
#define	APPLE_MAX		(8)			// �����S�����ő吔
#define TYPE_MAX		(4)			// �I�u�W�F�N�g�^�C�v��
#define	APPLE_STX		(-53)		// �����S�������WX
#define	APPLE_STY		(-53)		// �����S�������WY
#define	APPLE_SCALE		(30)		// �����S�̑傫��
#define	APPLE_EXT		(0.125)		// �����S�摜�g�嗦
#define APPLE_FALLSP	(10)		// �����S�������x
#define	APPLE_CRWD		(70)		// �����S������
// Player�֘A
#define PSTD_POS_X		(250)		// �v���C���[�X�^�[�gX���W
#define PSTD_POS_Y		(435)		// �v���C���[�X�^�[�gY���W
#define PSTD_HEIGHT		(100)		// �v���C���[����
#define PSTD_WIDTH		(40)		// �v���C���[��
#define PMOV_HEIGHT		(80)		// �v���C���[����(�ړ���)
#define PMOV_WIDTH		(60)		// �v���C���[��(�ړ���)
#define PSTD_SPEED		(3)			// �v���C���[�ړ���
#define	PSTD_EXT		(0.25)		// �v���C���[�g�嗦

// UI�֘A
#define	SET_TIME		(6000)	// ��������

// �^��`
typedef struct {
	int x;
	int y;
}T_Vector2;
typedef struct {
	T_Vector2	pos;		// �|�W�V����
	T_Vector2	scale;		// �X�P�[��
	float		angle;		// z����]
	int			img;		// �摜
	bool		flg;		// true:�\��	false:��\��
}T_PLAYER;
typedef struct {
	T_Vector2	pos;		// �|�W�V����
	T_Vector2	scale;		// �X�P�[��
	int			type;		// �I�u�W�F�N�g�^�C�v
	int			img;		// �摜
	bool		flg;		// true:�\��	false:��\��
}T_ENEMY;

#endif // !GAME_MAIN_CONFIG_H__