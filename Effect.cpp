//---------------------------------------------------------------
//
// BaseProject = Effect
// 金崎依里朱
//
//---------------------------------------------------------------

#include "Dxlib.h"
#include "Effect.h"

// 変数
//----------------------------------------------------------------
// 画面切替エフェクト
int fadeCnt;
bool fadeIn;
bool fadeOut;
// 一時停止エフェクト
bool pauseFlag;
int a;


// エフェクトの初期化
//--------------------------------------------------------------
void EffectInit(void)
{
	// 画面切り替えエフェクト
	fadeIn = false;
	fadeOut = false;
	fadeCnt = 0;
	// 一時停止エフェクト
	pauseFlag = false;
	a = 0;
}


// フェードイン処理
//--------------------------------------------------------------
bool FadeInScreen(int fadeStep)
{
	fadeCnt += fadeStep;
	if (fadeCnt <= 255)
	{
		SetDrawBright(fadeCnt, fadeCnt, fadeCnt);
		return true;
	}
	else
	{
		SetDrawBright(255, 255, 255);
		fadeCnt = 255;
		fadeIn = false;
		return false;
	}
}


// フェードアウト処理
//--------------------------------------------------------------
bool FadeOutScreen(int fadeStep)
{
	fadeCnt -= fadeStep;
	if (fadeCnt >= 0)
	{
		SetDrawBright(fadeCnt, fadeCnt, fadeCnt);
		return true;
	}
	else
	{
		SetDrawBright(0, 0, 0);
		fadeCnt = 0;
		fadeOut = false;
		return false;
	}
}