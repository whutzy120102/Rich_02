#include "place.h"

void Place::setPlaceX(unsigned int x)
{
	x_place = x;
}

void Place::setPlaceY(unsigned int y)
{
	y_place = y;
}

/**
*函数:setPlaceType(int type)
*参数说明：整型：
*函数功能：设置地块类型
		0：空地；1：占有；2：矿地；3：监狱
*返回值：无
*作者：王飞
*/
void Place::setPlaceType(int type)
{
	placeType = type;
}

void Place::setPlaceOwner(Player* player)
{
	placeOwner = player;
}

/**
*函数:setPlaceSign(char sign)
*参数说明：char
*函数功能：设置显示字符
     0：空地；1：一级地块；2：2级地块；3：3级地块
*返回值：无
*作者：王飞
*/
void Place::setPlaceSign(char sign)
{
	placeSign = sign;
}

/**
*函数:setPlaceLevel(int m_level)
*参数说明：m_level:级别数
*函数功能：设置地块级别
*返回值：无
*作者：王飞
*/
void Place::setPlaceLevel(int m_level)
{
	level = m_level;
}

void Place::setPlacePrice(int price)
{
	placePrice = price;
}

int Place::getPlaceType()
{
	return placeType;
}

int Place::getPlacePrice()
{
	return placePrice;
}

int Place::getPlaceLevel()
{
	return level;
}

unsigned int Place::getPlaceX()
{
	return x_place;
}

unsigned int Place::getPlaceY()
{
	return y_place;
}

char Place::getPlaceSign()
{
	return placeSign;
}

string Place::getPlaceOwnerName()
{
	return placeOwner->getPlayerName();
}

/**
*函数:charge(int money)
*参数说明：int:收费钱数
*函数功能：地块收费,拥有者收益
*返回值：无
*作者：王飞
*/
void Place::charge(int money)
{
	int currAssets = placeOwner->getPlayerAssets();
	placeOwner->setPlayerAssets(currAssets + money);
}