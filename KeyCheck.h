//#pragma once

// �񋓌^
//--------------------------------------------------------------
// ���͏��Ǘ��p
enum KEY_ID {
	KEY_ID_SPACE,		//	�X�y�[�X�L�[
	KEY_ID_PAUSE,
	KEY_ID_MAX
};


// extern�錾
//--------------------------------------------------------------
extern bool keyOld[KEY_ID_MAX];				// 1�t���[���O�̓��͏��
extern bool keyNew[KEY_ID_MAX];				// ���݂̓��͏��
extern bool keyDownTrigger[KEY_ID_MAX];		// �L�[�_�E�����̃g���K�[
extern bool keyUpTrigger[KEY_ID_MAX];		// �L�[�A�b�v���̃g���K�[


// �v���g�^�C�v�錾
//--------------------------------------------------------------
void KeyInit(void);			// ���͏��̏�����
void KeyCheck(void);		// ���͏��̊m�F
