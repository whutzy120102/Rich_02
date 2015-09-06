#ifndef _PLACE_H_
#define _PLACE_H_

#include "player.h"
#include <vector>
#include<stack>

class Place
{
private:
	char placeSign;	//地块显示字符
	unsigned int level; //地块级别
	int placeType;	//地块的类型
	int placePrice;	//地块的价格

	stack<vector<Player>::iterator > stayPlayers;//驻留用户

	vector<Player>::iterator placeOwner;	//地块拥有者
	unsigned int x_place;	//地块x坐标
	unsigned int y_place;	//地块y坐标

public:
	Place() {}
	~Place() {}
	
	void setPlaceX(unsigned int x);
	void setPlaceY(unsigned int y);
	void setPlaceType(int type);
	void setPlaceOwner(vector<Player>::iterator it);
	void setPlaceSign(char sign);
	void setPlaceLevel(int m_level);
	void setPlacePrice(int price);
	/*
	*函数： getPlaceType()
	*参数说明：无
	*功能：获取地块属性
	*返回值：int: tyoe
	*作者：
	*/
	int getPlaceType();

	int getPlacePrice();
	unsigned int getPlaceLevel();

	unsigned int getPlaceX();
	unsigned int getPlaceY();
	char getPlaceSign();
	string getPlaceOwnerName();

	/**
	*函数:charge(int money)
	*参数说明：int:收费钱数
	*函数功能：地块收费
	*返回值：无
	*作者：王飞
	*/
	void charge(int money);

	//添加驻留玩家
	void pushStayPlayers(vector<Player>::iterator it);


	//获取最近驻留用户
	vector<Player>::iterator topStayPlayers();

	//出栈顶最近驻留用户
	void popStayPlayers();

	//驻留数
	int getStayPlayerNum();

};
#endif
