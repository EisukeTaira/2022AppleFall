#ifndef GAME_MAIN_CONFIG_H__

// ĉzñYĤ
#define	BACK_GROUND		(0)		// wiĉ

#define	BG_POS_X	(640 >> 1)		// wiĉFXÀW
#define	BG_POS_Y	(480 >> 1)		// wiĉFYÀW
#define	BACK_GROUND_EXT	(0.65)		// wiĉgċĤ



// ^è`
typedef void*	T_FUNC;

typedef struct {
	int		x, y;		// ÀW
	int		w, h;		// XP[
	float	angle;		// z²ñ]
	int		img;		// ĉ
	bool	flg;		// true:\Ĥ	false:ñ\Ĥ
	T_FUNC	hitcheck;	// ½èğè`FbN
}T_PLAYER;

#endif // !GAME_MAIN_CONFIG_H__