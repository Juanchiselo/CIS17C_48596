/*
* Jose Sandoval
* CIS-17C: C++ Programming
* November 11, 2014
* Project #1: Card Fight Game
* Description: A fighting game that uses cards.
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"
#include "Item.h"
#include "Character.h"

using namespace std;

class Player
{
private:
	Hand hand;
	Card* currentCard;
	Character* character;
	bool isAI;
	map<Item, int> items;
public:
	Player(bool);
	~Player();
	void displayHand();
	void attack();
	Character* getCharacter();
	Card* getCurrentCard();
	Hand* getHand();
};

#endif // PLAYER_H