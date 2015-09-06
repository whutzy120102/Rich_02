#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "player.h"
#include "map.h"
#include "playerAction.h"
#include "function.h"
const int MIN_STEP = 1;
const int MAX_STEP = 6;
const int MAX_COMMAND_SIZE = 10; //����������������
/**
*����������
*/

class Command
{
private:
	char command[MAX_COMMAND_SIZE];
	PlayerAction *action;
	//Player *player;
	//Place *place;
	//Map *map;
public:
	Command() 
	{
		action = new PlayerAction;
	}
	~Command() {}

	/*
	*������help()
	*����˵����
	*���ܣ�����˵�������ʹ��
	*����ֵ����
	*���ߣ�
	*/
	void help();


	/*
	*������roll()
	*����˵����
	*���ܣ�������
	*����ֵ����
	*���ߣ�
	*/
	int roll();

	/*
	*������sell()
	*����˵����Player player, Place place, int position
	*���ܣ�������ҵķ���
	*����ֵ����
	*���ߣ�
	*/
	void sell(vector<Player>::iterator it, Map *map);

	/*
	*������query()
	*����˵������Player player
	*���ܣ���ѯ����ʲ���Ϣ
	*����ֵ����
	*���ߣ�
	*/
	void query(vector<Player>::iterator it);

	//Player player, Map map
	void exit(vector<Player>::iterator it, Map *map);

	//��ȡСд����
	char* getLowerCommand();

	//ִ������
	int goCommand(vector<Player>::iterator it, Map *map);

	//�ж��������
	bool equalCommand(char *m, char *m_m);

	//ǿ��
	void quit();

};
#endif