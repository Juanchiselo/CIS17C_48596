#include "Player.h"
#include "Game.h"

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
	cout << "Player destroyed" << endl;
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
			cout << endl;
			displayHand();
			cout << "\nChoose a card: ";
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
