/*
 * Jose Sandoval
 * CIS-17C: C++ Programming
 * November 11, 2014
 * Project #1: Card Fight Game
 * Description: A fighting game that uses cards.
 */

#include "Character.h"
#include "GameManager.h"

// Overloaded constructor for Character class.
Character::Character(string name)
{
	this->name = name;
	health = 50;
	energy = 50;
	maxHealth = health;
	maxEnergy = energy;
}

// Destructor for Character class.
Character::~Character()
{
}

// Returns the name of the character.
string Character::getName()
{
	return name;
}

// Returns the health of the character.
int Character::getHealth()
{
	return health;
}

// Returns the energy of the character.
int Character::getEnergy()
{
	return energy;
}

// Returns the maximum health of the character.
int Character::getMaxHealth()
{
	return maxHealth;
}

// Returns the maximum energy of the character.
int Character::getMaxEnergy()
{
	return maxEnergy;
}

// Adds health to the character when the
// player has used a health package.
void Character::addHealth(int addedHealth)
{
	// If the health is less than the
	// maximum health, add health.
	if (health < maxHealth)
		health += addedHealth;

	// If health goes over the maximum
	// health, set the health equal to
	// the maximum health.
	if (health > maxHealth)
		health = maxHealth;
}

// Adds energy to the character when the
// player has used an energy package.
void Character::addEnergy(int addedEnergy)
{
	// If the energy is less than the
	// maximum energy, add energy.
	if (energy < maxEnergy)
		energy += addedEnergy;

	// If the energy goes over the
	// maximum energy, set the energy equal
	// to the maximum energy.
	if (energy > maxEnergy)
		energy = maxEnergy;
}

// Decreases the energy of the character
// when the character has used a
// special attack.
void Character::decreaseEnergy(int usedEnergy)
{
	energy -= usedEnergy;
}

// The character defends himself
void Character::defend(int damage, int defense)
{
	// Take the damage off the defense.
	defense -= damage;

	// If the defense is less than or
	// equal to zero, take the remaining
	// damage off the health.
	if (defense <= 0)
		health += defense;

	// If the health of the character is less than
	// or equal to zero, set the health to 0 and
	// set the gameState to GAMEOVER.
	if (health <= 0)
	{
		health = 0;
		GameManager::getInstance()->setGameState(GameState::GAMEOVER);
	}
}