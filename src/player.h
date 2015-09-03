#ifndef _PLAYER_H_
#define _PLAYER_H_

/**
*声明玩家类
*/

#include <iostream>
#include <string>
#include "place.h"
class Place;
using namespace std;


class Player {
private:
	string name;	//玩家姓名
	int id;		//玩家ID

	int assets;		//资产,默认10000，初始为10000
					//	int fixedAssets;	//固定资产
	int points;		//玩家可用点数

	unsigned int position;	//玩家位置
	char playerSign;	//玩家显示符号
	unsigned short signColor;	//玩家显示颜色

public:
	Player(string m_name, int m_id) :
		name(m_name), id(m_id) {
		assets = 0;
		points = 0;
		position = 0;
	}
	~Player() {}


	/*
	*函数：getPlayerPos()
	*参数说明：无
	*功能：返回当前玩家的位置
	*返回值：int:position
	*作者：
	*/
	int getPlayerPos();

	/*
	*函数：goStep(int step)
	*参数说明：step玩家掷骰子获得的点数，即行走步数
	*功能：玩家按点数行走
	*返回值：int:当前位置
	*作者：
	*/
	int goStep(int step);

	/*
	*函数：resetPlayerPos(int step)
	*参数说明：step玩家掷骰子获得的点数，即行走步数
	*功能：重新设置用户位置
	*返回值：int:玩家位置
	*作者：
	*/
	int resetPlayerPos(int step);

	/*
	*函数：buyLand(Place place)
	*参数说明：place：想要购买的地块
	*功能：购买空地
	*返回值：无
	*作者：
	*/
	void buyLand(Place place);

	/*
	*函数： stayInDiffPlace(Place place, Player player)
	*参数说明：place:地块，player：处于地块的玩家·
	*功能：停留在不同地块之上，执行购买、支付钱财的行为
	*返回值：无
	*作者：
	*/
	void stayInDiffPlace(Place place, Player player);

	/*
	*函数： payForStay(Place place, Player player)
	*参数说明：place:地块，player：处于地块的玩家·
	*功能：停留他人购买地块之上，执行支付钱财的行为
	*返回值：无
	*作者：
	*/
	void payForStay(Place place, Player player);

	/*
	*函数： uppdatePlate(Place place)
	*参数说明：place:地块
	*功能：升级地块，最高升级3次
	*返回值：无
	*作者：
	*/
	void uppdatePlate(Place place);
};

#endif