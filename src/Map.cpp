#include "map.h"
#include <iostream>
using namespace std;

Map::Map()
{

}

Map::~Map()
{
}

void Map::initMap()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 29; j++)
		{
			mapGraph[i][j] = ' ';
		}
	}

	init0();

	places[0].setPlaceSign('S');
	mapGraph[0][0] = places[0].getPlaceSign();

	
	//49
	places[10].setPlaceSign('P');
	mapGraph[7][14] = places[49].getPlaceSign();



	for (int i = 64; i < 70; i++)
	{
		places[i].setPlaceSign('$');

	}
	for (int i = 6; i > 0; i--)
	{
		mapGraph[i][0] = places[64].getPlaceSign();
	}


	initPlaceType();
	initPlaceLevel();
}

void Map::init0()//将地图上所有的点都初始化为空地
{
	int k = 0;

	for (int j = 0; j < 29; j++)
	{
		places[k].setPlaceSign('0');
		places[k].setPlacePrice(200);
		mapGraph[0][j] = places[k].getPlaceSign();
		k++;
	}
	for (int i = 1; i < 8; i++)
	{
		places[k].setPlaceSign('0');
		places[k].setPlacePrice(500);
		mapGraph[i][28] = places[k].getPlaceSign();
		k++;
	}
	for (int j = 27; j > -1; j--)
	{
		places[k].setPlaceSign('0');
		places[k].setPlacePrice(300);
		mapGraph[7][j] = places[k].getPlaceSign();
		k++;
	}
	for (int i = 6; i > 0; i--)
	{
		places[k].setPlaceSign('0');
		mapGraph[i][0] = places[k].getPlaceSign();
		k++;
	}
	places[64].setPlacePrice(20);
	places[65].setPlacePrice(80);
	places[66].setPlacePrice(100);
	places[67].setPlacePrice(40);
	places[68].setPlacePrice(80);
	places[69].setPlacePrice(60);
}

//char Map::getMapHereSign(int x, int y)
//{}
//
void Map::setMapHereSign(int x, int y, char sign)
{
	mapGraph[x][y] = sign;
}

//
void Map::printOwnerColor(int i)
{
	int type = places[i].getPlaceType();
	if (type == 1)
	{
		vector<Player>::iterator it = places[i].getPlaceOwner();
		unsigned short color = it->getPlayerSignColor();
		switch (color)
		{
		case 1: cout << greencolor << mapGraph[_X_Y_PLACE[i][0]][_X_Y_PLACE[i][1]]; break;
		case 2: cout << redcolor << mapGraph[_X_Y_PLACE[i][0]][_X_Y_PLACE[i][1]]; break;
		case 3: cout << yellowcolor << mapGraph[_X_Y_PLACE[i][0]][_X_Y_PLACE[i][1]]; break;
		case 4: cout << bluecolor << mapGraph[_X_Y_PLACE[i][0]][_X_Y_PLACE[i][1]]; break;
		default:
			break;
		}
	}
	else
	{
		cout << lredcolor << mapGraph[_X_Y_PLACE[i][0]][_X_Y_PLACE[i][1]];
	}
}

void Map::printMap()
{
	for (int i = 0; i < 29; ++i)
	{
		printOwnerColor(i);
		
	}
	cout << endl;
	for (int i = 1; i < 7; i++)
	{
		int c = 1;
		int begin = 69;
		
		printOwnerColor(begin - c);
		for (int j = 1; j < 28; j++)
		{
			char cur = mapGraph[i][j];
			cout <<lredcolor << cur;
		}
		printOwnerColor(i + 28);
		c++;
		begin--;
		cout << endl;
	}

	for (int i = 63; i > 34; --i)
	{
		printOwnerColor(i);
	}
	cout << endl;
}

//0：空地；1：占有；2：矿地， -1：原点
void Map::initPlaceType()
{
	for (int i = 1; i < 64; ++i)
	{
		places[i].setPlaceType(0);
	}
	for (int i = 64; i < 70; ++i)
	{
		places[i].setPlaceType(2);
	}
	places[0].setPlaceType(-1);
	places[POS_OF_PRISION].setPlaceType(2);
}

//设置地块的级别
void Map::initPlaceLevel()
{
	for (int i = 0; i < 70; ++i)
	{
		places[i].setPlaceLevel(0);
	}
}

//获取当前位置的符号
char Map::getMapHereSign(int position)
{
	return places[position].getPlaceSign();
}

int Map::getPlaceLevel(int pos)
{
	return places[pos].getPlaceLevel();
}

int Map::getPlaceType(int pos)
{
	return places[pos].getPlaceType();
}

//获取总的地块数
int Map::getPlaceNum()
{
	return PLACE_NUM;
}

//0：空地；1：占有；2：矿地， -1：原点
void Map::setPlaceType(int type, int pos)
{
	places[pos].setPlaceType(type);
}

//设置土地的级别：0：空地，1：一级：2：2级
void Map::setPlaceLevel(int level, int pos)
{
	places[pos].setPlaceLevel(level);
}

int Map::getPlacePrice(int pos)
{
	return places[pos].getPlacePrice();
}

void Map::setPlaceOwner(vector<Player>::iterator it, int pos)
{
	places[pos].setPlaceOwner(it);
}

void Map::setPlaceSign(char sign, int pos)
{
	places[pos].setPlaceSign(sign);
}

string Map::getPlaceOwnerName(int pos)
{
	return places[pos].getPlaceOwnerName();
}

void Map::charge(int stayCost, int pos)
{
	places[pos].charge(stayCost);
}


//重新设置玩家相关地图
void Map::cleanMapOfPlayer(vector<Player>::iterator it)
{
	int pos_one = it->getPlayerPos();
	vector<int> pos = it->getOwnPosContainer();
	vector<int>::iterator ait;
	pos.push_back(pos_one);
	/*for (ait = pos.begin(); ait != pos.end(); ++ait)
	{
		int tempPos = *ait;
		int type = getPlaceType(tempPos);
		if (type == -1)
		{
			setMapHereSign(_X_Y_PLACE[tempPos][0], _X_Y_PLACE[tempPos][1], 'S');
		}
		else if (type = 2)
		{
			setMapHereSign(_X_Y_PLACE[tempPos][0], _X_Y_PLACE[tempPos][1], '$');
		}
		else
		{
			setMapHereSign(_X_Y_PLACE[tempPos][0], _X_Y_PLACE[tempPos][1], '0');
			setPlaceLevel(tempPos, 0);
			setPlaceSign(tempPos, '0');
		}

	}*/
}

//驻留数
bool Map::isStayEmpty(int pos)
{
	return places[pos].isStayEmpty();
}

vector<vector<Player>::iterator>::iterator Map::topHerePlayer(int pos)
{
	return places[pos].topStayPlayers();
}

void Map::popHerePlayer(vector<Player>::iterator it, int pos)
{
	places[pos].popStayPlayers(it);
}
void Map::pushHerePlayer(vector<Player>::iterator it, int pos)
{
	places[pos].pushStayPlayers(it);
}