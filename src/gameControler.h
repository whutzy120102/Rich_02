#ifndef _GAME_CONTROLER_H_
#define _GAME_CONTROLER_H_

#include "game.h"
class GameControler
{
private:
	Game *game;
public:
	GameControler()
	{
		game = new Game();
	}
	~GameControler()
	{
		delete game;
	}
	void startGame()
	{
		game->goGame();
	}
};
#endif
