#include "playerAction.h"


/*
*函数：goStep(int step)
*参数说明：step玩家掷骰子获得的点数，即行走步数
*功能：玩家按点数行走
*返回值：int:当前位置
*作者：
*/
int PlayerAction::goStep(Player player, Map map, int step)
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
*作者：
*/
void PlayerAction::resetPlayerPos(Player player, Map map, int step)
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
*返回值：无
*作者：
*/
bool PlayerAction::buyLand(Player player, Place place)
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
//		place.setPlaceOwner(player);
		//地块设置属性----------------这里注意设置常量
		place.setPlaceType(1);
		//地块显示该玩家符号
		place.setPlaceSign(player.getPlayerSign());

		return true;
	}

	return false;
}

/*
*函数： payForStay(Place place, Player player)
*参数说明：place:地块，player：处于地块的玩家·
*功能：停留他人购买地块之上，执行支付钱财的行为
*返回值：无
*作者：王飞
*/
bool PlayerAction::payForStay(Place place, Player player) 
{
	//停留他人地块费用
	int stayCost = (place.getPlacePrice() * place.getPlaceType()) / 2;

	if (player.getPlayerAssets() > stayCost)
	{
		cout << endl;
	//	cout << "请向此地块拥有者：" << place.getPlaceOwnerName() <<
		//	"缴纳如下费用：" << stayCost << endl;

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
*返回值：无
*作者：王飞
*/
bool PlayerAction::uppdatePlate(Player player, Place place)
{
	//此处可以分离出函数判断
	if (place.getPlaceType() > 3) return false;
	if (player.getPlayerAssets() > place.getPlacePrice())
	{
		int currType = place.getPlaceType();
		cout << "当前你的地块级别为：" << currType << endl;
		cout << "你将花费：" << place.getPlacePrice() << "进行地块升级" << endl;

		//玩家重新设置资产
		int currAssets = player.getPlayerAssets() - place.getPlacePrice();
		player.setPlayerAssets(currAssets);

		//地块升级
		currType += 1;
		place.setPlaceType(currType);

		return true;
	}
	return false;
}


/*
*函数： stayInDiffPlace(Place place, Player player)
*参数说明：place:地块，player：处于地块的玩家·
*功能：停留在不同地块之上，执行购买、支付钱财的行为
*返回值：无
*作者：
*/
void stayInDiffPlace(Place place, Player player);