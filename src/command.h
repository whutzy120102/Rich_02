#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "player.h"
#include "map.h"
#include "playerAction.h"

/**
*声明命令类
*/

class Command
{
public:

	/*
	*函数：help()
	*参数说明：
	*功能：帮助说明命令的使用
	*返回值：无
	*作者：
	*/
	void help();

	/*
	*函数：quit()
	*参数说明：
	*功能：终止游戏
	*返回值：无
	*作者：
	*/
	void quit();

	/*
	*函数：roll()
	*参数说明：
	*功能：掷骰子
	*返回值：无
	*作者：
	*/
	void roll(Player player, Map map, PlayerAction pAction);

	/*
	*函数：sell()
	*参数说明：
	*功能：出售玩家的房产
	*返回值：无
	*作者：
	*/
	bool sell(Player player, Place place, int position);

	/*
	*函数：query()
	*参数说明：无
	*功能：查询玩家资产信息
	*返回值：无
	*作者：
	*/
	void query(Player player);

	void exit(Player player, Map map);
	void quit();
};
#endif