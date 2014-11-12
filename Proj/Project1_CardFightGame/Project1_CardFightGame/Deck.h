/*
 * Jose Sandoval
 * CIS-17C: C++ Programming
 * November 11, 2014
 * Project #1: Card Fight Game
 * Description: A fighting game that uses cards.
 */

#ifndef DECK_H
#define DECK_H

#include <queue>
#include <stack>

#include "Card.h"

using namespace std;

class Deck
{
private:
	queue<Card> cards;
	int size;
public:
	Deck();
	~Deck();
	void displayDeck();
	Card getCard();
};

#endif //DECK_H