#include"Dxlib.h"
#include "main.h"
#include "player.h"

Player::Player(int no, int posX, int posY, const char filename[], KEY_LIST key) : START_POS_X(posX), START_POS_Y(posY)
{
	playerNo = no;
	keyList = key;
	playerImage[PLAYER_ANI_MAX] = LoadDivGraph(filename, PLAYER_ANI_MAX, PLAYER_ANI_MAX, 1, 40, 58, playerImage);

	// 変数の初期化
	playerPosX = (SCREEN_SIZE_X - PLAYER_SIZE_X) / 2;
	playerPosY = (SCREEN_SIZE_Y - PLAYER_SIZE_Y);
	playerSpeed = PLAYER_DEF_SPEED;
	playerFlag = true;
	playerCounter = 0;
}

//デストラクタ
Player::~Player()
{
	//DeleteGraph(playerImage);
}


void Player::SystemInit(void)
{
	LoadDivGraph("image/bule.png", PLAYER_ANI_MAX, PLAYER_ANI_MAX, 1, 40, 58, playerImage);
}

void Player::GameInit(void)
{
	playerPosX = START_POS_X;
	playerPosY = START_POS_Y;
	playerSpeed = PLAYER_DEF_SPEED;
}

void Player::Control(void)
{
	// キー操作
	// ｽﾋﾟｰﾄﾞを変える

	// playerを移動させる
	if (CheckHitKey(keyList.Right))	// 右移動
	{
		if (playerPosX < SCREEN_SIZE_X - PLAYER_SIZE_X)
		{
			playerPosX = playerPosX + playerSpeed;
		}
	}
	if (CheckHitKey(keyList.Left))	// 左移動
	{
		if (playerPosX > 0)
		{
			playerPosX = playerPosX - playerSpeed;
		}
	}
	if (CheckHitKey(keyList.Up))		// 上移動
	{
		if (playerPosY > 0)
		{
			playerPosY = playerPosY - playerSpeed;
		}
	}
	if (CheckHitKey(keyList.Down))		// 下移動
	{
		if (playerPosY < SCREEN_SIZE_Y - PLAYER_SIZE_Y)
		{
			playerPosY = playerPosY + playerSpeed;
		}
	}

	//// 弾の発射
	//if (CheckHitKey(keyList.Shot))
	//{
	//	CreateMainShot(GetPos());
	//}


	// 自機が倒されたら初期位置に再表示
	if (playerFlag == false)
	{
		playerPosX = (SCREEN_SIZE_X - PLAYER_SIZE_X) / 2;
		playerPosY = (SCREEN_SIZE_Y - PLAYER_SIZE_Y);
		playerFlag = true;
	}
	playerCounter++;
}


XY Player::GetPos(void)
{
	return { playerPosX,playerPosY };
}

XY Player::GetSize(void)
{
	return { PLAYER_SIZE_X,PLAYER_SIZE_Y };
}


void Player::Draw(void)
{
	// ﾌﾟﾚｲﾔｰの表示
	if (playerFlag == true)
	{
		DrawBox(playerPosX, playerPosY, playerPosX + PLAYER_SIZE_X, playerPosY + PLAYER_SIZE_Y, 0xffffff, false);
	}

	// 文字の表示
	DrawFormatString(0, 0, 0xffffff, "Speed:%d", playerSpeed);
	DrawFormatString(0, 16, GetColor(255, 255, 255), "Count:%d", playerCounter);

	DrawGraph(playerPosX, playerPosY, playerImage[playerCounter / 5 % PLAYER_ANI_MAX], true);
}

void Player::DeletePlayer(void)
{
	playerFlag = false;
}