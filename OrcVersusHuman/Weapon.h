// Weapon.h
// Author : Théo Bertet
// Description : This file contains all the data structure for weapons.
#include <iostream>

#pragma once
class Weapon
{
protected:
	std::string name;		// Weapon's name
	int damages;			// Weapon's damages

public:
	// Constructor
	Weapon();
	// Copy constructor
	Weapon(const Weapon &copyWeapon);
	// Comfort constructor
	Weapon(std::string _name, int _damages);
	// Destructor
	~Weapon();

	// Method to clone an armor, same as a copy constructor
	Weapon* Clone();

	std::string GetName();		// Get the weapon's name
	int GetDamages();			// Get the weapon's damages
};

