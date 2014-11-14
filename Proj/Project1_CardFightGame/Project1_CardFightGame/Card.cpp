#include "Card.h"

Card::Card(int attack, int defense)
{
	this->attack = attack;
	this->defense = defense;

	if (attack == defense)
	{
		isItemCard = true;
		this->attack = 0;
		this->defense = 0;
	}
	else
		isItemCard = false;
}

Card::~Card()
{
}

void Card::print()
{
}

int Card::getAttack()
{
	return attack;
}

int Card::getDefense()
{
	return defense;
}

bool Card::getItemCard()
{
	return isItemCard;
}