//#pragma once

// extern�錾
//----------------------------------------------------------------
// ��ʐؑփG�t�F�N�g
extern int fadeCnt;
extern bool fadeIn;
extern bool fadeOut;
// �ꎞ��~�G�t�F�N�g
extern bool pauseFlag;
extern int a;


// �v���g�^�C�v�錾
//------------------------------------------------------------------
void EffectInit(void);
bool FadeInScreen(int fadeStep);	// �t�F�[�h�C������
bool FadeOutScreen(int fadeStep);	// �t�F�[�h�A�E�g����

