#include "Map.h"
#include <iostream>
using namespace std;

Map::Map()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 29; j++)
		{
			mapGraph[i][j] = ' ';
		}
	}
}


Map::~Map()
{
}

void Map::initMap()
{
	init0();
	
	places[0].setSign('S');
	mapGraph[0][0] = places[0].getSign();

	places[14].setSign('H');
	mapGraph[0][14] = places[14].getSign();

	places[28].setSign('T');
	mapGraph[0][28] = places[28].getSign();

	places[35].setSign('G');
	mapGraph[7][28] = places[35].getSign();

	places[49].setSign('P');
	mapGraph[7][14] = places[49].getSign();

	places[63].setSign('M');
	mapGraph[7][0] = places[63].getSign();


	for (int i = 64; i < 70; i++)
	{
		places[i].setSign('$');
		
	}
	for (int i = 6; i > 0; i--)
	{
		mapGraph[i][0] = places[64].getSign();
	}
	
}

void Map::init0()//将地图上所有的点都初始化为空地
{
	int k = 0;

	for (int j = 0; j < 29; j++)
	{
		places[k].setSign('0');
		mapGraph[0][j] = places[k].getSign();
		k++;
	}
	for (int i = 1; i < 8; i++)
	{
		places[k].setSign('0');
		mapGraph[i][28] = places[k].getSign();
		k++;
	}
	for (int j = 27; j > -1; j--)
	{
		places[k].setSign('0');
		mapGraph[7][j] = places[k].getSign();
		k++;
	}
	for (int i = 6; i > 0; i--)
	{
		places[k].setSign('0');
		mapGraph[i][0] = places[k].getSign();
		k++;
	}
}

//char Map::getMapHereSign(int x, int y)
//{}
//
//void Map::setMapHereSign(int x, int y, char sign)
//{}

void Map::printMap()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 29; j++)
		{
			cout << mapGraph[i][j];
		}
		cout << endl;
	}
}
