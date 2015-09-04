#ifndef _PLACE_H_
#define _PLACE_H_

#include "player.h"

class Place
{
private:
	char placeSign;	//地块显示字符
	unsigned int level; //地块级别
	unsigned int placeType;	//地块的类型
	int placePrice;	//地块的价格

	Player placeOwner;	//地块拥有者
	unsigned int x_place;	//地块x坐标
	unsigned int y_place;	//地块y坐标

public:

	/*
	*函数： setPlaceType(Player player)
	*参数说明：player:地块拥有者
	*功能：设置地块属性：0，空地；1，一级；2，二级；3，三级
	*返回值：无
	*作者：
	*/
	void setPlaceType(int type);
	void setPlaceOwner(Player player);
	void setPlaceSign(char sign);
	void setPlaceLevel(int m_level);
	/*
	*函数： getPlaceType()
	*参数说明：无
	*功能：获取地块属性
	*返回值：int: tyoe
	*作者：
	*/
	int getPlaceType();

	int getPlacePrice();
	int getPlaceLevel();

	unsigned int getPlaceX();
	unsigned int getPlaceY();
	char getPlaceSign();
	string getPlaceOwnerName();
	//地块收费
	void charge(int money);

};
#endif
