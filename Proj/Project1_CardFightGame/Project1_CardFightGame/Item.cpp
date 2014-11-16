/*
 * Jose Sandoval
 * CIS-17C: C++ Programming
 * November 11, 2014
 * Project #1: Card Fight Game
 * Description: A fighting game that uses cards.
 */

#include "Item.h"

// Overloaded constructor for Item class.
Item::Item(int itemType)
{
	switch (itemType)
	{
	case 1:
		type = "Special Attack";
		break;
	case 2:
		type = "Health Package";
		break;
	case 3:
		type = "Energy Package";
		break;
	case 4:
		type = "Cards Swap";
		break;
	default:
		break;
	}
}

// Destructor for Item class.
Item::~Item()
{
}

// Returns the type of the item.
string Item::getType()
{
	return type;
}