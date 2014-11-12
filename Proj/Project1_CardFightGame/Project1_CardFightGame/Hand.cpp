#include "Hand.h"

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
	currentHand.erase(currentHand.begin() + chosenCard);
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
	this->chosenCard = chosenCard;

	return &currentHand.at(chosenCard);
}