/*
 * Jose Sandoval
 * CIS-17C: C++ Programming
 * November 11, 2014
 * Project #1: Card Fight Game
 * Description: A fighting game that uses cards.
 */

#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item
{
private:
	string type;
public:
	Item(int);
	~Item();
	string getType();
};

#endif // ITEM_H