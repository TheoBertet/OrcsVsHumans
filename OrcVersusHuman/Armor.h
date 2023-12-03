// Armor.h
// Author : Théo Bertet
// Description : This file contains all the data structure for Fighters' armors.
#include <iostream>

#pragma once
class Armor
{
protected:
	std::string name;		// Armor's name
	int armorPoints;		// Armor's health points
	int currentAp;			// Current armor's health points

public:
	// Default Constructor
	Armor();
	// Copy Constructor
	Armor(const Armor &copyArmor);
	// Comfort Constructor
	Armor(std::string _name, int _armorPoints);
	// Destructor
	~Armor();

	// Method to clone an armor, same as a copy constructor
	Armor* Clone();



	/// <summary>
	/// Method that deals damages to the armor's health points. Minimum armor points is 0 ; exceeded damage are ignored.
	/// </summary>
	/// <param name="damages">The damages dealt to the armor</param>
	void Damages(int damages);

	/// <summary>
	/// Method that heal the armor's health points. Maximum armor points is "armorPoints" variable. Exceeded repair points are ignored.
	/// </summary>
	/// <param name="repair"></param>
	void Repair(int repair);

	/// <summary>
	/// Method that indicates if the armor is broken or not.
	/// </summary>
	/// <returns>TRUE if broken, FALSE if not</returns>
	bool IsBroken();



	// Method to get the armor's name
	std::string GetName();
	// Method to get the maximum armor points
	int GetArmorPoints();
	// Method to get the current armor points
	int GetCurrentArmorPoints();
};

