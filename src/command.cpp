#include "command.h"
#include <ctime>
#include <cstdlib>

int Command::roll()
{
	int step = randomEx(MIN_STEP, MAX_STEP);
	return step;
}

 void Command::help()
{
	string help_string = "\n\
***********************************地图解释***********************************\n\
地图外围数字为标尺，用来标志土地位置：A-10，B-20，D-40，E-50,F-60\n\
0:空地; $:矿地; S:起点0;  P:监狱49; \n\
***********************************命令解释***********************************\n\
*********************输入命令后回车即可执行命令，输入错误请重新输入***********\n\
roll    掷骰子命令。\n\
sell n  出售地图上n位置上的房产\n\
query   查询当前玩家资产信息。\n\
help    帮助。\n\
exit    玩家退出游戏\n\
quit    结束游戏。\n";
	cout << help_string;
}
 

 //出售土地命令
 void Command::sell(vector<Player>::iterator it, Map *map)
 {
	 PlayerAction::sellPlace(it, map);
 }
 
 //查询玩家信息命令
 void Command::query(vector<Player>::iterator it)
 {
	 PlayerAction::queryAssets(it);
 }

 //void Command::exit();

 //获取小写命令
 char* Command::getLowerCommand()
 {
	 char inputCmd[MAX_COMMAND_SIZE];
	 getInput(inputCmd, MAX_COMMAND_SIZE);
    // toLower(command, inputCmd, MAX_COMMAND_SIZE);
	 return command;
 }

 
 /*
 //执行命令
 int Command::goCommand(vector<Player>::iterator it, Map *map)
 {
	 getLowerCommand();

	 if (equalCommand(command, "help"))
	 {
		 help();
	 }
	 else if (equalCommand(command, "roll"))
	 {
		 int step = roll();
		 action->resetPlayerPos(it, map, step);
		
		 return step;
	 }
	 else if (equalCommand(command, ""))
	 {
	 }
 }*/

 //判断命令相等
 bool Command::equalCommand(char *m, char *m_m)
 {
	 if (strcmp(m, m_m) == 0) return true;
	 
	 return false;
 }

 //强退出
 void Command::quit()
 {
	 return;
 }

 //用户选择退出
 void Command::exit(vector<Player>::iterator it, Map *map)
 {
	 
	 it->setPlayerAssets(0);
	 it->setPlayerPoints(0);
	 it->setPlayerId(0);
	 it->setPlayerName("");
	 it->setPlayerPos(0);
	 it->setPlayerSign(' ');
	
	 map->cleanMapOfPlayer(it);
 }