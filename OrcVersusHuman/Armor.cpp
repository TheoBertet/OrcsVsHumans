// Armor.cpp
// Author : Théo Bertet
// Description : This file contains all the functions for Fighters' armors.
#include "Armor.h"

// Default Constructor
Armor::Armor() : Armor("N/A", 0)
{
}

// Copy Constructor
Armor::Armor(const Armor& copyArmor) : Armor(copyArmor.name, copyArmor.armorPoints)
{
}

// Comfort Constructor
Armor::Armor(std::string _name, int _armorPoints)
{
	name = _name;
	armorPoints = _armorPoints;
	currentAp = armorPoints;
}

// Destructor
Armor::~Armor()
{
	name = "Deleted";
	armorPoints = 0;
}

// Method to clone an armor, same as a copy constructor
Armor* Armor::Clone()
{
	return new Armor(*this);
}

/// <summary>
/// Method that deals damages to the armor's health points. Minimum armor points is 0 ; exceeded damage are ignored.
/// </summary>
/// <param name="damages">The damages dealt to the armor</param>
void Armor::Damages(int damages)
{
	currentAp -= damages;
}

/// <summary>
/// Method that heal the armor's health points. Maximum armor points is "armorPoints" variable. Exceeded repair points are ignored.
/// </summary>
/// <param name="repair"></param>
void Armor::Repair(int repair)
{
	currentAp = std::min(armorPoints, currentAp + repair);
}

/// <summary>
/// Method that indicates if the armor is broken or not.
/// </summary>
/// <returns>TRUE if broken, FALSE if not</returns>
bool Armor::IsBroken()
{
	if (currentAp <= 0)
		return true;
	else
		return false;
}

// Method to get the armor's name
std::string Armor::GetName()
{
	return name;
}

// Method to get the maximum armor points
int Armor::GetArmorPoints()
{
	return armorPoints;
}

// Method to get the current armor points
int Armor::GetCurrentArmorPoints()
{
	return currentAp;
}
