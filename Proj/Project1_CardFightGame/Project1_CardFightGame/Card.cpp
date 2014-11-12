#include "Card.h"

Card::Card(int attack, int defense)
{
	this->attack = attack;
	this->defense = defense;
}

Card::~Card()
{
}

void Card::print()
{
	cout << "A: " << attack << "  "
		<< "D: " << defense << endl;
}

int Card::getAttack()
{
	return attack;
}

int Card::getDefense()
{
	return defense;
}
