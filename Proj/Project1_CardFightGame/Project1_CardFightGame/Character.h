/*
 * Jose Sandoval
 * CIS-17C: C++ Programming
 * November 11, 2014
 * Project #1: Card Fight Game
 * Description: A fighting game that uses cards.
 */

#ifndef CHARACTER_H
#define CHARACTER_H

// System Libraries
#include <string>

using namespace std;

class Character
{
private:
	string name;
	int health;
	int energy;
	int maxHealth;
	int maxEnergy;
public:
	Character(string);
	~Character();
	string getName();
	int getHealth();
	int getEnergy();
	int getMaxHealth();
	int getMaxEnergy();
	void addHealth(int);
	void addEnergy(int);
	void decreaseEnergy(int);
	void defend(int, int);
};

#endif // CHARACTER_H