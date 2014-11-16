/*
 * Jose Sandoval
 * CIS-17C: C++ Programming
 * November 11, 2014
 * Project #1: Card Fight Game
 * Description: A fighting game that uses cards.
 */

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <fstream>
#include <stack>

#include "Player.h"
#include "GUI.h"
#include "GameState.h"

class GameManager
{
private:
	static GameManager* _instance;
	GameState::GameState gameState;
	vector<Player*> players;
	Player* player;
	Player* enemy;
	GUI gui;
	map<string, string> characters;
	stack<Item> items;
	GameManager();
	GameManager(const GameManager&);
	GameManager& operator=(const GameManager&);
	void cleanUp();
public:
	static GameManager* getInstance();
	void setGameState(GameState::GameState);
	GameState::GameState getGameState();
	Player* getPlayer();
	Player* getEnemy();
	map<string, string> getCharacters();
	GUI* getGUI();
	void startGame();
	void gameOver();
	void startBattle();
	void compareCards();
	void replaceCards();
	void battleMenu();
};

#endif // GAMEMANAGER_H