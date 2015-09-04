/**
*声明游戏类
*/
#ifndef _GAME_H_
#define _GAME_H_

#include "map.h"
#include "player.h"
#include "command.h"

class Game
{
private:
	Map map;
	Player *player;
	Command command;
	int playerNum;

public:
	Game() {}
	~Game() {}

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
	void addPlayer();

	/*
	*函数：deletePlayer()
	*参数说明：
	*功能：删除玩家
	*返回值：无
	*作者：
	*/
	void deletePlayer();
};

#endif