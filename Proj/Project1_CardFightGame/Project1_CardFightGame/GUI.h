/*
* Jose Sandoval
* CIS-17C: C++ Programming
* November 11, 2014
* Project #1: Card Fight Game
* Description: A fighting game that uses cards.
*/

#ifndef GUI_H
#define GUI_H

#include <string>
#include <iostream>

using namespace std;

class GUI
{
private:
	char upperLeftCorner = 201;
	char upperRightCorner = 187;
	char lowerLeftCorner = 200;
	char lowerRightCorner = 188;
	char horizontal = 205;
	char vertical = 186;
	string graphic;
public:
	GUI();
	~GUI();
	string drawBox(int, int, int, int);
	string drawTopBox(int);
	string drawBottomBox(int);
};

#endif // HAND_H