#include "Game.h"

Game* Game::_instance = NULL;

Game::Game()
{
	gui = new GUI();
	gameState = GameState::GAMEOVER;
}

Game* Game::getInstance()
{
	if (_instance == NULL)
		_instance = new Game;

	return _instance;
}

void Game::setGameState(GameState::GameState gameState)
{
	this->gameState = gameState;
}

GameState::GameState Game::getGameState()
{
	return gameState;
}

void Game::startGame()
{
	// Change the gameState to PLAYING
	gameState = GameState::PLAYING;

	// Instantiate player objects.
	// The passed argument indicates whether
	// the player is AI (Artificial Intelligence)
	player = new Player(false);
	enemy = new Player(true);

	// Instantiate items stack.
	Item* anItem;
	for (int item = 0; item < 50; item++)
	{
		anItem = new Item(rand() % 3 + 1);
		items.push(*anItem);
	}

	for (int i = 0; i < items.size(); i++)
	{
		cout << "Item #" << i << ": " << items.top().getType() << endl;
		items.pop();
	}

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
		displayChosenCards();
		compareCards();
		replaceCards();
	} while (gameState != GameState::GAMEOVER);

	displayStats();
	gameOver();
}

void Game::displayStats()
{
	cout << gui->drawTopBox(46) << endl;

	for (int i = 1; i < 4; i++)
	{
		cout << char(186);
		cout << "     ";
		if (i == 1)
		{
			cout << player->getCharacter()->getName() 
				 << "           "
				 << enemy->getCharacter()->getName();
		}
		if (i == 2)
		{
			cout << "Health: " << player->getCharacter()->getHealth()
				 << "            "
				 << "Health: " << enemy->getCharacter()->getHealth();
		}
		if (i == 3)
		{
			cout << "Energy: " << player->getCharacter()->getEnergy()
				 << "            "
				 << "Energy: " << enemy->getCharacter()->getEnergy();
		}
		cout << "       ";
		cout << char(186) << endl;
	}

	cout << gui->drawBottomBox(46) << endl;
}

void Game::compareCards()
{
	if (player->getCurrentCard()->getItemCard())
	{
		cout << "\nYou got item: " << endl;
	}

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
		displayChosenCards();
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

void Game::displayChosenCards()
{
	string output;

	output += "Player chose card:     ";
	output += "Enemy chose card:\n";

	for (int line = 0; line <= 12; line++)
	{
		if (line % 2 == 1)
			output += "\n     ";
		if (line % 2 == 0)
			output += "             ";

		if (line == 1 || line == 2)
		{
			output += gui->drawTopBox(6);
			output += "  ";
		}
		if (line == 3 || line == 4 || line == 9 || line == 10)
		{
			output += char(186);
			output += "      ";
			output += char(186);
			output += "  ";
		}
		if (line == 5 || line == 6)
		{
			output += char(186);
			if (line == 5)
			{
				if (player->getCurrentCard()->getItemCard())
					output += " Item";
				else
					output += " A: " + to_string(player->getCurrentCard()->getAttack());
			}
			else
			{
				if (enemy->getCurrentCard()->getItemCard())
					output += " Card";
				else
					output += " A: " + to_string(enemy->getCurrentCard()->getAttack());
			}	
			output += " ";
			output += char(186);
			output += "  ";
		}
		if (line == 7 || line == 8)
		{
			output += char(186);
			if (line == 7)
			{
				if (player->getCurrentCard()->getItemCard())
					output += " Card";
				else
					output += " D: " + to_string(player->getCurrentCard()->getDefense());
			}
			else
			{
				if (enemy->getCurrentCard()->getItemCard())
					output += " Card";
				else
					output += " D: " + to_string(enemy->getCurrentCard()->getDefense());
			}
			
			output += " ";
			output += char(186);
			output += "  ";
		}
		if (line == 11 || line == 12)
		{
			output += gui->drawBottomBox(6);
			output += "  ";
		}
	}

	cout << output;
}