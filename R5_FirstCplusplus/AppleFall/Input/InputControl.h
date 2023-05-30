#pragma once

#define XINPUT_BUTTONS_MAX	(16)		// XINPUTボタン最大数

class InputControl
{
private:
	static unsigned char oldButtons[XINPUT_BUTTONS_MAX];	// 前フレームのボタン入力情報
	static unsigned char nowButtons[XINPUT_BUTTONS_MAX];	// 現在フレームのボタン入力情報
	static float leftTrigger;	// 左トリガー( 0.0 ～ 1.0 )
	static float rightTrigger;	// 右トリガー( 0.0 ～ 1.0 )	
	static float thumbLX;		// 左スティックの横軸値( -1.0 ～ 1.0 )
	static float thumbLY;		// 左スティックの縦軸値( -1.0 ～ 1.0 )
	static float thumbRX;		// 右スティックの横軸値( -1.0 ～ 1.0 )
	static float thumbRY;		// 右スティックの縦軸値( -1.0 ～ 1.0 )

private:
	/**
	* static int CheckButtonIndex(const short)
	* 引数：
	* 　const short checkXButton　調べたいXInputボタンの入力定義
	* 戻り値：
	* 　TRUE　問題なし
	* 　FLASE　エラー
	* 処理内容：
	* 　引数の値がXInputボタン入力定義の範囲内(0～15)かどうか調べる
	*/
	static int CheckButtonIndex(const short);

	/**
	* static int CheckTriggerThumb(const float, const float, const int)
	* 引数：
	* 　const float checkData　調べるデータ
	* 　const float threshold　しきい値
	* 　const int isMore：
	* 　　TRUE　しきい値以上
	* 　　FALSE　しきい値以下
	* 戻り値：
	* 　TRUE　入力あり
	* 　FLASE　入力なし
	* 処理内容：
	* 　調べるデータの値をしきい値と比較し入力があるか調べる
	*/
	static int CheckTriggerThumb(const float, const float, const int);

public:
	/**
	* static void Update()
	* 引数：なし
	* 戻り値：なし
	* 処理内容：
	* 　XInputの入力情報を更新する
	*/
	static void Update();

	/**
	* static int ButtonPressed(const short)
	* 引数：
	* 　const short checkXButton　調べたいXInputボタンの入力定義
	* 戻り値：
	* 　TRUE　入力あり
	* 　FLASE　入力なし
	* 処理内容：
	* 　引数に対応するボタンが押されているか調べる
	*/
	static int ButtonPressed(const short);

	/**
	* static int ButtonDown(const short)
	* 引数：
	* 　const short checkXButton　調べたいXInputボタンの入力定義
	* 戻り値：
	* 　TRUE　入力あり
	* 　FLASE　入力なし
	* 処理内容：
	* 　引数に対応するボタンが押された瞬間か調べる
	*/
	static int ButtonDown(const short);

	/**
	* static int ButtonReleased(const short)
	* 引数：
	* 　const short checkXButton　調べたいXInputボタンの入力定義
	* 戻り値：
	* 　TRUE　入力なし
	* 　FLASE　入力あり
	* 処理内容：
	* 　引数に対応するボタンが離されているか調べる
	*/
	static int ButtonReleased(const short);

	/**
	* static int ButtonUp(const short)
	* 引数：
	* 　const short checkXButton　調べたいXInputボタンの入力定義
	* 戻り値：
	* 　TRUE　入力なし
	* 　FLASE　入力あり
	* 処理内容：
	* 　引数に対応するボタンが離された瞬間か調べる
	*/
	static int ButtonUp(const short);

	/**
	* static int CheckLeftTrigger(const float, const int)
	* 引数：
	* 　const float threshold　しきい値
	* 　const int isMore：
	* 　　TRUE　しきい値以上
	* 　　FALSE　しきい値以下
	* 戻り値：
	* 　TRUE　入力あり
	* 　FLASE　入力なし
	* 処理内容：
	* 　左トリガーの入力値をしきい値と比較し入力があるか調べる
	*/
	static int CheckLeftTrigger(const float, const int);

	/**
	* static int CheckRightTrigger(const float, const int)
	* 引数：
	* 　const float threshold　しきい値
	* 　const int isMore：
	* 　　TRUE　しきい値以上
	* 　　FALSE　しきい値以下
	* 戻り値：
	* 　TRUE　入力あり
	* 　FLASE　入力なし
	* 処理内容：
	* 　右トリガーの入力値をしきい値と比較し入力があるか調べる
	*/
	static int CheckRightTrigger(const float, const int);

	/**
	* static int CheckThumbLX(const float, const int)
	* 引数：
	* 　const float threshold　しきい値
	* 　const int isMore：
	* 　　TRUE　しきい値以上
	* 　　FALSE　しきい値以下
	* 戻り値：
	* 　TRUE　入力あり
	* 　FLASE　入力なし
	* 処理内容：
	* 　左スティック横軸の入力値をしきい値と比較し入力があるか調べる
	*/
	static int CheckThumbLX(const float, const int);

	/**
	* static int CheckThumbLY(const float, const int)
	* 引数：
	* 　const float threshold　しきい値
	* 　const int isMore：
	* 　　TRUE　しきい値以上
	* 　　FALSE　しきい値以下
	* 戻り値：
	* 　TRUE　入力あり
	* 　FLASE　入力なし
	* 処理内容：
	* 　左スティック縦軸の入力値をしきい値と比較し入力があるか調べる
	*/
	static int CheckThumbLY(const float, const int);

	/**
	* static int CheckThumbRX(const float, const int)
	* 引数：
	* 　const float threshold　しきい値
	* 　const int isMore：
	* 　　TRUE　しきい値以上
	* 　　FALSE　しきい値以下
	* 戻り値：
	* 　TRUE　入力あり
	* 　FLASE　入力なし
	* 処理内容：
	* 　右スティック横軸の入力値をしきい値と比較し入力があるか調べる
	*/
	static int CheckThumbRX(const float, const int);

	/**
	* static int CheckThumbRY(const float, const int)
	* 引数：
	* 　const float threshold　しきい値
	* 　const int isMore：
	* 　　TRUE　しきい値以上
	* 　　FALSE　しきい値以下
	* 戻り値：
	* 　TRUE　入力あり
	* 　FLASE　入力なし
	* 処理内容：
	* 　右スティック縦軸の入力値をしきい値と比較し入力があるか調べる
	*/
	static int CheckThumbRY(const float, const int);

public:
	/**
	* static const unsigned char* getOldButtons()
	* 引数：なし
	* 戻り値：
	* 　InputControl::oldButtons　前フレームのボタン入力情報
	* 処理内容：
	* 　前フレームのボタン入力情報を返す
	*/
	static const unsigned char* getOldButtons();

	/**
	* static const unsigned char* getNowButtons()
	* 引数：なし
	* 戻り値：
	* 　InputControl::nowButtons　現在のボタン入力情報
	* 処理内容：
	* 　現在のフレームのボタン入力情報を返す
	*/
	static const unsigned char* getNowButtons();

	/**
	* static const float getLeftTrigger()
	* 引数：なし
	* 戻り値：
	* 　InputControl::leftTrigger(0.0f～1.0f)　左トリガーの入力情報
	* 処理内容：
	* 　左トリガーの入力情報を返す
	*/
	static const float getLeftTrigger();

	/**
	* static const float getRightTrigger()
	* 引数：なし
	* 戻り値：
	* 　InputControl::rightTrigger(0.0f～1.0f)　右トリガーの入力情報
	* 処理内容：
	* 　右トリガーの入力情報を返す
	*/
	static const float getRightTrigger();

	/**
	* static const float getThumbLX()
	* 引数：なし
	* 戻り値：
	* 　InputControl::thumbLX(-1.0f～1.0f)　左スティック横軸の入力情報
	* 処理内容：
	* 　左スティック横軸の入力情報を返す
	*/
	static const float getThumbLX();

	/**
	* static const float getThumbLY()
	* 引数：なし
	* 戻り値：
	* 　InputControl::thumbLY(-1.0f～1.0f)　左スティック縦軸の入力情報
	* 処理内容：
	* 　左スティック縦軸の入力情報を返す
	*/
	static const float getThumbLY();

	/**
	* static const float getThumbRX()
	* 引数：なし
	* 戻り値：
	* 　InputControl::thumbRX(-1.0f～1.0f)　右スティック横軸の入力情報
	* 処理内容：
	* 　右スティック横軸の入力情報を返す
	*/
	static const float getThumbRX();

	/**
	* static const float getThumbRY()
	* 引数：なし
	* 戻り値：
	* 　InputControl::thumbRY(-1.0f～1.0f)　右スティック縦軸の入力情報
	* 処理内容：
	* 　右スティック縦軸の入力情報を返す
	*/
	static const float getThumbRY();
};