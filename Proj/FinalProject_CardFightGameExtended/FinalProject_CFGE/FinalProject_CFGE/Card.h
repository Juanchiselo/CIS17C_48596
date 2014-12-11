/*
 * Jose Sandoval
 * CIS-17C: C++ Programming
 * November 11, 2014
 * Project #1: Card Fight Game
 * Description: A fighting game that uses cards.
 */

#ifndef CARD_H
#define CARD_H

class Card
{
private:
	int attack;
	int defense;
	bool isSpecialCard;
public:
	Card(int attack, int defense);
	~Card();
	int getAttack();
	int getDefense();
	bool isItemCard();
};

#endif //CARD_H