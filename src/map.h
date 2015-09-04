#ifndef _MAP_H_
#define _MAP_H_
#include "place.h"
//地图宽高
const int WIDTH = 29;
const int HEIGHT = 8;
class Map
{
private:
	Place places[70];
	char mapGraph[HEIGHT][WIDTH];	//存储地图数组
	void init0();

public:
	Map();
	~Map();

	/*
	*函数：initMap()
	*参数说明：无
	*功能：初始化地图
	*返回值：无
	*作者：
	*/
	void initMap();

	/*
	*函数：setMapHereSign(int x, int y, char sign)
	*参数说明：x,y坐标位置；sign设置地图显示符号
	*功能：设置坐标为x,y的地图位置显示为制定字符
	*返回值：无
	*作者：
	*/
	void setMapHereSign(int x, int y, char sign);

	/*
	*函数：getMapHereSign(int x, in y)
	*参数说明：x,y坐标位置
	*功能：获取x,y坐标下的字符
	*返回值：char:显示字符
	*作者：
	*/
	char getMapHereSign(int x, int y);

	/*
	*函数： printMap()
	*参数说明：无
	*功能：打印地图
	*返回值：无
	*作者：
	*/
	void printMap();



	/*************************此处添加没有的代码*************************/
	int getPlaceNum()
	{
		return 10;
	}
};
#endif
