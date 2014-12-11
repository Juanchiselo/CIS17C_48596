/*
 * Jose Sandoval
 * CIS-17C: C++ Programming
 * November 11, 2014
 * Project #1: Card Fight Game
 * Description: A fighting game that uses cards.
 */

#include "Deck.h"

// Overloaded constructor of Deck class.
Deck::Deck(int size)
{
	this->size = size;
	
	for (int card = 0; card < size; card++)
	{
		Card* aCard = new Card(rand() % 9 + 1, rand() % 5 + 1);
		cards.push(*aCard);
	}
}

// Destructor for Deck class.
Deck::~Deck()
{
}

// Returns the size of the deck.
int Deck::getSize()
{
	return size;
}

// Returns the first card on the deck.
Card Deck::getCard()
{
	Card card = cards.front();
	cards.pop();
	return card;
}