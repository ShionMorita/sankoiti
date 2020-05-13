//---------------------------------------------------------------
//
// BaseProject = Effect
// ����˗���
//
//---------------------------------------------------------------

#include "Dxlib.h"
#include "Effect.h"

// �ϐ�
//----------------------------------------------------------------
// ��ʐؑփG�t�F�N�g
int fadeCnt;
bool fadeIn;
bool fadeOut;
// �ꎞ��~�G�t�F�N�g
bool pauseFlag;
int a;


// �G�t�F�N�g�̏�����
//--------------------------------------------------------------
void EffectInit(void)
{
	// ��ʐ؂�ւ��G�t�F�N�g
	fadeIn = false;
	fadeOut = false;
	fadeCnt = 0;
	// �ꎞ��~�G�t�F�N�g
	pauseFlag = false;
	a = 0;
}


// �t�F�[�h�C������
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


// �t�F�[�h�A�E�g����
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