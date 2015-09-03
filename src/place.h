#ifndef _PLACE_H_
#define _PLACE_H_

#include "player.h"
class Place 
{
private:
	char sign;	//地块显示字符
	unsigned int type;	//地块的类型
	int price;	//地块的价格
	Player owner;	//地块拥有者
	unsigned int x;	//地块x坐标
	unsigned int y;	//地块y坐标

public:

	/*
	*函数： setPlaceType(Player player)
	*参数说明：player:地块拥有者
	*功能：设置地块属性：0，空地；1，一级；2，二级；3，三级
	*返回值：无
	*作者：
	*/
	void setPlaceType(Player player);

	/*
	*函数： getPlaceType()
	*参数说明：无
	*功能：获取地块属性
	*返回值：int: tyoe
	*作者：
	*/
	int getPlaceType();
};
#endif

