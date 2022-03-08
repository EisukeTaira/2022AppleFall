#ifndef GAME_MAIN_CONFIG_H__

// 画像配列添え字
#define	BACK_GROUND		(0)		// 背景画像

#define	BG_POS_X	(640 >> 1)		// 背景画像：X座標
#define	BG_POS_Y	(480 >> 1)		// 背景画像：Y座標
#define	BACK_GROUND_EXT	(0.65)		// 背景画像拡大率



// 型定義
typedef void*	T_FUNC;

typedef struct {
	int		x, y;		// 座標
	int		w, h;		// スケール
	float	angle;		// z軸回転
	int		img;		// 画像
	bool	flg;		// true:表示	false:非表示
	T_FUNC	hitcheck;	// 当たり判定チェック
}T_PLAYER;

#endif // !GAME_MAIN_CONFIG_H__