#include <iostream>

using namespace std;
#include "map.h"
#include "game.h"

int main()
{
	Game *game = new Game();
	
	game->initGame();
	game->deletePlayer(Player("wang", 2));
	system("pause");
	return 0;
}