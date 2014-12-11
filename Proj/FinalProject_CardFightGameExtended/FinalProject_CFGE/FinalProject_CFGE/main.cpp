/*
 * Jose Sandoval
 * CIS-17C: C++ Programming
 * November 11, 2014
 * Project #1: Card Fight Game
 * Description: A fighting game that uses cards.
 */

// System libraries
#include <ctime>

// Header files
#include "GameManager.h"

int main()
{
	// Initialize the random number generator.
	srand(static_cast<unsigned int>(time(0)));

	// Instatiate GameManager object and start game.
	GameManager::getInstance()->newGame();
	GameManager::getInstance()->startGame();
	
	char answer;

	do
	{
		cout << "Would you like to battle again? (Y/N)" << endl;
		cin >> answer;

		switch (answer)
		{
		case 'y':
		case 'Y':
			GameManager::getInstance()->newGame();
			GameManager::getInstance()->startGame();
			break;
		case 'n':
		case 'N':
			cout << "Goodbye!" << endl;
			break;
		default:
			cout << "ERROR: Not a valid choice!\n\n" << endl;
		}
	} while (answer != 'n' && answer != 'N');

	return 0;
}