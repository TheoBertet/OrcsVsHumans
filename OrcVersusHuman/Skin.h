// Skin.h
// Author : Théo Bertet
// Description : This file contains all the data structure for skins. Skins are just lines of characters that represents characters in
// the fight part.
#pragma once
#include<iostream>
#include <vector>

class Skin
{
protected:
	std::string name;					// Name of the skin
	std::vector<std::string> lines;		// All the characters lines that represents the character

public:
	// Constructor
	Skin();
	// Confort constructor
	Skin(std::string _name, std::vector<std::string> _lines);
	// Destructor
	~Skin();

	std::string GetName();					// Get the skin's name
	std::vector<std::string> GetLines();	// Get all the skin's lines representing the character
};

