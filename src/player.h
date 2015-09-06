#ifndef _PLAYER_H_
#define _PLAYER_H_

/**
*声明玩家类
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player {
private:
	string playerName;	//玩家姓名
	int playerId;		//玩家ID
	vector<int> ownPos;
	int assets;		//资产,默认10000，初始为10000
					//	int fixedAssets;	//固定资产
	int points;		//玩家可用点数

	unsigned int position;	//玩家位置
	char playerSign;	//玩家显示符号
	unsigned short signColor;	//玩家显示颜色

	int noActionTimes;	//轮空次数

public:
	Player(string m_name, int m_id, char m_sign) :
		playerName(m_name), playerId(m_id),playerSign(m_sign) {
		assets = 0;
		points = 0;
		position = 0;
		noActionTimes = 0;
	}
	~Player() {}

	//查询拥有地块个数
	int getOwnPosNum();

	//添加自己拥有的位置
	void putOwnPos(int pos);

	//查询自己所有拥有地块
	void printOwnPos();

	//查询指定编号的拥有地块 ,判断是否是自己的地块
	bool isOwnPos(int pos);

	void deletePos(int pos);

	vector<int> getOwnPosContainer();

	int getPlayerPos();

	int getPlayerAssets();

	char getPlayerSign();

	unsigned short getPlayerSignColor();

	int getPlayerId();

	string getPlayerName();

	int getPlayerPoints();

	void setPlayerAssets(int m_assets);

	void setPlayerSign(char sign);

	void setPlayerName(string name);

	void setPlayerPos(int pos);

	void setPlayerPoints(int po);

	void setPlayerId(int id);

	void setNoActionTimes(int times);
	
	int getNoActionTimes();
};

#endif