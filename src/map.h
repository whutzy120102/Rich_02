#ifndef _MAP_H_
#define _MAP_H_
#include "place.h"
//地图宽高
const int WIDTH = 29;
const int HEIGHT = 8;
//坐标地块对应关系
const int _X_Y_PLACE[70][2] = {
	{0,0},{0,1},{0,2},{0,3},{0,4},{0,5},{0,6},{0,7},{0,8},{0,9},
	{0,10},{0,11},{0,12},{0,13},{0,14},{0,15},{0,16},{0,17},{0,18},{0,19},
	{0,20},{0,21},{0,22},{0,23},{0,24},{0,25},{0,26},{0,27},{0,28},
	{1,28},{2,28},{3,28},{4,28},{5,28},{6,28},
	{7,28},{7,27},{7,26},{7,25},{7,24},{7,23},{7,22},{7,21},{7,20},
	{7,19},{7,18},{7,17},{7,16},{7,15},{7,14},{7,13},{7,12},{7,11},{7,10},
	{7,9},{7,8},{7,7},{7,6},{7,5},{7,4},{7,3},{7,2},{7,1},{7,0},
	{6,0},{5,0},{4,0},{3,0},{2,0},{1,0}
};

//在监狱中轮空次数
const int NO_ACTION_PRISION_TIMES = 3;

class Map
{
private:
	Place places[70];
	char mapGraph[HEIGHT][WIDTH];	//存储地图数组
	void init0();
	const int POS_OF_PRISION = 10;
	const int PLACE_NUM = 70;

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
	char getMapHereSign(int position);

	/*
	*函数： printMap()
	*参数说明：无
	*功能：打印地图
	*返回值：无
	*作者：
	*/
	void printMap();

	//获取总的地块数
	int getPlaceNum();

	int getPlaceType(int positio);

	int getPlaceLevel(int position);

	//初始化地块类型
	void initPlaceType();
	//初始化地块级别
	void initPlaceLevel();

	//0：空地；1：占有；2：矿地， -1：原点
	void setPlaceType(int type, int pos);

	//设置土地的级别：0：空地，1：一级：2：2级
	void setPlaceLevel(int level, int pos);

	int getPlacePrice(int pos);

	void setPlaceOwner(vector<Player>::iterator it, int pos);
	
	void setPlaceSign(char sign, int pos);

	string getPlaceOwnerName(int pos);

	void charge(int stayCost, int pos);

	//重新设置玩家相关信息
	void cleanMapOfPlayer(vector<Player>::iterator it);

	//驻留数
	int getHerePlayerNum(int pos);
	
	vector<Player>::iterator topHerePlayer(int pos);
	void popHerePlayer(int pos);

	void pushHerePlayer(vector<Player>::iterator it, int pos);


};
#endif

