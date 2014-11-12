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
private:
	Player* player;
	Player* enemy;
public:
	Game();
	~Game();
	void startGame();
	void startBattle();
	void displayStats();
	void compareCards();
};

Game::Game()
{
}

Game::~Game()
{

}

void Game::startGame()
{
	player = new Player(false);
	enemy = new Player(true);
}

void Game::startBattle()
{
	bool isGameOver = false;

	cout << "The battle starts!" << endl;
	cout << player->getCharacter()->getName() << " vs " << enemy->getCharacter()->getName() << endl;
	cout << "\n\n";

	do
	{
		displayStats();
		player->attack(false);
		enemy->attack(true);
		compareCards();
	} while (!isGameOver);
}

void Game::displayStats()
{
	cout << player->getCharacter()->getName() << "                    "
		 << enemy->getCharacter()->getName() << endl;
	cout << "Health: " << player->getCharacter()->getHealth()
		 << "                    "
		 << "Health: " << enemy->getCharacter()->getHealth() << endl;
}

void Game::compareCards()
{
	if (player->getCurrentCard()->getAttack() > enemy->getCurrentCard()->getAttack())
	{
		cout << "\nPlayer attacks!" << endl;
		enemy->getCharacter()->defend(player->getCurrentCard()->getAttack(),
			enemy->getCurrentCard()->getDefense());
	}
	else
	{
		cout << "\nEnemy attacks!" << endl;
		player->getCharacter()->defend(enemy->getCurrentCard()->getAttack(),
			player->getCurrentCard()->getDefense());
	}

	cout << "\n\n";
}

#endif // GAME_H