#ifndef _PLAYER_ACTION_H_
#define _PLAYER_ACTION_H_

#include "player.h"
#include "place.h"
#include "map.h"
#include <vector>

class PlayerAction
{

public:


	//�뿪��ǰλ�ú�
	static void levPlace(vector<Player>::iterator it, Map *map)
	{
		int currentPos = it->getPlayerPos();
		int x = _X_Y_PLACE[currentPos][0];
		int y = _X_Y_PLACE[currentPos][1];
	/*	if (!map->isStayEmpty(currentPos))
		{
			vector<vector<Player>::iterator>::iterator ait;
			map->popHerePlayer(it, currentPos);
			ait = map->topHerePlayer(currentPos);
			map->setMapHereSign(x, y, (*ait)->getPlayerSign());
			
		}*/
		//else 
		//{
			map->setMapHereSign(x, y, map->getMapHereSign(currentPos));
		//}
	}
	/*
	*������goStep(int step)
	*����˵����step��������ӻ�õĵ����������߲���
	*���ܣ���Ұ���������
	*����ֵ��int:��ǰλ��
	*���ߣ�����
	*/
	static int goStep(vector<Player>::iterator it, Map *map, int step)
	{
		int currentPos = it->getPlayerPos();
		//���ѭ������
		currentPos = (currentPos + step) % (map->getPlaceNum());
		//�˴����õ�ͼ��ʾ����
		int x = _X_Y_PLACE[currentPos][0];
		int y = _X_Y_PLACE[currentPos][1];
		map->pushHerePlayer(it, currentPos);
		map->setMapHereSign(x, y, it->getPlayerSign());
		return currentPos;
	}

	/*
	*������resetPlayerPos(int step)
	*����˵����step��������ӻ�õĵ����������߲���
	*���ܣ����������û�λ��
	*����ֵ��int:���λ��
	*���ߣ�����
	*/
	static void resetPlayerPos(vector<Player>::iterator it, Map *map, int step)
	{
		//��ȡ�������֮���λ��
		int position = goStep(it, map, step);
		//�����������λ��
		it->setPlayerPos(position);
	}

	/*
	*������buyLand(Place place)
	*����˵����place����Ҫ����ĵؿ�
	*���ܣ�����յ�
	*����ֵ��bool
	*���ߣ�����
	*/
	static bool buyLand(vector<Player>::iterator it, Map *map, int pos)
	{
		//����ʲ����ڵؼۣ���������
		if (it->getPlayerAssets() >= map->getPlacePrice(pos))
		{
			cout << "���պøõص�ַ��(" << _X_Y_PLACE[pos][0] << ", " << _X_Y_PLACE[pos][1] << ")";

			int currentAssets = it->getPlayerAssets() - map->getPlacePrice(pos);
			//������������ʲ�
			it->setPlayerAssets(currentAssets);
			//��ӵؿ�
			it->putOwnPos(pos);
			//�յ�����ӵ����
			map->setPlaceOwner(it, pos);
			//�ؿ���������----------------����ע�����ó���
			map->setPlaceType(1, pos);
			//�ؿ���ʾ�õؿ鼶�����
			map->setPlaceSign('0', pos);
			map->setPlaceLevel(0, pos);

			return true;
		}

		return false;
	}

	/*
	*������ payForStay(Place place, Player player)
	*����˵����place:�ؿ飬player�����ڵؿ����ҡ�
	*���ܣ�ͣ�����˹���ؿ�֮�ϣ�ִ��֧��Ǯ�Ƶ���Ϊ
	*����ֵ��bool
	*���ߣ�����
	*/
	static bool payForStay(vector<Player>::iterator it, Map *map, int pos)
	{
		int placeLevel = 0;
		
		//ͣ�����˵ؿ����
		int stayCost = (map->getPlacePrice(pos) * (map->getPlaceLevel(pos) + 1)) / 2;

		if (it->getPlayerAssets() >= stayCost)
		{
			cout << endl;
				cout << "����˵ؿ�ӵ���ߣ�" << map->getPlaceOwnerName(pos) <<
				"�������·��ã�" << stayCost << endl;

			int currAssets = it->getPlayerAssets() - stayCost;
			//�������òƲ�
			it->setPlayerAssets(currAssets);
			//�ؿ��շ�
			map->charge(stayCost, pos);
			return true;
		}
		return false;
	}


	/*
	*������ uppdatePlate(Place place)
	*����˵����place:�ؿ�
	*���ܣ������ؿ飬�������3��
	*����ֵ��bool
	*���ߣ�����
	*/
	static bool uppdatePlate(vector<Player>::iterator it, Map *map, int pos)
	{
		//�˴����Է���������ж�
		if (map->getPlaceLevel(pos) > 3)
		{
			cout << "�˵ؿ��Ѵﵽ��߼��𣬲���������" << endl;
			return false;
		}
		if (it->getPlayerAssets() >= map->getPlacePrice(pos))
		{
			int currLevel = map->getPlaceLevel(pos);
			cout << "��ǰ��ĵؿ鼶��Ϊ��" << currLevel << endl;
			cout << "�㽫���ѣ�" << map->getPlacePrice(pos) << "���еؿ�����" << endl;

			//������������ʲ�
			int currAssets = it->getPlayerAssets() - map->getPlacePrice(pos);
			it->setPlayerAssets(currAssets);

			//�ؿ�����
			currLevel += 1;
			map->setPlaceLevel(currLevel, pos);

			return true;
		}
		return false;
	}

	/*
	*������addPoints(Player player, int points)
	*����˵����player,��ң�points�˴���صĵ���
	*���ܣ�ͣ����أ����ӵ���
	*����ֵ����
	*���ߣ�����
	*/
	static void addPoints(vector<Player>::iterator it, int points)
	{
		int currPoints = it->getPlayerPoints();
		it->setPlayerPoints(currPoints + points);
	}

	/*
	*������ stayInDiffPlace(Player player, Place place)
	*����˵����place:�ؿ飬player�����ڵؿ����ҡ�
	*���ܣ�ͣ���ڲ�ͬ�ؿ�֮�ϣ�ִ�й���֧��Ǯ�Ƶ���Ϊ
	*����ֵ����
	*���ߣ�����
	*/
	static bool stayInDiffPlace(vector<Player>::iterator it, Map *map, int pos)
	{
		bool doAction = false;
		//��ȡ�ؿ����
		int placeType = map->getPlaceType(pos);
		//��ȡ�ؿ鼶��
		int placeLevel = map->getPlaceLevel(pos);

		char choice = 'n'; 
		
		switch (placeType)
		{
		//�յ�
		case 0:
			    char isBuy;
				cout << endl;
				cout << "�˴��ǿյأ���ѡ���Ƿ���" << endl;
				cin >> isBuy;
				if (isBuy == 'y')
				{
					cout << "�㽫���� " << map->getPlacePrice(pos) << "����õ�" << endl;
					doAction = buyLand(it, map, pos);
					if (!doAction)
					{
						queryAssets(it);
						cout << "��û���㹻���ʽ����������" << endl;
					}
				}
				
				break;
		case 1:
			//���ڱ��˵ؿ�,����
			if (it->getPlayerName() != map->getPlaceOwnerName(pos))
			{
				doAction = payForStay(it, map, pos);
			}
			//�����Լ��ؿ飬��ѡ������
			else
			{
				cout << "�˴����㱾�˵ؿ飬��ѡ���Ƿ�����, y or n:" << endl;
				cin >> choice;
				if(choice == 'y')
				{ 
					doAction = uppdatePlate(it, map, pos);
				}
		        
			}
			break;
		//���ڿ��
		case 2:
			addPoints(it, map->getPlacePrice(pos));
			doAction = true;
			break;
		//���ڼ���
		case 3:
			cout << "�治���ˣ�������ħ��������㽫�ֿղ�������" << endl;
			it->setNoActionTimes(NO_ACTION_PRISION_TIMES);
			break;
		default:
			break;
		}
        cout << endl;
        system("Pause");
		return doAction;
	}

	//��ѯ�û��ʲ�
	static void queryAssets(vector<Player>::iterator it)
	{
		cout << "�㵱ǰ�ʲ����£�" << endl;
		cout << "Ǯ�ƣ�" << it->getPlayerAssets() << endl
			<< "������" << it->getPlayerPoints() << endl
			<< "ӵ�еؿ飺";
		it->printOwnPos();
		cout << endl;
	}

	//��ѯ�Ƿ����ʲ�
	static bool isNoAssets(vector<Player>::iterator it)
	{
		if (it->getOwnPosNum() == 0 && it->getPlayerAssets() == 0)
			return true;
		return false;
	}

	//���۷���
	static bool sellPlace(vector<Player>::iterator it, Map *map)
	{
	
		int pos;
		cout << "������Ҫ���۵ؿ���" << endl;
		cin >> pos;
		if (it->isOwnPos(pos))
		{
			cout << "�㽫���۱��Ϊ" << pos << "�ĵؿ�" << endl;
			cout << "���棺" << (map->getPlaceLevel(pos) + 1) * map->getPlacePrice(pos) << endl;
			cout << "��ѡ��: y or n";
			char choice;
			cin >> choice;
			if (choice == 'y')
			{
				int currAssets = it->getPlayerAssets();
				int inCome = (map->getPlaceLevel(pos) + 1) * map->getPlacePrice(pos);
				it->setPlayerAssets(currAssets + inCome);
				it->deletePos(pos);
				map->setMapHereSign(_X_Y_PLACE[pos][0], _X_Y_PLACE[pos][1], '0');
				
			//	map->setPlaceOwner(Player(" ", 0, 0, 0));
				map->setPlaceLevel(pos, 0);
				map->setPlaceType(pos, 0);
				map->setPlaceSign(pos, '0');
			}
			else
				return true;
		}
		else
		{
			cout << "���ﲢ������ĵ��̣��������������������" << endl;
		}
		return false;
	}
	
	//�����ֿմ���
	static void setNoActionTimes(vector<Player>::iterator it, int times)
	{
		it->setNoActionTimes(times);
	}

	//��ȡ�ֿմ���
	static int getNoActionTimes(vector<Player>::iterator it)
	{
		return it->getNoActionTimes();
	}

};

#endif