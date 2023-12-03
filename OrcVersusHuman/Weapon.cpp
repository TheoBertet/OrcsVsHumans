// Weapon.cpp
// Author : Théo Bertet
// Description : This file contains all the methods for weapons.
#include "Weapon.h"

// Constructor
Weapon::Weapon()
{
	name = "N/A";
	damages = 0;
}

// Copy constructor
Weapon::Weapon(const Weapon& copyWeapon)
{
	name = copyWeapon.name;
	damages = copyWeapon.damages;
}

// Comfort constructor
Weapon::Weapon(std::string _name, int _damages)
{
	name = _name;
	damages = _damages;
}

// Destructor
Weapon::~Weapon()
{
	name = "Deleted";
	damages = 0;
}

// Method to clone an armor, same as a copy constructor
Weapon* Weapon::Clone()
{
	return new Weapon(*this);
}

// Get the weapon's name
std::string Weapon::GetName()
{
	return name;
}

// Get the weapon's damages
int Weapon::GetDamages()
{
	return damages;
}
