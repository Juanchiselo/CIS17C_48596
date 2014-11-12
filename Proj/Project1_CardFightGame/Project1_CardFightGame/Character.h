/*
* Jose Sandoval
* CIS-17C: C++ Programming
* November 11, 2014
* Project #1: Card Fight Game
* Description: A fighting game that uses cards.
*/

#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <list>

using namespace std;

class Character
{
private:
	string name;
	int health;
	int energy;
	int experienceLevel;
	list<string> attacks;
public:
	Character(string);
	~Character();
	string getName();
	void defend(int, int);
	int getHealth();
	int getEnergy();
};

#endif // CHARACTER_H