#include "game.h"
//设置初始资金
void Game::setDefalutMoney()
{
    while (defaultMoney < 1000 || defaultMoney > 50000) {
        cout << "请输入玩家的初始金额：";
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
*函数：initPlayer()
*参数说明：
*功能：初始化玩家，包括玩家的资金，位置
*返回值：无
*作者：
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
*函数：initGame()
*参数说明：
*功能：初始化地图和玩家
*返回值：无
*作者：
*/
void Game::initGame()
{
	map->initMap();
	map->printMap();
	cout << "\n\n游戏开始, 请选择玩家进行初始化玩家和资金" << endl;
	cout << "请选择2~4位不重复玩家，连续输入玩家编号后回车即可，如：123。\n(1.钱夫人; 2.阿土伯; 3.孙小美; 4.金贝贝):";
	initPlayer();
}

/*
*函数：destroyPlayer()
*参数说明：
*功能：销毁地图
*返回值：无
*作者：
*/
void Game::destroyGame() 
{
	players.clear();
}

/*
*函数：quitGame()
*参数说明：
*功能：终止游戏
*返回值：无
*作者：
*/
void Game::quitGame() {}

/*
*函数：addPlayer()
*参数说明：
*功能：添加玩家
*返回值：无
*作者：
*/
void Game::addPlayer(Player player)
{
	players.push_back(player);
}

/*
*函数：deletePlayer()
*参数说明：
*功能：删除玩家
*返回值：无
*作者：
*/
vector<Player>::iterator Game::deletePlayer(vector<Player>::iterator it)
{

	it = players.erase(it);

	return it;
}

//执行命令


//游戏主体,主要包括玩家一次各种操作
void Game::goGameBody()
{
	//获取当前玩家


	for (;;)
	{
		for (vector<Player>::iterator it = players.begin(); it != players.end(); ++it) {
			//刷新地图
			flushMap();
			//用于退出
			bool doAction = false;
			bool needInc = false;

			//轮空开始
			if (it->getNoActionTimes() > 0)
			{
				//获取轮空次数
				int noActionTimes = it->getNoActionTimes();
				cout << "轮空一次，你还需要再轮空" << (noActionTimes - 1) << "次，才能执行命令" << endl;
				it->setNoActionTimes(noActionTimes - 1);
				needInc = true;
				break;
			}

			else
			{

				//标记执行roll
				int roll_once = 0;
				//命令
				char tempCmd[MAX_COMMAND_SIZE];

				//提示用户输入
				cout << it->getPlayerName() << ">";

				for (;;)
				{
					//执行命令
					getCommandInput(tempCmd);
					//玩家强行退出
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
						cout << "向前行进" << step << "步数" << endl;

						PlayerAction::levPlace(it, map);
						PlayerAction::resetPlayerPos(it, map, step);

						//刷新地图
						flushMap();
						//提示用户输入
						cout << lredcolor << it->getPlayerName() << ">";
						//执行不同位置操作
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


					//exit有问题
					else if (command->equalCommand(tempCmd, "exit"))
					{
						command->exit(it, map);

						it = deletePlayer(it);
						if (players.size() == 0)
						{

							cout << "游戏结束" << endl;
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
							cout << "你名下没有地产" << endl;
						}


					}
					/*
					else
					{
						cout << "没有你选择的命令,请输入help查看帮助" << endl;
					}
					*/

				}
			}

			if (!doAction && PlayerAction::isNoAssets(it))
			{
				PlayerAction::queryAssets(it);
				cout << "你当前资产已经不足以玩本游戏， 游戏无奈让你退出" << endl;
				command->exit(it, map);
				it = deletePlayer(it);
				if (it == players.end())
				{
					it = players.begin();
				}

			}


			if (players.size() == 1)
			{
				cout << "恭喜" << it->getPlayerName() << "胜利" << endl;
				cout << "游戏结束" << endl;
				destroyGame();
				return;
			}
			//刷新屏幕
			system("cls");
		}

	}
}

//执行游戏，再次封装游戏
void Game::goGame()
{
	char isPlay = 'y';
	while (isPlay == 'y')
	{
		system("cls");
		initGame();
		goGameBody();
		cout << "是否重新开始游戏：y or n";
		cin >> isPlay;
	}
}

//选择玩家
void Game::choicePlayer(char *input)
{
	do
	{
		getPlayerInput(input);
		if (isInputPlayer(input) || (!isExistPlayer(input)))
		{
			cout << "输入有误，注意输入格式并不要重复选择玩家" << endl;
			continue;
		}
		/*if (playerNum < (MIN_PLAYER_NUM-1) || playerNum > MAX_PLAYER_NUM-1 )
		{
			cout << "输入玩家数量有误（2-4）" << endl;
			cout << "请重新输入用户" << endl;
			getPlayerInput(input);
			continue;
		}*/
		playerNum = strlen(input);
	} while (playerNum < MIN_PLAYER_NUM || playerNum > MAX_PLAYER_NUM);


}

//检查玩家是否存在
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

//检查输入玩家是否重复
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


//输入玩家
void Game::getPlayerInput(char *input)
{
	getInput(input, MAX_PLAYER_NUM);
}

//输入命令
void Game::getCommandInput(char *input)
{
	getInput(input, MAX_COMMAND_SIZE);
}

void Game::flushMap()
{
	system("cls");
	map->printMap();
	cout << "可输入help获得帮助信息：" << endl;
}