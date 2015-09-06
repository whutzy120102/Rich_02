#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "player.h"
#include "map.h"
#include "playerAction.h"
#include "function.h"
const int MIN_STEP = 1;
const int MAX_STEP = 6;
const int MAX_COMMAND_SIZE = 10; //最大允许输入命令长度
/**
*声明命令类
*/

class Command
{
private:
	char command[MAX_COMMAND_SIZE];
	PlayerAction *action;
	//Player *player;
	//Place *place;
	//Map *map;
public:
	Command() 
	{
		action = new PlayerAction;
	}
	~Command() {}

	/*
	*函数：help()
	*参数说明：
	*功能：帮助说明命令的使用
	*返回值：无
	*作者：
	*/
	void help();


	/*
	*函数：roll()
	*参数说明：
	*功能：掷骰子
	*返回值：无
	*作者：
	*/
	int roll();

	/*
	*函数：sell()
	*参数说明：Player player, Place place, int position
	*功能：出售玩家的房产
	*返回值：无
	*作者：
	*/
	void sell(vector<Player>::iterator it, Map *map);

	/*
	*函数：query()
	*参数说明：无Player player
	*功能：查询玩家资产信息
	*返回值：无
	*作者：
	*/
	void query(vector<Player>::iterator it);

	//Player player, Map map
	void exit(vector<Player>::iterator it, Map *map);

	//获取小写命令
	char* getLowerCommand();

	//执行命令
	int goCommand(vector<Player>::iterator it, Map *map);

	//判断命令相等
	bool equalCommand(char *m, char *m_m);

	//强退
	void quit();

};
#endif