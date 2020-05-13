#define PLAYER_SIZE_X 32
#define PLAYER_SIZE_Y 32
#define PLAYER_DEF_SPEED 4
#define PLAYER_ANI_MAX 4

class Player
{
	// privateとして処理されている
	char playerName;

private:
	const int START_POS_X;	// プレイヤーの初期位置X座標
	const int START_POS_Y;	// プレイヤーの初期位置Y座標

	// メンバ変数
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
	// メンバ関数
	void SystemInit(void);
	void GameInit(void);
	void Control(void);
	void Draw(void);

	XY GetPos(void);
	XY GetSize(void);
	
	void DeletePlayer(void);
};