#include "command.h"
#include <ctime>
#include <cstdlib>

void Command::roll(Player player, Map map, PlayerAction pAction)
{
	srand((unsigned)time(NULL));
	int step = (1 + rand() % 6);
	pAction.resetPlayerPos(player, map, step);
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
quit    结束游戏。\n\
************************输入<help>命令可再次显示该帮助信息********************\n";
	cout << help_string;
}

 bool Command::sell(Player player, Place place, int position)
 {
	 if (player.getPlayerName() != place.getPlaceOwnerName())
	 {
		 cout << "此地块不是你的土地，请不要开玩笑好吗。。" << endl;
		 return false;
	 }
	
	 string choice;
	 //卖地块的收益
	 int inCome = place.getPlacePrice() * place.getPlaceLevel() * 2;
	 cout << "你将出售该地块，并将获得如下收益：" << inCome << endl;
	 cout << "y or n" << endl;
	 cin >> choice;
	 if (choice == "y")
	 {
		 player.setPlayerAssets(player.getPlayerAssets() + inCome);
		// place.setPlaceOwner(NULL);
	 }
	 return true;
 }

 //待续
 void Command::query(Player player)
 {
	 cout << "玩家资产信息如下";
 }

 //void Command::exit();