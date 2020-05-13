
#include "Dxlib.h"			// Dxlib���C�u�������g�p
#include "main.h"
#include "player.h"
#include "KeyCheck.h"
#include "Effect.h"


// �ϐ�
//-------------------------------------------------------------
// �V�[���Ǘ��p
int gameCounter;		// gameLoop����m�F�p
int sceneCounter;		// �V�[���J�E���^�[
SCENE_ID sceneID;
SCENE_ID preSceneID;

// �^�C�g��
int titleImage;
int titleWordImage;

// �N���X����C���X�^���X�𐶐�����
Player* player1;


// WinMain�֐�
//-------------------------------------------------------------
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// �V�X�e���̏�����
	if (!SystemInit())
	{
		return -1;
	}

	// �Q�[�����[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{

		player1->Control();

		ClsDrawScreen();

		// �V�[���J�E���^�𐧌�
		if (sceneID != preSceneID)
		{
			preSceneID = sceneID;
			sceneCounter = 0;
		}


		// ���͏��̎擾
		KeyCheck();


		// �V�[���I��
		switch (sceneID)
		{
		// �������V�[��
		case SCENE_ID_INIT:
			InitScene();
			break;

		// �^�C�g���V�[��
		case SCENE_ID_TITLE:
			// ��ʐ؂�ւ��G�t�F�N�g
			if (fadeIn)
			{
				if (!FadeInScreen(5))
				{
					// �G�t�F�N�g�I����̏���
				}
			}
			else if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{
					// �G�t�F�N�g�I����̏���
					sceneID = SCENE_ID_GAME;
					fadeIn = true;
					//SetDrawBright(255, 255, 255);
				}
			}
			TitleScene();
			break;

		// �Q�[���V�[��
		case SCENE_ID_GAME:
			// ��ʐ؂�ւ��G�t�F�N�g
			if (fadeIn)
			{
				if (!FadeInScreen(5))
				{
					// �G�t�F�N�g�I����̏���
				}
			}
			else if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{
					// �G�t�F�N�g�I����̏���
					sceneID = SCENE_ID_GAMEOVER;
					fadeIn = true;
					//SetDrawBright(255, 255, 255);
				}
			}
			GameScene();
			break;

		// �Q�[���I�[�o�[�V�[��
		case SCENE_ID_GAMEOVER:
			// ��ʐ؂�ւ��G�t�F�N�g
			if (fadeIn)
			{
				if (!FadeInScreen(5))
				{
					// �G�t�F�N�g�I����̏���
				}
			}
			else if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{
					// �G�t�F�N�g�I����̏���
					sceneID = SCENE_ID_INIT;
					fadeIn = true;
					//SetDrawBright(255, 255, 255);
				}
			}
			GameOverScene();
			break;

		// ���̑�
		default:
			return -1;
			break;
		}


		gameCounter++;
		sceneCounter++;

		ScreenFlip();
	}

	DxLib_End();		// DX���C�u�����̏I������
	return 0;
}


//�V�X�e���n������
//--------------------------------------------------------------
bool SystemInit(void)
{
	// �V�X�e���̏�����
	SetWindowText("SanCo��");
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	ChangeWindowMode(true);
	if (DxLib_Init() == -1)
	{
		return -1;
	}
	SetDrawScreen(DX_SCREEN_BACK);

	// �ݽ�ݽ�̐���
	player1 = new Player(PLAYER_1
		, 100
		, SCREEN_SIZE_Y - 50
		, "image/bule.png"
		, { KEY_INPUT_W
		,	KEY_INPUT_D
		,	KEY_INPUT_S
		,	KEY_INPUT_A});


	// �O���t�B�b�N�̓o�^
	//---------------------------------
	
	// �ϐ��̏�����
	//---------------------------------
	gameCounter = 0;
	sceneCounter = 0;
	sceneID = SCENE_ID_INIT;
	preSceneID = SCENE_ID_MAX;
	
	player1->GameInit();

	KeyInit();		// �L�[���̏�����
	EffectInit();	// �G�t�F�N�g�̏�����

	return true;
}



// �������V�[��
//--------------------------------------------------------------
void InitScene(void)
{
	fadeIn = true;
	
	sceneID = SCENE_ID_TITLE;

}


// �^�C�g���V�[��
//---------------------------------------------------------------
void TitleScene(void)
{
	if (keyUpTrigger[KEY_ID_SPACE])
	{
		fadeOut = true;
	}

	TitleDraw();
}

void TitleDraw(void)
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "TitleScene : %d", sceneCounter);

	DrawBox(100, 100, 700, 500, GetColor(0, 255, 0), true);
}


// �Q�[���V�[��
//----------------------------------------------------------------
void GameScene(void)
{

	if (keyUpTrigger[KEY_ID_SPACE])
	{
		fadeOut = true;
	}

	// Pause�@�\
	if (keyDownTrigger[KEY_ID_PAUSE])
	{
		pauseFlag = !pauseFlag;
	}

	// Pause��
	if (pauseFlag)
	{
		SetDrawBright(100, 100, 100);
	}
	// �ʏ퓮�쎞
	else
	{
		// �e�폈��
		a++;
	}

	// ��ʕ`��
	GameDraw();

	// Pause���b�Z�[�W��`��
	if (pauseFlag)
	{
		SetDrawBright(255, 255, 255);
		DrawFormatString((SCREEN_SIZE_X - 9 * 8) / 2
			, (SCREEN_SIZE_Y - 16) / 2
			, GetColor(255, 255, 255)
			, "P A U S E");
	}
}

void GameDraw(void)
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "GameScene : %d", sceneCounter);
	DrawFormatString(0, 64, GetColor(255, 255, 255), "����m�F : (%d)", a);

	DrawBox(100, 100, 700, 500, GetColor(255, 0, 0), true);
	player1->Draw();
}


// �Q�[���I�[�o�[�V�[��
//-----------------------------------------------------------------
void GameOverScene(void)
{
	if (keyUpTrigger[KEY_ID_SPACE])
	{
		fadeOut = true;
	}

	GameOverDraw();
}

void GameOverDraw(void)
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "GameOverScene : %d", sceneCounter);

	DrawBox(100, 100, 700, 500, GetColor(0, 0, 255), true);
}