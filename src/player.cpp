#include "player.h"

//查询拥有地块个数
int Player::getOwnPosNum()
{
	return ownPos.size();
}
//添加自己拥有的位置
void Player::putOwnPos(int pos)
{
	ownPos.push_back(pos);
}

//查询自己所有拥有地块
void Player::printOwnPos()
{
	if (ownPos.size() == 0)
	{
		cout << "无地块资产" << endl;
		return;
	}
	cout << "拥有地块资产编号：";
	vector<int>::iterator it;
	for (it = ownPos.begin(); it != ownPos.end(); ++it)
	{
		cout << *it << ",";
	}
	cout << endl;
}

//查询指定编号的拥有地块 ,判断是否是自己的地块
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