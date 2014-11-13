#include "Player.h"

Player::Player(bool isAI)
{
	this->isAI = isAI;
	int chosenCharacter;

	do
	{
		if (!isAI)
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

void Player::attack()
{
	int chosenCard;

	if (!isAI)
	{
		do
		{
			cout << "\n\nChoose a card:\n" << endl;
			displayHand();
			cin >> chosenCard;
		} while (chosenCard > 5 || chosenCard < 1);
		chosenCard--;
	}
	else
	{
		int bestCardAttack = 0;
		int bestCardDefense = 0;
		for (int card = 0; card < 5; card++)
		{
			currentCard = hand.getCard(card);
			if (bestCardAttack < currentCard->getAttack())
			{
				bestCardAttack = currentCard->getAttack();
				chosenCard = card;

				if (bestCardDefense < currentCard->getDefense())
				{
					bestCardDefense = currentCard->getDefense();
					chosenCard = card;
				}
			}
		}
	}

	currentCard = hand.getCard(chosenCard);

	if (!isAI)
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

Hand* Player::getHand()
{
	return &hand;
}
