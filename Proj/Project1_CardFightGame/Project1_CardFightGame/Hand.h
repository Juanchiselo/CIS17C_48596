/*
 * Jose Sandoval
 * CIS-17C: C++ Programming
 * November 11, 2014
 * Project #1: Card Fight Game
 * Description: A fighting game that uses cards.
 */

#ifndef HAND_H
#define HAND_H

// System Libraries
#include <deque>
#include <string>
#include <iostream>

// Header Files
#include "Deck.h"

using namespace std;

class Hand
{
private:
	int chosenCard;
	Deck* deck;
	deque<Card> hand;
public:
	Hand();
	~Hand();
	Card* getCard(int);
	void replaceCard();
	void displayHand();
};

#endif // HAND_H