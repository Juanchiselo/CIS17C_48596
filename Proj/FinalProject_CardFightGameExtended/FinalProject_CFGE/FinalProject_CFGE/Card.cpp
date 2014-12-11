/*
 * Jose Sandoval
 * CIS-17C: C++ Programming
 * November 11, 2014
 * Project #1: Card Fight Game
 * Description: A fighting game that uses cards.
 */

#include "Card.h"

// Overloaded constructor for Card class.
Card::Card(int attack, int defense)
{
	// Set attack and defense of the card,
	// and make it a not special card.
	this->attack = attack;
	this->defense = defense;
	isSpecialCard = false;

	// Make it a special card if attack
	// value equals defense value and
	// set attack and defense values to 0.
	if (attack == defense)
	{
		isSpecialCard = true;
		this->attack = 0;
		this->defense = 0;
	}
}

// Destructor for Card class.
Card::~Card()
{
}

// Returns the attack value of the card.
int Card::getAttack()
{
	return attack;
}

// Returns the defense value of the card.
int Card::getDefense()
{
	return defense;
}

// Returns whether the card is a special card.
bool Card::isItemCard()
{
	return isSpecialCard;
}