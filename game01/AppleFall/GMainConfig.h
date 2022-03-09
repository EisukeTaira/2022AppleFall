#ifndef GAME_MAIN_CONFIG_H__

// 画像配列添え字
#define	BACK_GROUND		(0)			// 背景画像

#define	BG_POS_X		(640 >> 1)	// 背景画像：X座標
#define	BG_POS_Y		(480 >> 1)	// 背景画像：Y座標
#define	BACK_GROUND_EXT	(0.65)		// 背景画像拡大率

#define	APPLE_MAX		(8)			// リンゴ最大数
#define TYPE_MAX		(3)			// オブジェクトタイプ数
// 型定義
typedef void*	T_FUNC;
typedef struct {
	int x;
	int y;
}T_Vector2;
typedef struct {
	T_Vector2	pos;		// ポジション
	T_Vector2	scale;		// スケール
	float		angle;		// z軸回転
	int			img;		// 画像
	bool		flg;		// true:表示	false:非表示
}T_PLAYER;
typedef struct {
	T_Vector2	pos;		// ポジション
	T_Vector2	scale;		// スケール
	float		angle;		// z軸回転
	int			type;		// オブジェクトタイプ
	int			img;		// 画像
	bool		flg;		// true:表示	false:非表示
	T_FUNC		hitcheck;	// 当たり判定チェック
}T_ENEMY;

#endif // !GAME_MAIN_CONFIG_H__