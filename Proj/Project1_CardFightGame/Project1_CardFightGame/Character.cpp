/*
 * Jose Sandoval
 * CIS-17C: C++ Programming
 * November 11, 2014
 * Project #1: Card Fight Game
 * Description: A fighting game that uses cards.
 */

#include "Character.h"
#include "Game.h"

Character::Character(string name)
{
	this->name = name;
	health = 100;
	energy = 100;
}

Character::~Character()
{

}

string Character::getName()
{
	return name;
}

int Character::getHealth()
{
	return health;
}

int Character::getEnergy()
{
	return energy;
}

void Character::defend(int damage, int defense)
{
	defense -= damage;

	if (defense <= 0)
		health += defense;

	if (health <= 0)
	{
		health = 0;
		Game::getInstance()->setGameState(GameState::GAMEOVER);
	}
}