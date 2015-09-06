/**
*声明游戏类
*/
#ifndef _GAME_H_
#define _GAME_H_

#include "map.h"
#include "player.h"
#include "command.h"
#include "function.h"
#include <vector>


const int MAX_PLAYER_NUM = 5;	//最大允许设置玩家
const int MIN_PLAYER_NUM = 2;	//最小允许设置玩家
//可供选择的玩家

const string STAY_PLAYERS[MAX_PLAYER_NUM] ={ "钱夫人", "阿土伯", "孙小美","金贝贝" };
const char PLAYER_SIGN[MAX_PLAYER_NUM] = { 'Q', 'A', 'S', 'J' };


class Game
{
private:
	Map *map;
	vector<Player> players;
	Command *command;
	int playerNum;
	int defaultMoney;	//默认初始化资产

public:
	Game()
	{
		command = new Command();
		map = new Map();
		playerNum = 0;
		defaultMoney = 10000;
	}

	~Game()
	{
		delete command;
		delete map;
		players.clear();
	}

	//设置初始资金
	void setDefalutMoney();

	/*
	*函数：initPlayer()
	*参数说明：
	*功能：初始化玩家，包括玩家的资金，位置
	*返回值：无
	*作者：
	*/
	void initPlayer();



	/*
	*函数：initGame()
	*参数说明：
	*功能：初始化地图和玩家
	*返回值：无
	*作者：
	*/
	void initGame();

	/*
	*函数：destroyPlayer()
	*参数说明：
	*功能：销毁地图
	*返回值：无
	*作者：
	*/
	void destroyGame();

	/*
	*函数：quitGame()
	*参数说明：
	*功能：终止游戏
	*返回值：无
	*作者：
	*/
	void quitGame();

	/*
	*函数：addPlayer()
	*参数说明：
	*功能：添加玩家
	*返回值：无
	*作者：
	*/
	void addPlayer(Player player);


	//重新设置玩家相关地图
	void cleanMapOfPlayer(vector<Player>::iterator it, Map *map);

	//清空玩家设置
	void cleanPlayer(vector<Player>::iterator it);

	/*
	*函数：deletePlayer()
	*参数说明：
	*功能：删除玩家
	*返回值：无
	*作者：
	*/
	void deletePlayer(vector<Player>::iterator it);

	//游戏主体,主要包括玩家一次各种操作
	void goGameBody();

	//执行游戏，再次封装游戏
	void goGame();

	//选择玩家
	void choicePlayer(char *input);

	//检查玩家是否存在
	bool isExistPlayer(char *input);

	//检查输入玩家是否重复
	bool isInputPlayer(char *input);


	//输入玩家
	void getPlayerInput(char *input);

	//输入命令
	void getCommandInput(char *input);

	//刷新地图
	void Game::flushMap();

	
};

#endif