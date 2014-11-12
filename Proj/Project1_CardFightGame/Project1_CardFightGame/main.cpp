/*
 * Jose Sandoval
 * CIS-17C: C++ Programming
 * November 11, 2014
 * Project #1: Card Fight Game
 * Description: A fighting game that uses cards.
 */

#include <iostream>
#include <ctime>

#include "Hand.h"
#include "Character.h"

using namespace std;

Character* chooseCharacter(bool);
void startBattle(Character*, Character*);

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	Character* playerCharacter = chooseCharacter(false);
	Character* enemyCharacter = chooseCharacter(true);

	startBattle(playerCharacter, enemyCharacter);
	
	return 0;
}

Character* chooseCharacter(bool random)
{
	int chosenCharacter;
	Character* character = NULL;

	do
	{
		if (!random)
		{
			cout << "Choose a character:\n"
				<< "1) Master Chief       (Halo)\n"
				<< "2) Darth Vader        (Star Wars)\n"
				<< "3) Harry Potter       (Harry Potter)\n"
				<< "4) Goku               (Dragon Ball)" << endl;
			cin >> chosenCharacter;
		}
		else
				chosenCharacter = rand() % 3 + 1;

		switch (chosenCharacter)
		{
		case 1:
			character = new Character("Master Chief");
			break;
		case 2:
			character = new Character("Darth Vader");
			break;
		case 3:
			character = new Character("Harry Potter");
			break;
		case 4:
			character = new Character("Goku");
			break;
		default:
			cout << "ERROR: Not a valid choice." << endl;
		}
		cout << "\n\n";
	} while (character == NULL);

	return character;
}

void startBattle(Character* playerCharacter,Character* enemyCharacter)
{
	cout << "The battle starts!" << endl;
	cout << playerCharacter->getName() << " vs " << enemyCharacter->getName() << endl;

	Hand playerHand;
	Hand enemyHand;

	cout << "Your cards: " << endl;
	playerHand.displayHand();
	cout << "\n\n";
	cout << "Enemy's cards: " << endl;
	enemyHand.displayHand();
}