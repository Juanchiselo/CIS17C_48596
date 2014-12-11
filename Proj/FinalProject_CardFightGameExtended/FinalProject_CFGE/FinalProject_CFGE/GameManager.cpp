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
}

// cleanUp function would be the destructor
// for the GameManager class.
void GameManager::cleanUp()
{
	players.clear();
	currentPlayers->clear();
	characters.clear();
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

void GameManager::loadResources()
{
	const int NUMBEROFCHARACTERS = 8;

	for (int i = 0; i < NUMBEROFCHARACTERS; i++)
	{
		characters.push_back(new Character());
	}

	// Create variables for reading in
	// the Characters.txt file
	string line;
	ifstream charactersFile("Characters.txt");
	vector<string> characterNames;

	// Read in Characters.txt data.
	if (charactersFile.is_open())
	{
		// Save the data to the information vector.
		while (getline(charactersFile, line, ','))
			characterNames.push_back(line);

		// Close the Characters.txt file.
		charactersFile.close();
	}
	else
		cout << "ERROR: File could not be opened!" << endl;

	vector<string> attacks;
	ifstream attacksFile("Attacks.txt");

	// Read in Characters.txt data.
	if (attacksFile.is_open())
	{
		// Save the data to the information vector.
		while (getline(attacksFile, line, ','))
			attacks.push_back(line);

		// Close the Characters.txt file.
		attacksFile.close();
	}
	else
		cout << "ERROR: File could not be opened!" << endl;

	// Fill the characters' attacks maps with the data from vector.
	string attack;
	int damage;
	int energy;
	vector<int> stats;
	int index = 0;
	bool stop = false;
	int counter = 0;
	for (int i = 0; i < characters.size(); i++)
	{
		characters.at(i)->setName(characterNames.at(i));

		for (int j = 0; j < 4; j++)
		{
			attack = attacks.at(0);
			attacks.erase(attacks.begin());
			stats.push_back(atoi(attacks.at(0).c_str()));
			attacks.erase(attacks.begin());
			stats.push_back(atoi(attacks.at(0).c_str()));
			attacks.erase(attacks.begin());
			characters.at(i)->setAttacks(attack, stats);
			stats.clear();
		}
		
		
	}

	characterNames.clear();
	attacks.clear();
	stats.clear();


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

// Returns a pointer to the gui.
GUI* GameManager::getGUI()
{
	return &gui;
}

// Returns players.
vector<Player*>* GameManager::getPlayers()
{
	return currentPlayers;
}

// Creates a new game.
void GameManager::newGame()
{
	const int NUMBEROFPLAYERS = 4;

	// Instantiate player objects.
	// The passed argument indicates whether
	// the player is AI (Artificial Intelligence)
	for (int i = 0; i < NUMBEROFPLAYERS; i++)
	{
		players.push_back(new Player(true));
		players.at(i)->setOrder(i);
	}

	int choice;

	cout << "Choose game type:\n\n"
		<< "1) Human vs COM\n"
		<< "2) COM vs COM\n\n"
		<< "Choice: ";
	cin >> choice;

	if (choice == 1)
		players.at(0)->setAI(false);
}

void GameManager::loadGame()
{
	loadResources();
}

// Starts the game.
void GameManager::startGame()
{
	// Load characters and their attacks.
	loadResources();

	// Change the gameState to PLAYING
	gameState = GameState::PLAYING;

	// Display game banner.
	gui.displayBanner();	
	
	// Have players choose their character.
	for (int i = 0; i < players.size(); i++)
		chooseCharacter(players.at(i));

	int order = 0;
	tournament = new BinarySearchTree<Player*>();
	for (int i = 0; i < players.size() + (players.size() - 1); i++)
	{
		if (i < (players.size() - 1))
		{
			if (i % 2 == 0)
				order = i * 5;
			else
				order = -i * 5;

			Player* placeHolder = new Player(true);
			Character* holder = new Character();
			holder->setName("Placerholder " + to_string(i + 1));
			placeHolder->setCharacter(holder);
			placeHolder->setOrder(order);
			tournament->insert(placeHolder);
		}
		
		if (i >= (players.size() - 1))
		{
			if (i % 2 == 0)
				order = i - order;
			else
				order = -i + order;

			players.at(i - (players.size() - 1))->setOrder(order);
			tournament->insert(players.at(i - (players.size() - 1)));
		}
	}

	cout << "\n\n" << endl;
	tournament->print();

	// Start Battle.
	startBattle();
}

// Ends the game and displays who won the battle.
void GameManager::gameOver()
{
	cout << "\n" << setw(25) << "GAME OVER!" << endl;

	// Check what player won based on who has a health of 0. 
	if (players.at(0)->getCharacter()->getHealth() == 0)
		cout << setw(25) <<players.at(1)->getCharacter()->getName() << " WINS!!!" << endl;
	else
		cout << setw(25) << players.at(0)->getCharacter()->getName() << " WINS!!!" << endl;

	// Calls the destructor to clean up memory.
	cleanUp();
}

// Lets players choose a character.
void GameManager::chooseCharacter(Player* player)
{
	// Create a variable to store 
	// the number of the chosen character.
	int chosenCharacter;

	// If the player is not AI, 
	// show a list of characters
	// to choose from.
	if (!player->isPlayerAI())
	{
		// Count variable is used for character enumeration.
		int count = 0;

		cout << "Choose a character:\n\n" << "   NAME:" << endl;

		// Iterate through the characters map and print
		// them out so the player can choose one.

		for (int i = 0; i < characters.size(); i++)
		{
			count++;
			cout << count << ") " << characters.at(i)->getName() << endl;
		}

		// Receive chosen character player input.
		do
		{
			cout << "\nChosen characters: ";
			cin >> chosenCharacter;
		} while (chosenCharacter > characters.size() || chosenCharacter < 1);
	}
	// AI decision code for choosing a character.
	else
		chosenCharacter = rand() % characters.size() + 1;
	
	chosenCharacter--;

	// Instantiate a character object
	// and set it to the player.
	player->setCharacter(characters.at(chosenCharacter));
	characters.erase(characters.begin() + chosenCharacter);
}

// Starts the battle.
void GameManager::startBattle()
{
	currentPlayers = tournament->getPlayers();

	cout << "Players size: " << players.size() << endl;

	// Instantiate items stack.
	Item* anItem;
	int itemsStackSize = 25;
	for (int item = 0; item < itemsStackSize; item++)
	{
		anItem = new Item(rand() % 4 + 1);
		items.push(*anItem);
	}

	// Display the chosen characters.
	cout << "\n\n" << setw(30) << "THE BATTLE STARTS!\n"
	     << setw(20) << players.at(0)->getCharacter()->getName() 
		 << " VS " << players.at(1)->getCharacter()->getName()
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
	for (int i = 0; i < currentPlayers->size(); i++)
	{
		if (currentPlayers->at(i)->getChosenCard()->isItemCard())
		{
			// If a human is the one who chose the item
			// card, show him what he got and add it to
			// his bag.
			if (!currentPlayers->at(i)->isPlayerAI())
			{
				cout << "\nYou got item: "
					 << items.top().getType() << endl;
			}

			currentPlayers->at(i)->addItem(items.top());
			items.pop();
		}
	}

	// If the player chose a card with a higher attack
	// then he is the one who attacks.
	if (currentPlayers->at(0)->getChosenCard()->getAttack()
	     > currentPlayers->at(1)->getChosenCard()->getAttack())
	{
		cout << "\n" << setw(25) 
			 << currentPlayers->at(0)->getCharacter()->getName()
			 << " ATTACKS!" << endl;

		// Have the enemy take the attack of the player's
		// chosen card and the defense of his own card.
		currentPlayers->at(1)->getCharacter()
			->defend(currentPlayers->at(0)->getChosenCard()->getAttack(),
			currentPlayers->at(1)->getChosenCard()->getDefense());
	}

	// If the attack value on the player's chosen card
	// is the same as the attack value on the enemy's
	// chosen card and they are not item cards, then
	// it is a DRAW and both players have to choose
	// another card.
	else if (currentPlayers->at(0)->getChosenCard()->getAttack()
		== currentPlayers->at(1)->getChosenCard()->getAttack()
			 && !currentPlayers->at(0)->getChosenCard()->isItemCard())
	{
		cout << "\n" << setw(25) 
			 << "DRAW! Choose another card!" << endl;

		replaceCards();
		currentPlayers->at(0)->attack();
		currentPlayers->at(1)->attack();
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
		if (!currentPlayers->at(1)->getChosenCard()->isItemCard())
		{
			cout << "\n" << setw(25)
				<< "Enemy ATTACKS!" << endl;

			// Have the player take the attack value of the enemy's
			// chosen card and the defense of his own card.
			currentPlayers->at(0)->getCharacter()
				->defend(currentPlayers->at(1)->getChosenCard()->getAttack(),
				currentPlayers->at(0)->getChosenCard()->getDefense());
		}
	}

	// Replace the chosen cards.
	replaceCards();

	cout << "\n";
}

// Replaces the cards chosen by the players.
void GameManager::replaceCards()
{
	for (int i = 0; i < currentPlayers->size(); i++)
		currentPlayers->at(i)->getHand()->replaceCard();
}

void GameManager::battleMenu()
{
	// Create choice variable.
	int choice;

	for (int i = 0; i < currentPlayers->size(); i++)
	{
		if (!currentPlayers->at(i)->isPlayerAI())
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
					currentPlayers->at(i)->attack();
					break;
				case 2:
					// If the bag of the layer is not
					// empty look at his items.
					if (!currentPlayers->at(i)->getItems()->empty())
					{
						// Display the items inside
						// the player's bag.
						currentPlayers->at(i)->viewItems();

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
							map<string, int>* items = currentPlayers->at(i)->getItems();

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
								currentPlayers->at(i)->applyItem(choice);
							else
							{
								// If the chosen item is a Special Attack,
								// make sure the player has the minimum
								// energy to perform it.
								if (currentPlayers->at(i)->getCharacter()->getEnergy() > 10
									&& iterator->first == "Special Attack")
									currentPlayers->at(i)->applyItem(choice);
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
		else
		{
			// Create a variable for the chosen item.
			int chosenItem = 0;

			int count = 0;

			// If the bag of the enemy is not empty
			// have him look at its contents.
			if (!currentPlayers->at(i)->getItems()->empty())
			{
				// Create pointer that points to the 
				// enemy's bag.
				map<string, int>* items = currentPlayers->at(i)->getItems();

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
						if (currentPlayers->at(i)->getCharacter()->getHealth()
							< minHealthThreshold)
							chosenItem = count;
					}

					// If item is an Energy Package.
					if (iterator->first == "Energy Package")
					{
						// Use the energy package only when
						// the energy is less than the maximum
						// energy.
						if (currentPlayers->at(i)->getCharacter()->getEnergy()
							< currentPlayers->at(i)->getCharacter()->getMaxEnergy())
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
						if (currentPlayers->at(i)->getCharacter()->getEnergy() >= minEnergyNeeded)
							chosenItem = count;
					}
				}

				// Apply the chosen item.
				if (chosenItem != 0)
					currentPlayers->at(i)->applyItem(chosenItem);
				// If an item was not chosen then attack.
				else
					currentPlayers->at(i)->attack();
			}
			// If the enemy's bag is empty attack.
			else
				currentPlayers->at(i)->attack();
		}
	}		
}