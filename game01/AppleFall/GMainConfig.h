#ifndef GAME_MAIN_CONFIG_H__

// 画像配列添え字
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
// 音源配列添え字
enum {
	GET_APL,
	SND_MAX
};
// 画像描画関連
#define	BG_POS_X		(640 >> 1)	// 背景画像：X座標
#define	BG_POS_Y		(480 >> 1)	// 背景画像：Y座標
#define	BG_EXT			(0.65)		// 背景画像拡大率
#define BG_AREA_X		(500)		// 背景描画可能エリアX
#define BG_AREA_Y		(480)		// 背景描画可能エリアY

// リンゴ関連
#define	APPLE_MAX		(8)			// リンゴ生成最大数
#define TYPE_MAX		(4)			// オブジェクトタイプ数
#define	APPLE_STX		(-53)		// リンゴ初期座標X
#define	APPLE_STY		(-53)		// リンゴ初期座標Y
#define	APPLE_SCALE		(30)		// リンゴの大きさ
#define	APPLE_EXT		(0.125)		// リンゴ画像拡大率
#define APPLE_FALLSP	(10)		// リンゴ落下速度
#define	APPLE_CRWD		(70)		// リンゴ生成幅
// Player関連
#define PSTD_POS_X		(250)		// プレイヤースタートX座標
#define PSTD_POS_Y		(435)		// プレイヤースタートY座標
#define PSTD_HEIGHT		(100)		// プレイヤー高さ
#define PSTD_WIDTH		(40)		// プレイヤー幅
#define PMOV_HEIGHT		(80)		// プレイヤー高さ(移動時)
#define PMOV_WIDTH		(60)		// プレイヤー幅(移動時)
#define PSTD_SPEED		(3)			// プレイヤー移動量
#define	PSTD_EXT		(0.25)		// プレイヤー拡大率

// UI関連
#define	SET_TIME		(6000)	// 制限時間

// 型定義
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
	int			type;		// オブジェクトタイプ
	int			img;		// 画像
	bool		flg;		// true:表示	false:非表示
}T_ENEMY;

#endif // !GAME_MAIN_CONFIG_H__