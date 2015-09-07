#ifndef _PLAYER_ACTION_H_
#define _PLAYER_ACTION_H_

#include "player.h"
#include "place.h"
#include "map.h"
#include <vector>

class PlayerAction
{

public:


	//离开当前位置后
	static void levPlace(vector<Player>::iterator it, Map *map)
	{
		int currentPos = it->getPlayerPos();
		int x = _X_Y_PLACE[currentPos][0];
		int y = _X_Y_PLACE[currentPos][1];
		map->setMapHereSign(x, y, map->getMapHereSign(currentPos));
		
	}
	/*
	*函数：goStep(int step)
	*参数说明：step玩家掷骰子获得的点数，即行走步数
	*功能：玩家按点数行走
	*返回值：int:当前位置
	*作者：王飞
	*/
	static int goStep(vector<Player>::iterator it, Map *map, int step)
	{
		int currentPos = it->getPlayerPos();
		//玩家循环行走
		currentPos = (currentPos + step) % (map->getPlaceNum());
		//此处设置地图显示符号
		int x = _X_Y_PLACE[currentPos][0];
		int y = _X_Y_PLACE[currentPos][1];
		map->pushHerePlayer(it, currentPos);
		map->setMapHereSign(x, y, it->getPlayerSign());
		return currentPos;
	}

	/*
	*函数：resetPlayerPos(int step)
	*参数说明：step玩家掷骰子获得的点数，即行走步数
	*功能：重新设置用户位置
	*返回值：int:玩家位置
	*作者：王飞
	*/
	static void resetPlayerPos(vector<Player>::iterator it, Map *map, int step)
	{
		//获取玩家行走之后的位置
		int position = goStep(it, map, step);
		//重新设置玩家位置
		it->setPlayerPos(position);
	}

	/*
	*函数：buyLand(Place place)
	*参数说明：place：想要购买的地块
	*功能：购买空地
	*返回值：bool
	*作者：王飞
	*/
	static bool buyLand(vector<Player>::iterator it, Map *map, int pos)
	{
		//玩家资产大于地价，进行买卖
		if (it->getPlayerAssets() >= map->getPlacePrice(pos))
		{
			cout << "请收好该地地址：(" << _X_Y_PLACE[pos][0] << ", " << _X_Y_PLACE[pos][1] << ")";

			int currentAssets = it->getPlayerAssets() - map->getPlacePrice(pos);
			//玩家重新设置资产
			it->setPlayerAssets(currentAssets);
			//添加地块
			it->putOwnPos(pos);
			//空地设置拥有者
			map->setPlaceOwner(it, pos);
			//地块设置属性----------------这里注意设置常量
			map->setPlaceType(1, pos);
			//地块显示该地块级别符号
			map->setPlaceSign('0', pos);
			map->setPlaceLevel(0, pos);

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
	static bool payForStay(vector<Player>::iterator it, Map *map, int pos)
	{
		int placeLevel = 0;
		
		//停留他人地块费用
		int stayCost = (map->getPlacePrice(pos) * (map->getPlaceLevel(pos) + 1)) / 2;

		if (it->getPlayerAssets() >= stayCost)
		{
			cout << endl;
				cout << "请向此地块拥有者：" << map->getPlaceOwnerName(pos) <<
				"缴纳如下费用：" << stayCost << endl;

			int currAssets = it->getPlayerAssets() - stayCost;
			//重新设置财产
			it->setPlayerAssets(currAssets);
			//地块收费
			map->charge(stayCost, pos);
			return true;
		}
		else
		{
			cout << "请先出售地块来支付停留费用";
			queryAssets(it);
			if (it->getOwnPosNum() != 0)
			{
				sellPlace(it, map);
				payForStay(it, map, pos);
			}
			else return false;
			
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
	static bool uppdatePlate(vector<Player>::iterator it, Map *map, int pos)
	{
		//此处可以分离出函数判断
		if (map->getPlaceLevel(pos) > 3)
		{
			cout << "此地块已达到最高级别，不能再升级" << endl;
			return false;
		}
		if (it->getPlayerAssets() >= map->getPlacePrice(pos))
		{
			int currLevel = map->getPlaceLevel(pos);
			cout << "当前你的地块级别为：" << currLevel << endl;
			cout << "你将花费：" << map->getPlacePrice(pos) << "进行地块升级" << endl;

			//玩家重新设置资产
			int currAssets = it->getPlayerAssets() - map->getPlacePrice(pos);
			it->setPlayerAssets(currAssets);

			//地块升级
			currLevel += 1;
			map->setPlaceLevel(currLevel, pos);

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
	static void addPoints(vector<Player>::iterator it, int points)
	{
		int currPoints = it->getPlayerPoints();
		it->setPlayerPoints(currPoints + points);
	}

	/*
	*函数： stayInDiffPlace(Player player, Place place)
	*参数说明：place:地块，player：处于地块的玩家·
	*功能：停留在不同地块之上，执行购买、支付钱财的行为
	*返回值：无
	*作者：王飞
	*/
	static bool stayInDiffPlace(vector<Player>::iterator it, Map *map, int pos)
	{
		bool doAction = false;
		//获取地块类别
		int placeType = map->getPlaceType(pos);
		//获取地块级别
		int placeLevel = map->getPlaceLevel(pos);

		char choice = 'n'; 
		
		switch (placeType)
		{
		//空地
		case 0:
			    char isBuy;
				cout << endl;
				cout << "此处是空地，请选择是否购买" << endl;
				cin >> isBuy;
				if (isBuy == 'y')
				{
					cout << "你将花费 " << map->getPlacePrice(pos) << "买去该地" << endl;
					doAction = buyLand(it, map, pos);
					if (!doAction)
					{
						queryAssets(it);
						cout << "你没有足够的资金买这块土地" << endl;
					}
				}
				
				break;
		case 1:
			//呆在别人地块,交费
			if (it->getPlayerName() != map->getPlaceOwnerName(pos))
			{
				doAction = payForStay(it, map, pos);
			}
			//呆在自己地块，可选择升级
			else
			{
				cout << "此处是你本人地块，请选择是否升级, y or n:" << endl;
				cin >> choice;
				if(choice == 'y')
				{ 
					doAction = uppdatePlate(it, map, pos);
				}
		        
			}
			break;
		//呆在矿地
		case 2:
			addPoints(it, map->getPlacePrice(pos));
			doAction = true;
			break;
		//呆在监狱
		case 3:
			cout << "真不幸运，你来到魔鬼监狱，你将轮空操作两次" << endl;
			it->setNoActionTimes(NO_ACTION_PRISION_TIMES);
			break;
		default:
			break;
		}
		return doAction;
	}

	//查询用户资产
	static void queryAssets(vector<Player>::iterator it)
	{
		cout << "你当前资产如下：" << endl;
		cout << "钱财：" << it->getPlayerAssets() << endl
			<< "点数：" << it->getPlayerPoints() << endl
			<< "拥有地块：";
		it->printOwnPos();
		cout << endl;
	}

	//查询是否还有资产
	static bool isNoAssets(vector<Player>::iterator it)
	{
		if (it->getOwnPosNum() == 0 && it->getPlayerAssets() == 0)
			return true;
		return false;
	}

	//出售房产
	static bool sellPlace(vector<Player>::iterator it, Map *map)
	{
		int pos;
		cout << "请输入要出售地块编号" << endl;
		cin >> pos;
		if (it->isOwnPos(pos))
		{
			cout << "你将出售编号为" << pos << "的地块" << endl;
			cout << "收益：" << (map->getPlaceLevel(pos) + 1) * map->getPlacePrice(pos) << endl;
			cout << "请选择: y or n";
			char choice;
			cin >> choice;
			if (choice == 'y')
			{
				int currAssets = it->getPlayerAssets();
				int inCome = (map->getPlaceLevel(pos) + 1) * map->getPlacePrice(pos);
				it->setPlayerAssets(currAssets + inCome);
				it->deletePos(pos);
				map->setMapHereSign(_X_Y_PLACE[pos][0], _X_Y_PLACE[pos][1], '0');
				map->setPlaceLevel(pos, 0);
				map->setPlaceType(pos, 0);
				map->setPlaceSign(pos, '0');
			}
			else
				return true;
		}
		else
		{
			cout << "这里并不是你的地盘，你这样做可能招来横祸" << endl;
		}
		return false;
	}
	
	//设置轮空次数
	static void setNoActionTimes(vector<Player>::iterator it, int times)
	{
		it->setNoActionTimes(times);
	}

	//获取轮空次数
	static int getNoActionTimes(vector<Player>::iterator it)
	{
		return it->getNoActionTimes();
	}

};

#endif