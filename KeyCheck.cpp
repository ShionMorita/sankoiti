//---------------------------------------------------------------
//
// BaseProject = KeyCheck
// 金崎依里朱
//
//---------------------------------------------------------------

#include "Dxlib.h"
#include "KeyCheck.h"

// 変数
//---------------------------------------------------------------
// 入力情報管理用
bool keyOld[KEY_ID_MAX];			// 1フレーム前の入力状態
bool keyNew[KEY_ID_MAX];			// 現在の入力状態
bool keyDownTrigger[KEY_ID_MAX];	// キーダウン時のトリガー
bool keyUpTrigger[KEY_ID_MAX];		// キーアップ時のトリガー



// 入力情報関連
//---------------------------------------------------------------
// 入力情報の初期化
void KeyInit(void)
{
	for (int keyID = 0; keyID < KEY_ID_MAX; keyID++)
	{
		keyOld[keyID] = false;
		keyNew[keyID] = false;
		keyDownTrigger[keyID] = false;
		keyUpTrigger[keyID] = false;
	}
}
// 入力情報の確認
void KeyCheck(void)
{
	// Oldの準備
	for (int keyID = 0; keyID < KEY_ID_MAX; keyID++)
	{
		keyOld[keyID] = keyNew[keyID];
	}


	// 現在の状態を取得する
	keyNew[KEY_ID_SPACE] = CheckHitKey(KEY_INPUT_SPACE);
	keyNew[KEY_ID_PAUSE] = CheckHitKey(KEY_INPUT_P);


	// トリガーの算出
	for (int keyID = 0; keyID < KEY_ID_MAX; keyID++)
	{
		keyDownTrigger[keyID] = false;
		keyUpTrigger[keyID] = false;

		// ダウントリガーの算出
		if (!keyOld[keyID] && keyNew[keyID])
		{
			keyDownTrigger[keyID] = true;
		}
		// アップトリガーの算出
		if (keyOld[keyID] && !keyNew[keyID])
		{
			keyUpTrigger[keyID] = true;
		}
	}
}
