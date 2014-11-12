/*
 * Jose Sandoval
 * CIS-17C: C++ Programming
 * November 11, 2014
 * Project #1: Card Fight Game
 * Description: A fighting game that uses cards.
 */

#include <iostream>
#include <ctime>

#include "Game.h"

using namespace std;


int main()
{
	srand(static_cast<unsigned int>(time(0)));
	
	Game game;

	game.startGame();
	game.startBattle();
	
	return 0;
}