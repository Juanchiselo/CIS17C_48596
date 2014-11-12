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

#include "Deck.h"

using namespace std;

class Hand
{
private:
	int size;
	Deck deck;
	deque<Card> currentHand;
public:
	Hand();
	~Hand();
	void replaceCard();
	void displayHand();
	Card* getCard(int);
};

Hand::Hand()
{
	size = 5;

	for (int card = 0; card < size; card++)
		currentHand.push_back(deck.getCard());
}

Hand::~Hand()
{

}

void Hand::replaceCard()
{
	currentHand.push_back(deck.getCard());
}

void Hand::displayHand()
{
	int count = 0;
	for (auto iterator = currentHand.begin();
		iterator != currentHand.end(); iterator++)
	{
		count++;
		cout << "Card #" << count << ":  ";
		iterator->print();
	}
}

Card* Hand::getCard(int chosenCard)
{
	Card* card = &currentHand.at(chosenCard);
	currentHand.erase(currentHand.begin() + chosenCard);
	replaceCard();
	return card;
}

#endif // HAND_H