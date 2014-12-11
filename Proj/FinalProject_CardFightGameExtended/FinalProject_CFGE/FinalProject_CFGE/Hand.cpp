/*
 * Jose Sandoval
 * CIS-17C: C++ Programming
 * November 11, 2014
 * Project #1: Card Fight Game
 * Description: A fighting game that uses cards.
 */

#include "Hand.h"
#include "GameManager.h"

// Constructor for Hand class.
Hand::Hand()
{
	// Create a deck with 200 cards.
	deck = new Deck(200);

	// Fill the hand with 5 cards from the deck.
	for (int card = 0; card < 5; card++)
		hand.push_back(deck->getCard());
}

// Destructor for Hand class.
Hand::~Hand()
{
	delete deck;
}

// Get the chosen card from the hand.
Card* Hand::getCard(int chosenCard)
{
	this->chosenCard = chosenCard;

	return &hand.at(chosenCard);
}

// Replaces the chosen card from the hand
// with the next card on the deck.
void Hand::replaceCard()
{
	hand.erase(hand.begin() + chosenCard);
	hand.push_back(deck->getCard());
}

// Displays the cards on the hand.
void Hand::displayHand()
{
	GameManager::getInstance()->getGUI()->drawHandCards(&hand);
}