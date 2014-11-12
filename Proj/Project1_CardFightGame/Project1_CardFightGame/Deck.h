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

Deck::Deck()
{
	size = 100;

	for (int card = 0; card < size; card++)
	{
		Card* aCard = new Card(rand() % 9 + 1, rand() % 9 + 1);
		cards.push(*aCard);
	}
}

Deck::~Deck()
{

}

Card Deck::getCard()
{
	Card card = cards.front();
	cards.pop();
	return card;
}

void Deck::displayDeck()
{
	for (int i = 0; i < cards.size(); i++)
	{
		cards.front().print();
		cards.pop();
	}
}

#endif //DECK_H