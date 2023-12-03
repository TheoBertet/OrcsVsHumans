// DataManager.h
// Author : Théo Bertet
// Description : This file contains all the data structures for the data manager, including all the data accesses and data populating
// DATAMANAGER IS A SINGLETON.
#include <iostream>
#include <vector>
#include <fstream>
#include <nlohmann/json.hpp>	// This external lib is used to read json files
#include "Fighter.h"
#include "Weapon.h"
#include "Armor.h"
#include "Skill.h"
#include "Skin.h"

using json = nlohmann::json;

#pragma once
class DataManager
{
private:
	std::vector<Fighter> fighters;		// List of all the playable fighters
	std::vector<Weapon> weapons;		// List of all the weapons the fighters can handle
	std::vector<Armor> armors;			// List of all the armors the fighters can wear
	std::vector<Skill> skills;			// List of all the skills the fighters can cast
	std::vector<Skin> skins;			// List of all skins the fighters can use

	std::vector<std::string> fightLogs;	// List of all the fight logs. Used during the fight part to indicate the player everything that is interesting



	/// <summary>
	/// This method reads the fighters.json file and parse it in Fighter objects, and then push them in the Fighters vector
	/// </summary>
	void PopulateFighters();

	/// <summary>
	/// This method reads the weapons.json file and parse it in Weapon objects, and then push them in the Weapons vector
	/// </summary>
	void PopulateWeapons();

	/// <summary>
	/// This method reads the armors.json file and parse it in Armor objects, and then push them in the Armors vector
	/// </summary>
	void PopulateArmors();

	/// <summary>
	/// This method reads the skills.json file and parse it in Skill objects, and then push them in the Skills vector
	/// </summary>
	void PopulateSkills();

	/// <summary>
	/// This method reads the drawings.json file and parse it in Skin objects, and then push them in the Skins vector
	/// </summary>
	void PopulateSkins();

	// Constructor
	DataManager();
public:
	Fighter chosenFighter;	// The player's fighter
	Fighter enemy;			// The enemy's fighter

	/// <summary>
	/// This method is used to get the Singleton Instance.
	/// </summary>
	/// <returns></returns>
	static DataManager& GetInstance()
	{
		static DataManager instance;
		return instance;
	}



	/// <summary>
	/// Method to save the player fighter by indicating the id in the fighters vector
	/// If the id isn't correct, then the first fighter is chosen by default to prevent from errors.
	/// </summary>
	/// <param name="fighterId">The id of the fighter the player chose</param>
	void SetPlayerFighter(int fighterId);
	/// <summary>
	/// Get the player's fighter variable
	/// </summary>
	/// <returns>A reference of the player's fighter variable</returns>
	Fighter& GetPlayerFighter();



	/// <summary>
	/// Method to save the enemy fighter by indicating the id in the fighters vector
	/// If the id isn't correct, then the first fighter is chosen by default to prevent from errors.
	/// </summary>
	/// <param name="fighterId">The id of the fighter the player will fight against</param>
	void SetEnemyFighter(int fighterId);
	/// <summary>
	/// Get the enemy's fighter variable
	/// </summary>
	/// <returns>A reference of the enemy's fighter variable</returns>
	Fighter& GetEnemyFighter();



	// Destructor
	~DataManager();
	DataManager(DataManager const&)		= delete;
	void operator=(DataManager const&)	= delete;



	/// <summary>
	/// Method that populate ALL the data, by reading all the json files. All data are needed, otherwise the game crashes.
	/// </summary>
	void PopulateData();



	std::vector<Fighter> GetFighters();		// Get the list of all the loaded fighters.
	std::vector<Weapon> GetWeapons();		// Get the list of all the loaded weapons.
	std::vector<Armor> GetArmors();			// Get the list of all the loaded armors.
	std::vector<Skill> GetSkills();			// Get the list of all the loaded skills.



	/// <summary>
	/// Add a log line in the fight logs vector
	/// </summary>
	/// <param name="log">The log line to add in the vector</param>
	void AddLog(std::string log);

	/// <summary>
	/// Get the nbLogs last logs from the logs vector. If the requested number of logs exceeds the total number of logs, 
	/// then just the available logs are sent.
	/// </summary>
	/// <param name="nbLogs">The number of logs requested</param>
	/// <returns>All the requested logs</returns>
	std::vector<std::string> GetLastLogs(int nbLogs);

	/// <summary>
	/// Clear all the fight logs
	/// </summary>
	void ClearLog();
};

