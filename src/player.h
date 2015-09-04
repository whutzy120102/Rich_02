#ifndef _PLAYER_H_
#define _PLAYER_H_

/**
*声明玩家类
*/

#include <iostream>
#include <string>

using namespace std;

class Player {
private:
	string playerName;	//玩家姓名
	int playerId;		//玩家ID

	int assets;		//资产,默认10000，初始为10000
					//	int fixedAssets;	//固定资产
	int points;		//玩家可用点数

	unsigned int position;	//玩家位置
	char playerSign;	//玩家显示符号
	unsigned short signColor;	//玩家显示颜色

public:
	Player(string m_name, int m_id) :
		playerName(m_name), playerId(m_id) {
		assets = 0;
		points = 0;
		position = 0;
	}
	~Player() {}

	int getPlayerPos()
	{
		return position;
	}

	int getPlayerAssets()
	{
		return assets;
	}

	char getPlayerSign()
	{
		return playerSign;
	}
	unsigned short getPlayerSignColor()
	{
		return signColor;
	}

	int getPlayerId()
	{
		return playerId;
	}

	string getPlayerName()
	{
		return playerName;
	}

	int getPlayerPoints()
	{
		return points;
	}

	void setPlayerAssets(int m_assets)
	{
		assets = m_assets;
	}

	void setPlayerSign(char sign)
	{
		playerSign = sign;
	}

	void setPlayerName(string name)
	{
		playerName = name;
	}

	void setPlayerPos(int pos)
	{
		position = pos;
	}

	void setPlayerPoints(int po)
	{
		points = po;
	}

};

#endif