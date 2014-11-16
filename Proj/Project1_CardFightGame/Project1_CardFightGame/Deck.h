/*
 * Jose Sandoval
 * CIS-17C: C++ Programming
 * November 11, 2014
 * Project #1: Card Fight Game
 * Description: A fighting game that uses cards.
 */

#ifndef DECK_H
#define DECK_H

// System Libraries
#include <queue>

// Header Files
#include "Card.h"

using namespace std;

class Deck
{
private:
	int size;
	queue<Card> cards;
public:
	Deck(int);
	~Deck();
	int getSize();
	Card getCard();
};

#endif //DECK_H