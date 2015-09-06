#ifndef _PLAYER_H_
#define _PLAYER_H_

/**
*���������
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player {
private:
	string playerName;	//�������
	int playerId;		//���ID
	vector<int> ownPos;
	int assets;		//�ʲ�,Ĭ��10000����ʼΪ10000
					//	int fixedAssets;	//�̶��ʲ�
	int points;		//��ҿ��õ���

	unsigned int position;	//���λ��
	char playerSign;	//�����ʾ����
	unsigned short signColor;	//�����ʾ��ɫ

public:
	Player(string m_name, int m_id, char m_sign) :
		playerName(m_name), playerId(m_id),playerSign(m_sign) {
		assets = 0;
		points = 0;
		position = 0;
	}
	~Player() {}

	//��ѯӵ�еؿ����
	int getOwnPosNum();

	//����Լ�ӵ�е�λ��
	void putOwnPos(int pos);

	//��ѯ�Լ�����ӵ�еؿ�
	void printOwnPos();

	//��ѯָ����ŵ�ӵ�еؿ� ,�ж��Ƿ����Լ��ĵؿ�
	bool isOwnPos(int pos);

	void deletePos(int pos);

	vector<int> getOwnPosContainer();

	int getPlayerPos();

	int getPlayerAssets();

	char getPlayerSign();

	unsigned short getPlayerSignColor();

	int getPlayerId();

	string getPlayerName();

	int getPlayerPoints();

	void setPlayerAssets(int m_assets);

	void setPlayerSign(char sign);

	void setPlayerName(string name);

	void setPlayerPos(int pos);

	void setPlayerPoints(int po);

	void setPlayerId(int id);
};

#endif