// 定数
//------------------------------------------------------------------
#define SCREEN_SIZE_X 800		// 画面サイズ横
#define SCREEN_SIZE_Y 600		// 画面サイズ縦



// 列挙型
//------------------------------------------------------------------
// シーン管理用
enum SCENE_ID {
	SCENE_ID_INIT,		// 初期化シーン
	SCENE_ID_TITLE,		// タイトルシーン
	SCENE_ID_GAME,		// ゲームシーン
	SCENE_ID_GAMEOVER,	// ゲームオーバーシーン
	SCENE_ID_MAX
};

enum PLAYER {
	PLAYER_1,
	PLAYER_2,
	PLAYER_3,
	PLAYER_4,
	PLAYER_MAX
};

// 構造体
//------------------------------------------------------------------

struct KEY_LIST {
	int Up;
	int Right;
	int Down;
	int Left;
};

// 構造体
struct XY
{
	// publicとして処理されている
	int x;
	int y;
};


// プロトタイプ宣言
//------------------------------------------------------------------
bool SystemInit(void);				// システム系初期化

void InitScene(void);				// 初期化シーン用
void TitleScene(void);				// タイトルシーン用
void TitleDraw(void);				// タイトルシーン描画
void GameScene(void);				// ゲームシーン用
void GameDraw(void);				// ゲームシーン描画
void GameOverScene(void);			// ゲームオーバーシーン用
void GameOverDraw(void);			// ゲームオーバーシーン描画