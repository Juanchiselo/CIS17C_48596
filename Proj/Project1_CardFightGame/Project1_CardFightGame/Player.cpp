#include "Player.h"
#include "GameManager.h"

// Overloaded constructor for the Player class.
Player::Player(bool isAI)
{
	// Set the AI variable for the player.
	this->isAI = isAI;

	// Make a local map of characters for further code readability.
	map<string, string> characters = GameManager::getInstance()->getCharacters();

	// Create a variable to store the number of the chosen character.
	int chosenCharacter;

	// If the player is not AI, show a list of characters
	// to choose from.
	if (!isAI)
	{
		// Count variable is used for character enumeration.
		int count = 0;

		cout << "Choose a character:\n\n" << "   NAME:"
			 << setw(25) << "UNIVERSE:" << endl;

		// Iterate through the characters map and print
		// them out so the player can choose one.
		for (auto iterator = characters.begin(); 
			iterator != characters.end(); iterator++)
		{
			count++;
			cout << count << ") "  << iterator->first
			     << setw(25) << iterator->second << endl;
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
		chosenCharacter = rand() % 8 + 1;

	// Create an iterator and move it where the chosen
	// character is located in the map.
	auto iterator = characters.begin();
	advance(iterator, (chosenCharacter - 1));

	// Instantiate a character object.
	character = new Character(iterator->first);
}

// Destructor for the player class.
Player::~Player()
{
	delete character;
}

// Returns wheter the player is AI.
bool Player::isPlayerAI()
{
	return isAI;
}

// Returns a pointer to the card
// chosen by the player.
Card* Player::getChosenCard()
{
	return chosenCard;
}

// Returns a pointer to the character
// of the player.
Character* Player::getCharacter()
{
	return character;
}

// Returns a pointer to the hand
// of the player.
Hand* Player::getHand()
{
	return &hand;
}

// Returns whether the player has
// items in his bag.
map<string, int>* Player::getItems()
{
	return &items;
}

// Prints out the cards on the hand of the
// player and allows him to choose a card.
void Player::attack()
{
	// Create a variable for the chosen card.
	int selectedCard = 0;

	// If the player is not AI ask him for to
	// choose a card from his hand.
	if (!isAI)
	{
		do
		{
			cout << endl;

			// Print the cards on the hand of the
			// player.
			hand.displayHand();

			cout << "\nChoose a card: ";
			cin >> selectedCard;
		} while (selectedCard > 5 || selectedCard < 1);

		// Decrease the chosenCard variable so
		// that it matches with the subscripts
		// of the deque container.
		selectedCard--;
	}
	// AI decision code for choosing the best card
	// in the hand of the player.
	else
	{
		hand.displayHand();

		Card* currentCard;

		int bestCardAttack = 0;
		int bestCardDefense = 0;

		// Variable used to stop choosing cards
		// if an item card has already been chosen.
		bool itemCardChosen = false;

		// Loop through the 5 cards on the hand.
		for (int card = 0; card < 5; card++)
		{
			// Get a card.
			currentCard = hand.getCard(card);

			// If it is an item card, choose it.
			if (currentCard->isItemCard())
			{
				selectedCard = card;
				itemCardChosen = true;
			}

			// Check which car has the best attack and
			// best defense so it can be chosen as long as
			// an item card has not been chosen.
			if (bestCardAttack < currentCard->getAttack() && !itemCardChosen)
			{
				bestCardAttack = currentCard->getAttack();
				bestCardDefense = currentCard->getDefense();
				selectedCard = card;

				if (bestCardDefense < currentCard->getDefense())
				{
					bestCardDefense = currentCard->getDefense();
					selectedCard = card;
				}
			}
		}
	}

	// Points the currentCard pointer to
	// the chosen card.
	chosenCard = hand.getCard(selectedCard);
}

// Adds an item to the player's bag.
void Player::addItem(Item item)
{
	items[item.getType()] += 1;
}

// Displays the items on the player's bag.
void Player::viewItems()
{
	int count = 0;

	cout << "\n\nItems in your bag: " << endl;

	for (auto iterator = items.begin(); iterator != items.end(); iterator++)
	{
		count++;
		cout << count << ") " << iterator->first
			 << "     Quantity: " << iterator->second << endl;
	}
}

// Applies an item from the player's bag.
void Player::applyItem(int item)
{
	// Create an iterator and move it where the chosen
	// item is located in the map.
	auto iterator = items.begin();
	advance(iterator, (item - 1));

	// Create a used item variable and get the
	// type of the used item.
	string usedItem = iterator->first;

	// Create a variable for a special attack.
	string specialAttack;
	
	// If the used item is a special attack
	// display the special attacks of the
	// player's character.
	if (usedItem == "Special Attack")
	{
		// I NEED TO FINISH IMPLEMENTING THIS
		// BY OUTSOURCING SPECIAL ATTACKS TO
		// A .TXT FILE.

		int choice;
		int attack;
		int energyCost;

		if (!isAI)
		{
			do
			{
				cout << "\n\nChoose a Special Attack:\n"
					<< "1) Kamehameha        A: 25 E: 30\n"
					<< "2) Spirit Bomb       A: 40 E: 50\n"
					<< "3) Dragon Fist       A: 20 E: 20\n"
					<< "4) Ki Blast          A: 15 E: 10\n\n"
					<< "Choice: ";
				cin >> choice;

				cout << "\n\n" << character->getName()
					<< " used ";

				switch (choice)
				{
				case 1:
					cout << "Kamehameha." << endl;
					attack = 25;
					energyCost = 30;
					break;
				case 2:
					cout << "Spirit Bomb." << endl;
					attack = 40;
					energyCost = 50;
					break;
				case 3:
					cout << "Dragon Fist." << endl;
					attack = 20;
					energyCost = 20;
					break;
				case 4:
					cout << "Ki Blast." << endl;
					attack = 15;
					energyCost = 10;
					break;
				default:
					cout << "ERROR: Not a valid choice" << endl;
					choice = 0;
				}
			} while (choice == 0 || character->getEnergy() < energyCost);

			GameManager::getInstance()->getEnemy()
				->getCharacter()->defend(attack, 0);
			getCharacter()->decreaseEnergy(energyCost);
			GameManager::getInstance()->getGUI()->drawStats();
		}
		else
		{
			choice = rand() % 4 + 1;

			cout << "\n\n" << character->getName()
				<< " used ";

			switch (choice)
			{
			case 1:
				cout << "Kamehameha." << endl;
				attack = 25;
				energyCost = 30;
				break;
			case 2:
				cout << "Spirit Bomb." << endl;
				attack = 40;
				energyCost = 50;
				break;
			case 3:
				cout << "Dragon Fist." << endl;
				attack = 20;
				energyCost = 20;
				break;
			case 4:
				cout << "Ki Blast." << endl;
				attack = 15;
				energyCost = 10;
				break;
			default:
				break;
			}

			GameManager::getInstance()->getPlayer()
				->getCharacter()->defend(attack, 0);
			character->decreaseEnergy(energyCost);
			GameManager::getInstance()->getGUI()->drawStats();
		}
	}
		
	// If the used item is a health package.
    if (usedItem == "Health Package")
	{
		// Randomly choose the health contained
		// in the health package.
		int extraHealth = rand() % 11 + 5;

		// Display how much health was in the 
		// health package.
		cout << "\n\nYour health package contained "
			 << extraHealth << " health." << endl;

		// Add the health to the character.
		character->addHealth(extraHealth);

		// Display stats to see the added health.
		cout << "\n\n";
		GameManager::getInstance()->getGUI()->drawStats();
	}

	// If the used item is an energy package.
	if (usedItem == "Energy Package")
	{
		// Randomly choose the energy contained
		// in the energy package.
		int extraEnergy = rand() % 10 + 5;

		// Display how much energy was in the
		// energy package.
		cout << "\n\nYour energy package contained "
			 << extraEnergy << " energy." << endl;

		 // Add the energy to the character.
		character->addEnergy(extraEnergy);

		// Display stats to see the added energy.
		cout << "\n\n";
		GameManager::getInstance()->getGUI()->drawStats();
	}

	// If the used item is a cards swap item.
	if (usedItem == "Cards Swap")
	{
		// Display the old cards.
		cout << "\n\nYour old cards: " << endl;
		hand.displayHand();
		
		// Replace the cards on the hand
		// for new cards.
		for (int card = 0; card < 5; card++)
		{
			// Always get the first card
			// because when the card is replaced
			// the next card moves to the first spot.
			hand.getCard(0);
			hand.replaceCard();
		}

		// Display the new cards.
		cout << "\n\nYour new cards: " << endl;
		hand.displayHand();
	}

	// If the player has more than one of the
	// same item in his bag reduce the quantity
	// by one when the item is used.
	if (iterator->second > 1)
		items[usedItem] -= 1;
	// Otherwise delete the item from the bag.
	else
		items.erase(usedItem);
}

