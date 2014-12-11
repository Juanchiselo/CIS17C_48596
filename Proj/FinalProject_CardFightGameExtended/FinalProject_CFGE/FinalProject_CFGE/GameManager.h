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
#include "BinarySearchTree.h"

class GameManager
{
private:
	static GameManager* _instance;
	GameState::GameState gameState;
	vector<Player*> players;
	vector<Player*>* currentPlayers;
	GUI gui;
	vector<Character*> characters;
	stack<Item> items;
	GameManager();
	GameManager(const GameManager&);
	GameManager& operator=(const GameManager&);
	void cleanUp();
	BinarySearchTree<Player*>* tournament;
public:
	static GameManager* getInstance();
	void loadResources();
	void setGameState(GameState::GameState);
	GameState::GameState getGameState();
	GUI* getGUI();
	vector<Player*> getPlayers();
	void newGame();
	void loadGame();
	void startGame();
	void gameOver();
	void chooseCharacter(Player*);
	void startBattle();
	void compareCards();
	void replaceCards();
	void battleMenu();
};

#endif // GAMEMANAGER_H