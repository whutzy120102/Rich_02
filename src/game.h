/**
*声明游戏类
*/
#ifndef _GAME_H_
#define _GAME_H_

#include "map.h"
#include "player.h"
#include "command.h"
#include <vector>

const int MAX_PLAYER_NUM = 4;

class Game
{
private:
	Map *map;
	vector<Player> players;
	Command *command;
	int playerNum;

public:
	Game()
	{
		command = new Command();
		map = new Map();
		playerNum = 0;
	}

	~Game()
	{
		delete command;
		delete map;
		//playerNum = 0;
	}

	/*
	*函数：initPlayer()
	*参数说明：
	*功能：初始化玩家，包括玩家的资金，位置
	*返回值：无
	*作者：
	*/
	void initPlayer()
	{
		addPlayer(Player("wangfei", 1));
		addPlayer(Player("liuzi", 2));
		addPlayer(Player("xiaoqiang", 3));
		addPlayer(Player("leixiao", 4));
	}

	/*
	*函数：initGame()
	*参数说明：
	*功能：初始化地图和玩家
	*返回值：无
	*作者：
	*/
	void initGame()
	{
		initPlayer();
		map->initMap();
		map->printMap();
	}

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
	void addPlayer(Player player)
	{
		players.push_back(player);
		//玩家数目加1
		playerNum++;
	}

	/*
	*函数：deletePlayer()
	*参数说明：
	*功能：删除玩家
	*返回值：无
	*作者：
	*/
	void deletePlayer(Player player)
	{
		vector<Player>::iterator it;
		for (it = players.begin(); it != players.end(); ++it)
		{
			if (player.getPlayerId() == it->getPlayerId())
			{
				players.erase(it);
				break;
			}
		}
	}

	//执行游戏
	void goGame()
	{
		initGame();
		while (playerNum > 1)
		{
			cout << "";
		}
	}
};

#endif