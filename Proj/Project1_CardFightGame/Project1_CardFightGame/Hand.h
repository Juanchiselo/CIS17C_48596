/*
 * Jose Sandoval
 * CIS-17C: C++ Programming
 * November 11, 2014
 * Project #1: Card Fight Game
 * Description: A fighting game that uses cards.
 */

#ifndef HAND_H
#define HAND_H

#include <list>
#include <deque>
#include <string>

#include "Deck.h"

using namespace std;

class Hand
{
private:
	int size;
	int chosenCard;
	Deck* deck;
	deque<Card> currentHand;
public:
	Hand();
	~Hand();
	void replaceCard();
	void displayHand();
	Card* getCard(int);

};

#endif // HAND_H