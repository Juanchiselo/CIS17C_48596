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
	char leftUpperCorner = 201;
	char rightUpperCorner = 187;
	char leftLowerCorner = 200;
	char rightLowerCorner = 188;
	char horizontal = 205;
	char vertical = 186;

	cout << leftUpperCorner << horizontal << horizontal << horizontal
		<< horizontal << horizontal << horizontal << rightUpperCorner
		<< "\n" << vertical << "      " << vertical << "\n" << vertical
		<< " A: " << attack << " " << vertical << "\n" << vertical
		<< " D: " << defense << " " << vertical << "\n" << vertical
		<< "      " << vertical << "\n" << leftLowerCorner
		<< horizontal << horizontal << horizontal << horizontal
		<< horizontal << horizontal << rightLowerCorner << endl;
}

int Card::getAttack()
{
	return attack;
}

int Card::getDefense()
{
	return defense;
}
