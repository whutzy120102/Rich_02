#ifndef _COMMAND_H_
#define _COMMAND_H_

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
	void roll();

	/*
	*函数：sell()
	*参数说明：
	*功能：出售玩家的房产
	*返回值：无
	*作者：
	*/
	void sell();
};
#endif