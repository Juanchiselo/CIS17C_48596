#include "GUI.h"

GUI::GUI()
{
}

GUI::~GUI()
{
}

string GUI::drawBox(int horizontalSize, int verticalSize, int leftPadding, int rightPadding)
{
	string graphic;
	
	for (int y = 0; y < verticalSize; y++)
	{
		// Draw top part of the box
		if (y == 0)
		{
			drawTopBox(horizontalSize);
		}

		// Draw middle part of the box
		if (y > 0 && y < verticalSize - 1)
		{
			graphic += vertical;

			graphic += vertical;
		}

		// Draw bottom part of the box
		if (y == verticalSize - 1)
		{
			drawBottomBox(horizontalSize);
		}		

		graphic += "\n";
	}
	
	return graphic;
}

string GUI::drawTopBox(int horizontalSize)
{
	graphic = "";
	graphic += upperLeftCorner;
	for (int x = 0; x < horizontalSize; x++)
		graphic += horizontal;
	graphic += upperRightCorner;

	return graphic;
}

string GUI::drawBottomBox(int horizontalSize)
{
	graphic = "";
	graphic += lowerLeftCorner;
	for (int x = 0; x < horizontalSize; x++)
		graphic += horizontal;
	graphic += lowerRightCorner;

	return graphic;
}