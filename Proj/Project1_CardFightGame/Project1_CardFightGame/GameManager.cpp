/*
 * Jose Sandoval
 * CIS-17C: C++ Programming
 * November 11, 2014
 * Project #1: Card Fight Game
 * Description: A fighting game that uses cards.
 */

#include "GameManager.h"

GameManager* GameManager::_instance = NULL;

// Constructor for GameManager singleton class.
GameManager::GameManager()
{
	// Set gamestate to GAMEOVER
	gameState = GameState::GAMEOVER;

	// Create variables for reading in
	// the Characters.txt file
	string line;
	ifstream data("Characters.txt");
	vector<string> information;
	
	// Read in Characters.txt data.
	if (data.is_open())
	{
		// Save the data to the information vector.
		while (getline(data, line, ','))
			information.push_back(line);

		// Close the Characters.txt file.
		data.close();
	}
	else
		cout << "ERROR: File could not be opened!" << endl;

	// Fill the characters map with the data from vector.
	for (int i = 0; i < information.size(); i += 2)
		characters[information.at(i)] = information.at(i + 1);
}

// cleanUp function would be the destructor
// for the GameManager class.
void GameManager::cleanUp()
{
	delete player;
	delete enemy;
}

// Returns the one and only instance of
// GameManager.
GameManager* GameManager::getInstance()
{
	// If instance is NULL instantiate
	// a GameManager object.
	if (_instance == NULL)
		_instance = new GameManager;

	return _instance;
}

// Sets the gameState of the game.
void GameManager::setGameState(GameState::GameState gameState)
{
	this->gameState = gameState;
}

// Returns the gameState of the game.
GameState::GameState GameManager::getGameState()
{
	return gameState;
}

// Returns a pointer to the player.
Player* GameManager::getPlayer()
{
	return player;
}

// Returns a pointer to the enemy.
Player* GameManager::getEnemy()
{
	return enemy;
}

// Returns a pointer to the characters map.
map<string, string> GameManager::getCharacters()
{
	return characters;
}

// Returns a pointer to the gui.
GUI* GameManager::getGUI()
{
	return &gui;
}

// Starts the game.
void GameManager::startGame()
{
	// Change the gameState to PLAYING
	gameState = GameState::PLAYING;

	// Display game banner
	gui.displayBanner();

	// Instantiate player objects.
	// The passed argument indicates whether
	// the player is AI (Artificial Intelligence)
	player = new Player(false);
	enemy = new Player(true);

	// Instantiate items stack.
	Item* anItem;
	int itemsStackSize = 25;
	for (int item = 0; item < itemsStackSize; item++)
	{
		anItem = new Item(rand() % 4 + 1);
		items.push(*anItem);
	}

	// Start Battle
	startBattle();
}

// Ends the game and displays who won the battle.
void GameManager::gameOver()
{
	cout << "\n" << setw(25) << "GAME OVER!" << endl;

	// Check what player won based on who has a health of 0. 
	if (player->getCharacter()->getHealth() == 0)
		cout << setw(25) <<enemy->getCharacter()->getName() << " WINS!!!" << endl;
	else
		cout << setw(25) << player->getCharacter()->getName() << " WINS!!!" << endl;

	// Calls the destructor to clean up memory.
	cleanUp();
}

// Starts the battle.
void GameManager::startBattle()
{
	// Display the chosen characters.
	cout << "\n\n" << setw(30) << "THE BATTLE STARTS!\n"
	     << setw(20) << player->getCharacter()->getName() 
		 << " VS " << enemy->getCharacter()->getName()
		 << "\n\n\n";

	// Game loop.
	do
	{
		// Display stats.
		gui.drawStats();

		// Display battle menu.
		battleMenu();
		
		// TEMPORARY FIX FOR STOPPING AFTER SPECIAL
		// ATTACK KILLS OPPONENT.
		if (gameState != GameState::GAMEOVER)
		{
			// Displays the cards chosen by
			// the players.
			gui.drawChosenCards();

			// Compares the cards to see who will
			// attack.
			compareCards();
		}
	} while (gameState != GameState::GAMEOVER);

	// Displays the stats one last time
	// before calling gameOver.
	gui.drawStats();

	// Calls gameOver to finish the game.
	gameOver();
}

// Compares the chosen cards by the players
// to see who will attack.
void GameManager::compareCards()
{
	// If the player or the enemy chose an item
	// card add the item to the bag of the one
	// who chose it.
	if (player->getChosenCard()->isItemCard()
		|| enemy->getChosenCard()->isItemCard())
	{
		// If the player is the one who chose the item
		// card show him what he got and add it to
		// his bag.
		if (!player->isPlayerAI() 
			&& player->getChosenCard()->isItemCard())
		{
			cout << "\nYou got item: " 
				 << items.top().getType() << endl;

			player->addItem(items.top());
			items.pop();
		}

		// If the enemy is the one who chose the
		// item card just add it to his bag.
		if (enemy->getChosenCard()->isItemCard())
		{
			enemy->addItem(items.top());
			items.pop();
		}
	}

	// If the player chose a card with a higher attack
	// then he is the one who attacks.
	if (player->getChosenCard()->getAttack()
	     > enemy->getChosenCard()->getAttack())
	{
		cout << "\n" << setw(25) 
			 << "Player ATTACKS!" << endl;

		// Have the enemy take the attack of the player's
		// chosen card and the defense of his own card.
		enemy->getCharacter()
			->defend(player->getChosenCard()->getAttack(),
			enemy->getChosenCard()->getDefense());
	}

	// If the attack value on the player's chosen card
	// is the same as the attack value on the enemy's
	// chosen card and they are not item cards, then
	// it is a DRAW and both players have to choose
	// another card.
	else if (player->getChosenCard()->getAttack() 
		     == enemy->getChosenCard()->getAttack()
		     && !player->getChosenCard()->isItemCard())
	{
		cout << "\n" << setw(25) 
			 << "DRAW! Choose another card!" << endl;

		replaceCards();
		player->attack();
		enemy->attack();
		gui.drawChosenCards();
		compareCards();
	}
	// If none of the cases above is true it means
	// that enemy has a higher attack value on his
	// chosen card so he attacks.
	else
	{
		// If the enemy's chosen card is not an item
		// have the player take the damage.
		if (!enemy->getChosenCard()->isItemCard())
		{
			cout << "\n" << setw(25)
				<< "Enemy ATTACKS!" << endl;

			// Have the player take the attack value of the enemy's
			// chosen card and the defense of his own card.
			player->getCharacter()
				->defend(enemy->getChosenCard()->getAttack(),
				player->getChosenCard()->getDefense());
		}
	}

	// Replace the chosen cards.
	replaceCards();

	cout << "\n";
}

// Replaces the cards chosen by the players.
void GameManager::replaceCards()
{
	player->getHand()->replaceCard();
	enemy->getHand()->replaceCard();
}

void GameManager::battleMenu()
{
	// Create choice variable.
	int choice;

	// Battle menu for a player who is not AI.
	if (!player->isPlayerAI())
	{
		do
		{
			cout << "Choose an option:\n"
				 << "1) Attack\n"
				 << "2) Items\n\n"
				 << "Choice: ";
			cin >> choice;

			switch (choice)
			{
			case 1:
				// Player attacks.
				player->attack();
				break;
			case 2:
				// If the bag of the layer is not
				// empty look at his items.
				if (!player->getItems()->empty())
				{
					// Display the items inside
					// the player's bag.
					player->viewItems();

					cout << "\nChoose an option:\n"
						<< "1) Apply item\n"
						<< "2) Go back\n\n"
						<< "Choice: ";
					cin >> choice;

					// Apply item.
					if (choice == 1)
					{
						// Create pointer that points to the 
						// player's bag.
						map<string, int>* items = player->getItems();

						do
						{
							cout << "\nEnter item number: ";
							cin >> choice;
						} while (choice < 0 || choice > items->size());

						// Create an iterator and move it where the chosen
						// item is located in the map.
						auto iterator = items->begin();
						advance(iterator, (choice - 1));

						// If the chosen item is a Cards Swap,
						// a Health Package, or an Energy
						// Package use it.
						if (iterator->first == "Cards Swap" ||
							iterator->first == "Health Package" ||
							iterator->first == "Energy Package")
							player->applyItem(choice);
						else
						{
							// If the chosen item is a Special Attack,
							// make sure the player has the minimum
							// energy to perform it.
							if (player->getCharacter()->getEnergy() > 10
								&& iterator->first == "Special Attack")
								player->applyItem(choice);
							else
							{
								cout << "You do not have the minimum"
									<< " energy needed for a special attack.\n";
							}
						}

						// Set choice equal to 0 to break out of loop.
						choice = 0;
					}
				}
				// Otherwise tell him he has not items.
				else
					cout << "\nYou have no items in your bag." << endl;
				break;
			default:
				cout << "ERROR: Not a valid choice." << endl;
			}

			cout << "\n\n";

		} while (choice != 1);
	}

	// AI decisions code.
	if (enemy->isPlayerAI())
	{
		// Create a variable for the chosen item.
		int chosenItem = 0;

		int count = 0;

		// If the bag of the enemy is not empty
		// have him look at its contents.
		if (!enemy->getItems()->empty())
		{
			// Create pointer that points to the 
			// enemy's bag.
			map<string, int>* items = enemy->getItems();

			// Iterate through the enemy's bag.
			for (auto iterator = items->begin();
				iterator != items->end(); iterator++)
			{
				count++;

				// If item is a health Package.
				if (iterator->first == "Health Package")
				{
					// Create minimum health threshold variable.
					int minHealthThreshold = 15;

					// Check if the health of the player is
					// below the minimum health threshold,
					// if it is use a health package.
					if (enemy->getCharacter()->getHealth()
						< minHealthThreshold)
						chosenItem = count;
				}

				// If item is an Energy Package.
				if (iterator->first == "Energy Package")
				{
					// Use the energy package only when
					// the energy is less than the maximum
					// energy.
					if (enemy->getCharacter()->getEnergy()
						< enemy->getCharacter()->getMaxEnergy())
						chosenItem = count;
				}

				// If item is Cards Swap.
				if (iterator->first == "Cards Swap")
					chosenItem = count;

				// If item is Special Attack.
				if (iterator->first == "Special Attack")
				{
					// Miimum energy needed for a special attack.
					int minEnergyNeeded = 10;

					// If the energy of the enemy is greater than or
					// equal to the minimum energy needed then use it.
					if (enemy->getCharacter()->getEnergy() >= minEnergyNeeded)
						chosenItem = count;
				}
			}

			// Apply the chosen item.
			if (chosenItem != 0)
				enemy->applyItem(chosenItem);
			// If an item was not chosen then attack.
			else
				enemy->attack();
		}
		// If the enemy's bag is empty attack.
		else
			enemy->attack();
	}
}