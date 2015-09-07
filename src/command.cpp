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
***********************************��ͼ����***********************************\n\
��ͼ��Χ����Ϊ��ߣ�������־����λ�ã�A-10��B-20��D-40��E-50,F-60\n\
0:�յ�; $:���; S:���0;  P:����49; \n\
***********************************�������***********************************\n\
*********************���������س�����ִ����������������������***********\n\
roll    ���������\n\
sell n  ���۵�ͼ��nλ���ϵķ���\n\
query   ��ѯ��ǰ����ʲ���Ϣ��\n\
help    ������\n\
exit    ����˳���Ϸ\n\
quit    ������Ϸ��\n";
	cout << help_string;
}
 

 //������������
 void Command::sell(vector<Player>::iterator it, Map *map)
 {
		 PlayerAction::sellPlace(it, map); 

	
 }
 
 //��ѯ�����Ϣ����
 void Command::query(vector<Player>::iterator it)
 {
	 PlayerAction::queryAssets(it);
 }

 //void Command::exit();

 //��ȡСд����
 char* Command::getLowerCommand()
 {
	 char inputCmd[MAX_COMMAND_SIZE];
	 getInput(inputCmd, MAX_COMMAND_SIZE);
    // toLower(command, inputCmd, MAX_COMMAND_SIZE);
	 return command;
 }

 
 /*
 //ִ������
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

 //�ж��������
 bool Command::equalCommand(char *m, char *m_m)
 {
	 if (strcmp(m, m_m) == 0) return true;
	 
	 return false;
 }

 //ǿ�˳�
 void Command::quit()
 {
	 return;
 }

 //�û�ѡ���˳�
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