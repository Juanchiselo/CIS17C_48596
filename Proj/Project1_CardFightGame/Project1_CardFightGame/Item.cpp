#include "Item.h"

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
		type = "Card swap";
		break;
	default:
		break;
	}
}

Item::~Item()
{

}

string Item::getType()
{
	return type;
}