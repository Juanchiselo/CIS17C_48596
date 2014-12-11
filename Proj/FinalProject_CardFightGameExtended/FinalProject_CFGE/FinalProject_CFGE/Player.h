/*
 * Jose Sandoval
 * CIS-17C: C++ Programming
 * November 11, 2014
 * Project #1: Card Fight Game
 * Description: A fighting game that uses cards.
 */

#ifndef PLAYER_H
#define PLAYER_H

// System Libraries
#include <iterator>
#include <iomanip>
#include <map>

// Header Files
#include "Hand.h"
#include "Item.h"
#include "Character.h"

using namespace std;

class Player
{
private:
	Hand hand;
	Card* chosenCard;
	Character* character;
	bool isAI;
	map<string, int> items;
	int order;
public:
	Player(bool);
	~Player();
	void setAI(bool);
	bool isPlayerAI();
	int getOrder();
	void setOrder(int);
	void setCharacter(Character*);
	Character* getCharacter();
	Card* getChosenCard();
	Hand* getHand();
	map<string, int>* getItems();
	void attack();
	void addItem(Item);
	void viewItems();
	void applyItem(int);
};

#endif // PLAYER_H