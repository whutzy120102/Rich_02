#include "game.h"
//���ó�ʼ�ʽ�
void Game::setDefalutMoney()
{
    while (defaultMoney < 1000 || defaultMoney > 50000) {
        cout << "��������ҵĳ�ʼ��";
        cin >> defaultMoney;
    }
	vector<Player>::iterator it;
	for (it = players.begin(); it != players.end(); ++it)
	{
		it->setPlayerAssets(defaultMoney);
	}


	/*
	/////////////////////////
	vector<Player>::iterator ait;
	for (ait = players.begin(); ait != players.end(); ++ait)
	{
		cout << endl;
		cout << ait->getPlayerAssets() << " " << ait->getPlayerId() << endl;

	}*/
}

/*
*������initPlayer()
*����˵����
*���ܣ���ʼ����ң�������ҵ��ʽ�λ��
*����ֵ����
*���ߣ�
*/
void Game::initPlayer()
{
	char input[MAX_PLAYER_NUM];
	choicePlayer(input);

	for (int i = 0; i < playerNum; ++i)
	{
		int num = charToInt(input[i]);
		addPlayer(Player(STAY_PLAYERS[num - 1], i + 1, PLAYER_SIGN[num - 1], i+1));
	}
	setDefalutMoney();
}



/*
*������initGame()
*����˵����
*���ܣ���ʼ����ͼ�����
*����ֵ����
*���ߣ�
*/
void Game::initGame()
{
	map->initMap();
	map->printMap();
	cout << "\n\n��Ϸ��ʼ, ��ѡ����ҽ��г�ʼ����Һ��ʽ�" << endl;
	cout << "��ѡ��2~4λ���ظ���ң�����������ұ�ź�س����ɣ��磺123��\n(1.Ǯ����; 2.������; 3.��С��; 4.�𱴱�):";
	initPlayer();
}

/*
*������destroyPlayer()
*����˵����
*���ܣ����ٵ�ͼ
*����ֵ����
*���ߣ�
*/
void Game::destroyGame() 
{
	players.clear();
}

/*
*������quitGame()
*����˵����
*���ܣ���ֹ��Ϸ
*����ֵ����
*���ߣ�
*/
void Game::quitGame() {}

/*
*������addPlayer()
*����˵����
*���ܣ�������
*����ֵ����
*���ߣ�
*/
void Game::addPlayer(Player player)
{
	players.push_back(player);
}

/*
*������deletePlayer()
*����˵����
*���ܣ�ɾ�����
*����ֵ����
*���ߣ�
*/
vector<Player>::iterator Game::deletePlayer(vector<Player>::iterator it)
{

	it = players.erase(it);

	return it;
}

//ִ������


//��Ϸ����,��Ҫ�������һ�θ��ֲ���
void Game::goGameBody()
{
	//��ȡ��ǰ���


	for (;;)
	{
		for (vector<Player>::iterator it = players.begin(); it != players.end(); ++it) {
			//ˢ�µ�ͼ
			flushMap();
			//�����˳�
			bool doAction = false;
			bool needInc = false;

			//�ֿտ�ʼ
			if (it->getNoActionTimes() > 0)
			{
				//��ȡ�ֿմ���
				int noActionTimes = it->getNoActionTimes();
				cout << "�ֿ�һ�Σ��㻹��Ҫ���ֿ�" << (noActionTimes - 1) << "�Σ�����ִ������" << endl;
				it->setNoActionTimes(noActionTimes - 1);
				needInc = true;
				break;
			}

			else
			{

				//���ִ��roll
				int roll_once = 0;
				//����
				char tempCmd[MAX_COMMAND_SIZE];

				//��ʾ�û�����
				cout << it->getPlayerName() << ">";

				for (;;)
				{
					//ִ������
					getCommandInput(tempCmd);
					//���ǿ���˳�
					if (command->equalCommand(tempCmd, "quit"))
					{
						players.clear();
						return;
					}
					if ((command->equalCommand(tempCmd, "finish")) && (roll_once == 1))
					{
						break;
					}
					if (command->equalCommand(tempCmd, "roll"))
					{
						roll_once = 1;
						int step = command->roll();
						cout << "��ǰ�н�" << step << "����" << endl;

						PlayerAction::levPlace(it, map);
						PlayerAction::resetPlayerPos(it, map, step);

						//ˢ�µ�ͼ
						flushMap();
						//��ʾ�û�����
						cout << lredcolor << it->getPlayerName() << ">";
						//ִ�в�ͬλ�ò���
						doAction = PlayerAction::stayInDiffPlace(it, map, it->getPlayerPos());
						needInc = true;
						break;

					}
					else if (command->equalCommand(tempCmd, "help"))
					{
						command->help();
					}
					else if (command->equalCommand(tempCmd, "query"))
					{
						command->query(it);
					}


					//exit������
					else if (command->equalCommand(tempCmd, "exit"))
					{
						command->exit(it, map);

						it = deletePlayer(it);
						if (players.size() == 0)
						{

							cout << "��Ϸ����" << endl;
							return;
						}
						if (it == players.end())
						{
							it = players.begin();
						}
						
						if (it == players.end())
						{
							it = players.begin();
						}
						needInc = true;
						break;
					}
					else if (command->equalCommand(tempCmd, "sell"))
					{
						if (it->getOwnPosNum() != 0)
						{
							command->sell(it, map);
						}
						else
						{
							cout << "������û�еز�" << endl;
						}


					}
					/*
					else
					{
						cout << "û����ѡ�������,������help�鿴����" << endl;
					}
					*/

				}
			}

			if (!doAction && PlayerAction::isNoAssets(it))
			{
				PlayerAction::queryAssets(it);
				cout << "�㵱ǰ�ʲ��Ѿ��������汾��Ϸ�� ��Ϸ���������˳�" << endl;
				command->exit(it, map);
				it = deletePlayer(it);
				if (it == players.end())
				{
					it = players.begin();
				}

			}


			if (players.size() == 1)
			{
				cout << "��ϲ" << it->getPlayerName() << "ʤ��" << endl;
				cout << "��Ϸ����" << endl;
				destroyGame();
				return;
			}
			//ˢ����Ļ
			system("cls");
		}

	}
}

//ִ����Ϸ���ٴη�װ��Ϸ
void Game::goGame()
{
	char isPlay = 'y';
	while (isPlay == 'y')
	{
		system("cls");
		initGame();
		goGameBody();
		cout << "�Ƿ����¿�ʼ��Ϸ��y or n";
		cin >> isPlay;
	}
}

//ѡ�����
void Game::choicePlayer(char *input)
{
	do
	{
		getPlayerInput(input);
		if (isInputPlayer(input) || (!isExistPlayer(input)))
		{
			cout << "��������ע�������ʽ����Ҫ�ظ�ѡ�����" << endl;
			continue;
		}
		/*if (playerNum < (MIN_PLAYER_NUM-1) || playerNum > MAX_PLAYER_NUM-1 )
		{
			cout << "���������������2-4��" << endl;
			cout << "�����������û�" << endl;
			getPlayerInput(input);
			continue;
		}*/
		playerNum = strlen(input);
	} while (playerNum < MIN_PLAYER_NUM || playerNum > MAX_PLAYER_NUM);


}

//�������Ƿ����
bool Game::isExistPlayer(char *input)
{
	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i] > '4' || input[i] < '1')
		{
			return false;
		}
	}
	return true;
}

//�����������Ƿ��ظ�
bool Game::isInputPlayer(char *input)
{
	for (int i = 0; i < strlen(input); i++)
	{
		for (int j = i + 1; j < strlen(input); j++)
		{
			if (input[i] == input[j])
			{
				return true;
			}
		}
	}
	return false;
}


//�������
void Game::getPlayerInput(char *input)
{
	getInput(input, MAX_PLAYER_NUM);
}

//��������
void Game::getCommandInput(char *input)
{
	getInput(input, MAX_COMMAND_SIZE);
}

void Game::flushMap()
{
	system("cls");
	map->printMap();
	cout << "������help��ð�����Ϣ��" << endl;
}