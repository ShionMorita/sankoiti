//---------------------------------------------------------------
//
// BaseProject = KeyCheck
// ����˗���
//
//---------------------------------------------------------------

#include "Dxlib.h"
#include "KeyCheck.h"

// �ϐ�
//---------------------------------------------------------------
// ���͏��Ǘ��p
bool keyOld[KEY_ID_MAX];			// 1�t���[���O�̓��͏��
bool keyNew[KEY_ID_MAX];			// ���݂̓��͏��
bool keyDownTrigger[KEY_ID_MAX];	// �L�[�_�E�����̃g���K�[
bool keyUpTrigger[KEY_ID_MAX];		// �L�[�A�b�v���̃g���K�[



// ���͏��֘A
//---------------------------------------------------------------
// ���͏��̏�����
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
// ���͏��̊m�F
void KeyCheck(void)
{
	// Old�̏���
	for (int keyID = 0; keyID < KEY_ID_MAX; keyID++)
	{
		keyOld[keyID] = keyNew[keyID];
	}


	// ���݂̏�Ԃ��擾����
	keyNew[KEY_ID_SPACE] = CheckHitKey(KEY_INPUT_SPACE);
	keyNew[KEY_ID_PAUSE] = CheckHitKey(KEY_INPUT_P);


	// �g���K�[�̎Z�o
	for (int keyID = 0; keyID < KEY_ID_MAX; keyID++)
	{
		keyDownTrigger[keyID] = false;
		keyUpTrigger[keyID] = false;

		// �_�E���g���K�[�̎Z�o
		if (!keyOld[keyID] && keyNew[keyID])
		{
			keyDownTrigger[keyID] = true;
		}
		// �A�b�v�g���K�[�̎Z�o
		if (keyOld[keyID] && !keyNew[keyID])
		{
			keyUpTrigger[keyID] = true;
		}
	}
}
