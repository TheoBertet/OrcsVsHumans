// Skin.cpp
// Author : Théo Bertet
// Description : This file contains all the methods for skins. Skins are just lines of characters that represents characters in
// the fight part.
#include "Skin.h"

// Constructor
Skin::Skin()
{
	name = "N/A";
	lines = std::vector<std::string>();
}

// Confort constructor
Skin::Skin(std::string _name, std::vector<std::string> _lines)
{
	name = _name;
	lines = _lines;
}

// Destructor
Skin::~Skin()
{
	name = "Deleted";
	lines.clear();
}

// Get the skin's name
std::string Skin::GetName()
{
	return name;
}

// Get all the skin's lines representing the character
std::vector<std::string> Skin::GetLines()
{
	return lines;
}
