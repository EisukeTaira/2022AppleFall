#ifndef GAME_MAIN_CONFIG_H__

// �摜�z��Y����
#define	BACK_GROUND		(0)		// �w�i�摜

#define	BG_POS_X	(640 >> 1)		// �w�i�摜�FX���W
#define	BG_POS_Y	(480 >> 1)		// �w�i�摜�FY���W
#define	BACK_GROUND_EXT	(0.65)		// �w�i�摜�g�嗦



// �^��`
typedef void*	T_FUNC;

typedef struct {
	int		x, y;		// ���W
	int		w, h;		// �X�P�[��
	float	angle;		// z����]
	int		img;		// �摜
	bool	flg;		// true:�\��	false:��\��
	T_FUNC	hitcheck;	// �����蔻��`�F�b�N
}T_PLAYER;

#endif // !GAME_MAIN_CONFIG_H__