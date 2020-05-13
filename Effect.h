//#pragma once

// extern宣言
//----------------------------------------------------------------
// 画面切替エフェクト
extern int fadeCnt;
extern bool fadeIn;
extern bool fadeOut;
// 一時停止エフェクト
extern bool pauseFlag;
extern int a;


// プロトタイプ宣言
//------------------------------------------------------------------
void EffectInit(void);
bool FadeInScreen(int fadeStep);	// フェードイン処理
bool FadeOutScreen(int fadeStep);	// フェードアウト処理

