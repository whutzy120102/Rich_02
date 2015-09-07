/**
*������Ϸ��
*/
#ifndef _GAME_H_
#define _GAME_H_

#include "map.h"
#include "player.h"
#include "command.h"
#include "function.h"
#include <vector>


const int MAX_PLAYER_NUM = 5;	//��������������
const int MIN_PLAYER_NUM = 2;	//��С�����������
//�ɹ�ѡ������

const string STAY_PLAYERS[MAX_PLAYER_NUM] ={ "Ǯ����", "������", "��С��","�𱴱�" };
const char PLAYER_SIGN[MAX_PLAYER_NUM] = { 'Q', 'A', 'S', 'J' };


class Game
{
private:
	Map *map;
	vector<Player> players;
	Command *command;
	int playerNum;
	int defaultMoney;	//Ĭ�ϳ�ʼ���ʲ�

public:
	Game()
	{
		command = new Command();
		map = new Map();
		playerNum = 0;
		defaultMoney = 0;
	}

	~Game()
	{
		delete command;
		delete map;
		players.clear();
	}

	//���ó�ʼ�ʽ�
	void setDefalutMoney();

	/*
	*������initPlayer()
	*����˵����
	*���ܣ���ʼ����ң�������ҵ��ʽ�λ��
	*����ֵ����
	*���ߣ�
	*/
	void initPlayer();



	/*
	*������initGame()
	*����˵����
	*���ܣ���ʼ����ͼ�����
	*����ֵ����
	*���ߣ�
	*/
	void initGame();

	/*
	*������destroyPlayer()
	*����˵����
	*���ܣ����ٵ�ͼ
	*����ֵ����
	*���ߣ�
	*/
	void destroyGame();

	/*
	*������quitGame()
	*����˵����
	*���ܣ���ֹ��Ϸ
	*����ֵ����
	*���ߣ�
	*/
	void quitGame();

	/*
	*������addPlayer()
	*����˵����
	*���ܣ�������
	*����ֵ����
	*���ߣ�
	*/
	void addPlayer(Player player);


	//�������������ص�ͼ
	void cleanMapOfPlayer(vector<Player>::iterator it, Map *map);

	//����������
	void cleanPlayer(vector<Player>::iterator it);

	/*
	*������deletePlayer()
	*����˵����
	*���ܣ�ɾ�����
	*����ֵ����
	*���ߣ�
	*/
	vector<Player>::iterator deletePlayer(vector<Player>::iterator it);

	//��Ϸ����,��Ҫ�������һ�θ��ֲ���
	void goGameBody();

	//ִ����Ϸ���ٴη�װ��Ϸ
	void goGame();

	//ѡ�����
	void choicePlayer(char *input);

	//�������Ƿ����
	bool isExistPlayer(char *input);

	//�����������Ƿ��ظ�
	bool isInputPlayer(char *input);


	//�������
	void getPlayerInput(char *input);

	//��������
	void getCommandInput(char *input);

	//ˢ�µ�ͼ
	void Game::flushMap();

	
};

#endif