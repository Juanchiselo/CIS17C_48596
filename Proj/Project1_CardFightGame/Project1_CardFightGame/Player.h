/*
* Jose Sandoval
* CIS-17C: C++ Programming
* November 11, 2014
* Project #1: Card Fight Game
* Description: A fighting game that uses cards.
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"
#include "Character.h"

using namespace std;

class Player
{
private:
	Hand hand;
	Card* currentCard;
	Character* character;
public:
	Player(bool);
	~Player();
	void displayHand();
	void attack(bool);
	Character* getCharacter();
	Card* getCurrentCard();
};

Player::Player(bool ai)
{
	int chosenCharacter;

	do
	{
		if (!ai)
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
}

Player::~Player()
{

}

void Player::displayHand()
{
	hand.displayHand();
}

void Player::attack(bool ai)
{
	int chosenCard;

	if (!ai)
	{
		do
		{
			cout << "\n\nChoose a card:\n" << endl;
			displayHand();
			cin >> chosenCard;
		} while (chosenCard > 5 || chosenCard < 1);
	}
	else
		chosenCard = rand() % 4 + 1;
	
	currentCard = hand.getCard(chosenCard - 1);

	if (!ai)
	{
		cout << "\nYou chose card:" << endl;
		currentCard->print();
	}
	else
	{
		cout << "\nEnemy chose card:" << endl;
		currentCard->print();
	}
}

Card* Player::getCurrentCard()
{
	return currentCard;
}

Character* Player::getCharacter()
{
	return character;
}
#endif // PLAYER_H