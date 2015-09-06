#include "player.h"

//��ѯӵ�еؿ����
int Player::getOwnPosNum()
{
	return ownPos.size();
}
//����Լ�ӵ�е�λ��
void Player::putOwnPos(int pos)
{
	ownPos.push_back(pos);
}

//��ѯ�Լ�����ӵ�еؿ�
void Player::printOwnPos()
{
	if (ownPos.size() == 0)
	{
		cout << "�޵ؿ��ʲ�" << endl;
		return;
	}
	cout << "ӵ�еؿ��ʲ���ţ�";
	vector<int>::iterator it;
	for (it = ownPos.begin(); it != ownPos.end(); ++it)
	{
		cout << *it << ",";
	}
	cout << endl;
}

//��ѯָ����ŵ�ӵ�еؿ� ,�ж��Ƿ����Լ��ĵؿ�
bool Player::isOwnPos(int pos)
{
	vector<int>::iterator it;
	for (it = ownPos.begin(); it != ownPos.end(); ++it)
	{
		if (*it = pos) return true;
	}
	return false;
}

void Player::deletePos(int pos)
{
	vector<int>::iterator ait;
	for (ait = ownPos.begin(); ait != ownPos.end(); ++ait)
	{
		if (*ait == pos)
		{
			ownPos.erase(ait);
			return;
		}
	}
}


vector<int> Player::getOwnPosContainer()
{
	return ownPos;
}
int Player::getPlayerPos()
{
	return position;
}

int Player::getPlayerAssets()
{
	return assets;
}

char Player::getPlayerSign()
{
	return playerSign;
}
unsigned short Player::getPlayerSignColor()
{
	return signColor;
}

int Player::getPlayerId()
{
	return playerId;
}

string Player::getPlayerName()
{
	return playerName;
}

int Player::getPlayerPoints()
{
	return points;
}

void Player::setPlayerAssets(int m_assets)
{
	assets = m_assets;
}

void Player::setPlayerSign(char sign)
{
	playerSign = sign;
}

void Player::setPlayerName(string name)
{
	playerName = name;
}

void Player::setPlayerPos(int pos)
{
	position = pos;
}

void Player::setPlayerPoints(int po)
{
	points = po;
}

void Player::setPlayerId(int id)
{
	playerId = id;
}