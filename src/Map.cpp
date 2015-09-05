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

	places[14].setPlaceSign('H');
	mapGraph[0][14] = places[14].getPlaceSign();

	places[28].setPlaceSign('T');
	mapGraph[0][28] = places[28].getPlaceSign();

	places[35].setPlaceSign('G');
	mapGraph[7][28] = places[35].getPlaceSign();

	places[49].setPlaceSign('P');
	mapGraph[7][14] = places[49].getPlaceSign();

	places[63].setPlaceSign('M');
	mapGraph[7][0] = places[63].getPlaceSign();


	for (int i = 64; i < 70; i++)
	{
		places[i].setPlaceSign('$');
		
	}
	for (int i = 6; i > 0; i--)
	{
		mapGraph[i][0] = places[64].getPlaceSign();
	}
	
}

void Map::init0()//将地图上所有的点都初始化为空地
{
	int k = 0;

	for (int j = 0; j < 29; j++)
	{
		places[k].setPlaceSign('0');
		mapGraph[0][j] = places[k].getPlaceSign();
		k++;
	}
	for (int i = 1; i < 8; i++)
	{
		places[k].setPlaceSign('0');
		mapGraph[i][28] = places[k].getPlaceSign();
		k++;
	}
	for (int j = 27; j > -1; j--)
	{
		places[k].setPlaceSign('0');
		mapGraph[7][j] = places[k].getPlaceSign();
		k++;
	}
	for (int i = 6; i > 0; i--)
	{
		places[k].setPlaceSign('0');
		mapGraph[i][0] = places[k].getPlaceSign();
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
