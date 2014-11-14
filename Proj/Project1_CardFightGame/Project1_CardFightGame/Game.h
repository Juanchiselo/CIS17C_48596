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
#include "GUI.h"
#include "GameState.h"

class Game
{
public:
	static Game* getInstance();
	void setGameState(GameState::GameState);
	GameState::GameState getGameState();
	GUI* gui;
	void startGame();
	void gameOver();
	void startBattle();
	void displayStats();
	void compareCards();
	void replaceCards();
	void displayChosenCards();
private:
	Player* player;
	Player* enemy;
	GameState::GameState gameState;
	stack<Item> items;
	static Game* _instance;
	Game();
	Game(const Game&);
	Game& operator=(const Game&);
};

#endif // GAME_H