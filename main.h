// �萔
//------------------------------------------------------------------
#define SCREEN_SIZE_X 800		// ��ʃT�C�Y��
#define SCREEN_SIZE_Y 600		// ��ʃT�C�Y�c



// �񋓌^
//------------------------------------------------------------------
// �V�[���Ǘ��p
enum SCENE_ID {
	SCENE_ID_INIT,		// �������V�[��
	SCENE_ID_TITLE,		// �^�C�g���V�[��
	SCENE_ID_GAME,		// �Q�[���V�[��
	SCENE_ID_GAMEOVER,	// �Q�[���I�[�o�[�V�[��
	SCENE_ID_MAX
};

enum PLAYER {
	PLAYER_1,
	PLAYER_2,
	PLAYER_3,
	PLAYER_4,
	PLAYER_MAX
};

// �\����
//------------------------------------------------------------------

struct KEY_LIST {
	int Up;
	int Right;
	int Down;
	int Left;
};

// �\����
struct XY
{
	// public�Ƃ��ď�������Ă���
	int x;
	int y;
};


// �v���g�^�C�v�錾
//------------------------------------------------------------------
bool SystemInit(void);				// �V�X�e���n������

void InitScene(void);				// �������V�[���p
void TitleScene(void);				// �^�C�g���V�[���p
void TitleDraw(void);				// �^�C�g���V�[���`��
void GameScene(void);				// �Q�[���V�[���p
void GameDraw(void);				// �Q�[���V�[���`��
void GameOverScene(void);			// �Q�[���I�[�o�[�V�[���p
void GameOverDraw(void);			// �Q�[���I�[�o�[�V�[���`��