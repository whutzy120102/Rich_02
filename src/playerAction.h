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
	*作者：王飞
	*/
	int goStep(Player player, Map map, int step)
	{
		int currentPos = player.getPlayerPos();
		//玩家循环行走
		currentPos = (currentPos + step) % (map.getPlaceNum());
		//此处设置地图显示符号

		return currentPos;
	}

	/*
	*函数：resetPlayerPos(int step)
	*参数说明：step玩家掷骰子获得的点数，即行走步数
	*功能：重新设置用户位置
	*返回值：int:玩家位置
	*作者：王飞
	*/
	void resetPlayerPos(Player player, Map map, int step)
	{
		//获取玩家行走之后的位置
		int position = goStep(player, map, step);
		//重新设置玩家位置
		player.setPlayerPos(position);
	}

	/*
	*函数：buyLand(Place place)
	*参数说明：place：想要购买的地块
	*功能：购买空地
	*返回值：bool
	*作者：王飞
	*/
	bool buyLand(Player player, Place place)
	{
		//玩家资产大于地价，进行买卖
		if (player.getPlayerAssets() > place.getPlacePrice())
		{
			cout << endl;
			cout << "你将花费 " << place.getPlacePrice() << "买去该地" << endl;
			cout << "请收好该地地址：(" << place.getPlaceX() << ", " << place.getPlaceY() << ")";

			int currentAssets = player.getPlayerAssets() - place.getPlacePrice();
			//玩家重新设置资产
			player.setPlayerAssets(currentAssets);
			//空地设置拥有者
			place.setPlaceOwner(&player);
			//地块设置属性----------------这里注意设置常量
			place.setPlaceType(1);
			//地块显示该地块级别符号
			place.setPlaceSign('0');
			place.setPlaceLevel(0);

			return true;
		}

		return false;
	}

	/*
	*函数： payForStay(Place place, Player player)
	*参数说明：place:地块，player：处于地块的玩家·
	*功能：停留他人购买地块之上，执行支付钱财的行为
	*返回值：bool
	*作者：王飞
	*/
	bool payForStay(Player player, Place place)
	{
		int placeLevel = 0;
		
		//停留他人地块费用
		int stayCost = (place.getPlacePrice() * (place.getPlaceLevel() + 1)) / 2;

		if (player.getPlayerAssets() > stayCost)
		{
			cout << endl;
				cout << "请向此地块拥有者：" << place.getPlaceOwnerName() <<
				"缴纳如下费用：" << stayCost << endl;

			int currAssets = player.getPlayerAssets() - stayCost;
			//重新设置财产
			player.setPlayerAssets(currAssets);
			//地块收费
			place.charge(stayCost);
			return true;
		}
		return false;
	}


	/*
	*函数： uppdatePlate(Place place)
	*参数说明：place:地块
	*功能：升级地块，最高升级3次
	*返回值：bool
	*作者：王飞
	*/
	bool uppdatePlate(Player player, Place place)
	{
		//此处可以分离出函数判断
		if (place.getPlaceLevel() > 3)
		{
			cout << "此地块已达到最高级别，不能再升级" << endl;
			return false;
		}
		if (player.getPlayerAssets() > place.getPlacePrice())
		{
			int currLevel = place.getPlaceLevel();
			cout << "当前你的地块级别为：" << currLevel << endl;
			cout << "你将花费：" << place.getPlacePrice() << "进行地块升级" << endl;

			//玩家重新设置资产
			int currAssets = player.getPlayerAssets() - place.getPlacePrice();
			player.setPlayerAssets(currAssets);

			//地块升级
			currLevel += 1;
			place.setPlaceLevel(currLevel);

			return true;
		}
		return false;
	}

	/*
	*函数：addPoints(Player player, int points)
	*参数说明：player,玩家，points此处矿地的点数
	*功能：停留矿地，增加点数
	*返回值：无
	*作者：王飞
	*/
	void addPoints(Player player, int points)
	{
		int currPoints = player.getPlayerPoints();
		player.setPlayerPoints(currPoints + points);
	}

	/*
	*函数： stayInDiffPlace(Player player, Place place)
	*参数说明：place:地块，player：处于地块的玩家·
	*功能：停留在不同地块之上，执行购买、支付钱财的行为
	*返回值：无
	*作者：王飞
	*/
	void stayInDiffPlace(Player player, Place place)
	{
		//获取地块类别
		int placeType = place.getPlaceType();
		//获取地块级别
		int placeLevel = place.getPlaceLevel();

		char *choice;
		
		switch (placeType)
		{
		//空地
		case 0:
				buyLand(player, place);
				break;
		case 1:
			//呆在别人地块,交费
			if (player.getPlayerName() != place.getPlaceOwnerName())
			{
				payForStay(player, place);
			}
			//呆在自己地块，可选择升级
			else
			{
				cout << "此处是你本人地块，请选择是否升级, y or n:" << endl;
				cin >> choice;
				if(strcmp(choice, "y") == 0)
				{ 
					uppdatePlate(player, place);
				}
		        
			}
			break;
		//呆在矿地
		case 2:
			addPoints(player, place.getPlacePrice());
			break;
		//呆在监狱
		case 3:
			break;
		default:
			break;
		}
	}

};

#endif