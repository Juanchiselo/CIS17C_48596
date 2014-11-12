/*
 * Jose Sandoval
 * CIS-17C: C++ Programming
 * November 11, 2014
 * Project #1: Card Fight Game
 * Description: A fighting game that uses cards.
 */

#ifndef GAME_H
#define GAME_H

#include "Player.h"

class Game
{
public:
	enum GameState
	{
		GAMEOVER,
		PLAYING
	};
	static Game* getInstance();
	void setGameState(GameState);
	GameState getGameState();
	void startGame();
	void gameOver();
	void startBattle();
	void displayStats();
	void compareCards();
	void replaceCards();
private:
	Player* player;
	Player* enemy;
	GameState gameState;
	static Game* _instance;
	Game();
	Game(const Game& copy);
	Game& operator=(const Game& copy);
};

#endif // GAME_H