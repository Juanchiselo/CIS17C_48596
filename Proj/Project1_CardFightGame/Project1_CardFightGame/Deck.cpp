#include "Deck.h"

Deck::Deck(int deckSize)
{
	this->deckSize = deckSize;

	for (int card = 0; card < deckSize; card++)
	{
		Card* aCard = new Card(rand() % 9 + 1, rand() % 4 + 1);
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