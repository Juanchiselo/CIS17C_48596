#include "Game.h"

Game* Game::_instance = NULL;

Game::Game()
{
	gameState = GAMEOVER;
}

Game* Game::getInstance()
{
	if (_instance == NULL)
		_instance = new Game;

	return _instance;
}

void Game::setGameState(GameState gameState)
{
	this->gameState = gameState;
}

Game::GameState Game::getGameState()
{
	return gameState;
}

void Game::startGame()
{
	// Change the gameState to PLAYING
	gameState = PLAYING;

	// Instantiate player objects.
	// The passed argument indicates whether
	// the player is AI (Artificial Intelligence)
	player = new Player(false);
	enemy = new Player(true);

	// Start Battle
	startBattle();
}

void Game::gameOver()
{
	cout << "\n\n\n";
	cout << "GAME OVER!" << endl;

	if (player->getCharacter()->getHealth() <= 0)
		cout << enemy->getCharacter()->getName() << " WINS!!!" << endl;
	else
		cout << player->getCharacter()->getName() << " WINS!!!" << endl;
}

void Game::startBattle()
{
	cout << "The battle starts!" << endl;
	cout << player->getCharacter()->getName() << " vs " << enemy->getCharacter()->getName() << endl;
	cout << "\n\n";

	do
	{
		displayStats();
		player->attack();
		enemy->attack();
		compareCards();
		replaceCards();
	} while (gameState != GAMEOVER);

	displayStats();
	gameOver();
}

void Game::displayStats()
{
	cout << player->getCharacter()->getName() << "                    "
		<< enemy->getCharacter()->getName() << endl;
	cout << "Health: " << player->getCharacter()->getHealth()
		<< "                    "
		<< "Health: " << enemy->getCharacter()->getHealth() << endl;
	cout << "Energy: " << player->getCharacter()->getEnergy()
		<< "                    "
		<< "Energy: " << enemy->getCharacter()->getEnergy();
}

void Game::compareCards()
{
	if (player->getCurrentCard()->getAttack() > enemy->getCurrentCard()->getAttack())
	{
		cout << "\nPlayer attacks!" << endl;
		enemy->getCharacter()->defend(player->getCurrentCard()->getAttack(),
			enemy->getCurrentCard()->getDefense());
	}
	else if (player->getCurrentCard()->getAttack() == enemy->getCurrentCard()->getAttack())
	{
		cout << "\nDraw! Choose another card!" << endl;
		replaceCards();
		player->attack();
		enemy->attack();
		compareCards();
	}
	else
	{
		cout << "\nEnemy attacks!" << endl;
		player->getCharacter()->defend(enemy->getCurrentCard()->getAttack(),
			player->getCurrentCard()->getDefense());
	}

	cout << "\n\n";
}

void Game::replaceCards()
{
	player->getHand()->replaceCard();
	enemy->getHand()->replaceCard();
}
