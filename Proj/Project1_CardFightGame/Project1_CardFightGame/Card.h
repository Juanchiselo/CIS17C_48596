/*
 * Jose Sandoval
 * CIS-17C: C++ Programming
 * November 11, 2014
 * Project #1: Card Fight Game
 * Description: A fighting game that uses cards.
 */

#ifndef CARD_H
#define CARD_H

#include <iostream>

using namespace std;

class Card
{
private:
	int attack;
	int defense;
public:
	Card(int attack, int defense);
	~Card();
	void print();
	int getAttack();
	int getDefense();
};

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

#endif //CARD_H