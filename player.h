#define PLAYER_SIZE_X 32
#define PLAYER_SIZE_Y 32
#define PLAYER_DEF_SPEED 4
#define PLAYER_ANI_MAX 4

class Player
{
	// private�Ƃ��ď�������Ă���
	char playerName;

private:
	const int START_POS_X;	// �v���C���[�̏����ʒuX���W
	const int START_POS_Y;	// �v���C���[�̏����ʒuY���W

	// �����o�ϐ�
	int playerImage[PLAYER_ANI_MAX];
	int playerPosX;
	int playerPosY;
	int playerSpeed;
	int playerCounter;
	bool playerFlag;

	int playerNo;
	KEY_LIST keyList;

public:
	//Player(int no);
	Player(int no, int posX, int posY, const char filename[], KEY_LIST key);
	~Player();

public:
	// �����o�֐�
	void SystemInit(void);
	void GameInit(void);
	void Control(void);
	void Draw(void);

	XY GetPos(void);
	XY GetSize(void);
	
	void DeletePlayer(void);
};