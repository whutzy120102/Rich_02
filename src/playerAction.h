#ifndef _PLAYER_ACTION_H_
#define _PLAYER_ACTION_H_

#include "player.h"
#include "place.h"
#include "map.h"

class PlayerAction
{

public:

	/*
	*函数：goStep(int step)
	*参数说明：step玩家掷骰子获得的点数，即行走步数
	*功能：玩家按点数行走
	*返回值：int:当前位置
	*作者：
	*/
	int goStep(Player player, Map map, int step);

	/*
	*函数：resetPlayerPos(int step)
	*参数说明：step玩家掷骰子获得的点数，即行走步数
	*功能：重新设置用户位置
	*返回值：int:玩家位置
	*作者：
	*/
	void resetPlayerPos(Player player, Map map, int step);

	/*
	*函数：buyLand(Place place)
	*参数说明：place：想要购买的地块
	*功能：购买空地
	*返回值：无
	*作者：
	*/
	bool buyLand(Player player, Place place);

	/*
	*函数： payForStay(Place place, Player player)
	*参数说明：place:地块，player：处于地块的玩家·
	*功能：停留他人购买地块之上，执行支付钱财的行为
	*返回值：无
	*作者：
	*/
	bool payForStay(Place place, Player player);

	/*
	*函数： stayInDiffPlace(Place place, Player player)
	*参数说明：place:地块，player：处于地块的玩家·
	*功能：停留在不同地块之上，执行购买、支付钱财的行为
	*返回值：无
	*作者：
	*/
	void stayInDiffPlace(Place place, Player player);



	/*
	*函数： uppdatePlate(Place place)
	*参数说明：place:地块
	*功能：升级地块，最高升级3次
	*返回值：无
	*作者：
	*/
	bool uppdatePlate(Player player, Place place);

};

#endif
