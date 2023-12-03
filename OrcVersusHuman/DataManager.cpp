// DataManager.cpp
// Author : Théo Bertet
// Description : This file contains all the methods for the data manager, including all the data accesses and data populating
// DATAMANAGER IS A SINGLETON.
#include "DataManager.h"

/// <summary>
/// This method reads the fighters.json file and parse it in Fighter objects, and then push them in the Fighters vector
/// </summary>
void DataManager::PopulateFighters()
{
    std::ifstream i("fighters.json");
    json j;

    try
    {
        i >> j;

        for (auto& el : j)
        {
            Fighter f(el["name"], el["healthPoints"], el["defaultDamages"]);
            
            if (!el["weapon"].empty())
            {
                bool weaponAdded = false;
                for (Weapon w : weapons)
                {
                    if (w.GetName() == el["weapon"])
                    {
                        f.AddWeapon(w);
                        weaponAdded = true;
                    }
                }

                if (!weaponAdded)
                {
                    std::cout << "[ERR] The weapon \"" << el["weapon"] << "\" of fighter \"" << el["name"] << "\" hasn't be find. Make sure the names match, and that the weapon is present in the weapons data file." << std::endl;
                    throw std::exception();
                }
            }

            if (!el["armor"].empty())
            {
                bool armorAdded = false;
                for (Armor a : armors)
                {
                    if (a.GetName() == el["armor"])
                    {
                        f.AddArmor(a);
                        armorAdded = true;
                    }
                }

                if (!armorAdded)
                {
                    std::cout << "[ERR] The armor \"" << el["armor"] << "\" of fighter \"" << el["name"] << "\" hasn't be find. Make sure the names match, and that the armor is present in the armors data file." << std::endl;
                    throw std::exception();
                }
            }

            if (!el["skills"].empty())
            {
                for (auto& fighterSkill : el["skills"])
                {
                    bool skillAdded = false;
                    for (Skill s : skills)
                    {
                        if (fighterSkill == s.GetName())
                        {
                            f.AddSkill(s);
                            skillAdded = true;
                        }
                    }

                    if (!skillAdded)
                    {
                        std::cout << "[ERR] The skill \"" << fighterSkill << "\" of fighter \"" << el["name"] << "\" hasn't be find. Make sure the names match, and that the skill is present in the skills data file." << std::endl;
                        throw std::exception();
                    }
                }
            }

            if (!el["skin"].empty())
            {
                bool skinAdded = false;
                for (Skin s : skins)
                {
                    if (s.GetName() == el["skin"])
                    {
                        f.AddSkin(s);
                        skinAdded = true;
                    }
                }

                if (!skinAdded)
                {
                    std::cout << "[ERR] The skin \"" << el["skin"] << "\" of fighter \"" << el["name"] << "\" hasn't be find. Make sure the names match, and that the skin is present in the drawings data file." << std::endl;
                    throw std::exception();
                }
            }
            
            fighters.push_back(f);
        }
    }
    catch (const std::exception e)
    {
        throw std::ifstream::failure("File containing all FIGHTERS data is missing or its format isn't right. Please check if it's still present and correct.");
    }
}

/// <summary>
/// This method reads the weapons.json file and parse it in Weapon objects, and then push them in the Weapons vector
/// </summary>
void DataManager::PopulateWeapons()
{
    std::ifstream i("weapons.json");
    json j;

    try
    {
        i >> j;

        for (auto& el : j)
        {
            Weapon w(el["name"], el["damages"]);
            weapons.push_back(w);
        }
    }
    catch (const std::exception e)
    {
        throw std::ifstream::failure("File containing all WEAPONS data is missing or its format isn't right. Please check if it's still present and correct.");
    }
}

/// <summary>
/// This method reads the armors.json file and parse it in Armor objects, and then push them in the Armors vector
/// </summary>
void DataManager::PopulateArmors()
{
    std::ifstream i("armors.json");
    json j;

    try
    {
        i >> j;

        for (auto& el : j)
        {
            Armor a(el["name"], el["armorPoints"]);
            armors.push_back(a);
        }
    }
    catch (const std::exception e)
    {
        throw std::ifstream::failure("File containing all ARMORS data is missing or its format isn't right. Please check if it's still present and correct.");
    }
}

/// <summary>
/// This method reads the skills.json file and parse it in Skill objects, and then push them in the Skills vector
/// </summary>
void DataManager::PopulateSkills()
{
    std::ifstream i("skills.json");
    json j;

    try
    {
        i >> j;

        for (auto& el : j)
        {
            Skill s(el["name"], el["description"], el["damagesMultiplicator"], el["stunEnemy"], el["duration"], el["successRate"], el["cooldown"], el["heal"], el["drainDmg"]);
            skills.push_back(s);
        }
    }
    catch (const std::exception e)
    {
        throw std::ifstream::failure("File containing all SKILLS data is missing or its format isn't right. Please check if it's still present and correct.");
    }
}

/// <summary>
/// This method reads the drawings.json file and parse it in Skin objects, and then push them in the Skins vector
/// </summary>
void DataManager::PopulateSkins()
{
    std::ifstream i("drawings.json");
    json j;

    try
    {
        i >> j;

        for (auto& el : j)
        {
            std::vector<std::string> lines = std::vector<std::string>();
            
            for (int numLine = 1; numLine <= 8; numLine++)
            {
                std::string jsonField = "line_" + std::to_string(numLine);
                lines.push_back(el[jsonField]);
            }

            Skin s(el["name"], lines);
            skins.push_back(s);
        }
    }
    catch (const std::exception e)
    {
        throw std::ifstream::failure("File containing all SKINS data is missing or its format isn't right. Please check if it's still present and correct.");
    }
}



// Constructor
DataManager::DataManager()
{
    fighters = std::vector<Fighter>();
    weapons = std::vector<Weapon>();
    armors = std::vector<Armor>();
    skills = std::vector<Skill>();
    skins = std::vector<Skin>();

    fightLogs = std::vector<std::string>();

    chosenFighter = Fighter();
    enemy = Fighter();
}



/// <summary>
/// Method to save the player fighter by indicating the id in the fighters vector
/// If the id isn't correct, then the first fighter is chosen by default to prevent from errors.
/// </summary>
/// <param name="fighterId">The id of the fighter the player chose</param>
void DataManager::SetPlayerFighter(int fighterId)
{
    if (fighterId < fighters.size() && fighterId > 0)
    {
        chosenFighter = fighters[fighterId];
    }
    else
    {
        chosenFighter = fighters[0];
    }
}

/// <summary>
/// Get the player's fighter variable
/// </summary>
/// <returns>A reference of the player's fighter variable</returns>
Fighter& DataManager::GetPlayerFighter()
{
    return chosenFighter;
}



/// <summary>
/// Method to save the enemy fighter by indicating the id in the fighters vector
/// If the id isn't correct, then the first fighter is chosen by default to prevent from errors.
/// </summary>
/// <param name="fighterId">The id of the fighter the player will fight against</param>
void DataManager::SetEnemyFighter(int fighterId)
{
    if (fighterId < fighters.size() && fighterId > 0)
    {
        enemy = fighters[fighterId];
    }
    else
    {
        enemy = fighters[0];
    }
}

/// <summary>
/// Get the enemy's fighter variable
/// </summary>
/// <returns>A reference of the enemy's fighter variable</returns>
Fighter& DataManager::GetEnemyFighter()
{
    return enemy;
}



// Destructor
DataManager::~DataManager()
{
    fighters.clear();
    weapons.clear();
    armors.clear();
    skills.clear();
    fightLogs.clear();
    skins.clear();
}



/// <summary>
/// Method that populate ALL the data, by reading all the json files. All data are needed, otherwise the game crashes.
/// </summary>
void DataManager::PopulateData()
{
    try
    {
        PopulateWeapons();
        PopulateArmors();
        PopulateSkills();
        PopulateSkins();
        PopulateFighters();
    }
    catch (const std::exception e)
    {
        throw e;
    }
}



// Get the list of all the loaded fighters.
std::vector<Fighter> DataManager::GetFighters()
{
    return fighters;
}

// Get the list of all the loaded weapons.
std::vector<Weapon> DataManager::GetWeapons()
{
    return weapons;
}

// Get the list of all the loaded armors.
std::vector<Armor> DataManager::GetArmors()
{
    return armors;
}

// Get the list of all the loaded skills.
std::vector<Skill> DataManager::GetSkills()
{
    return skills;
}



/// <summary>
/// Add a log line in the fight logs vector
/// </summary>
/// <param name="log">The log line to add in the vector</param>
void DataManager::AddLog(std::string log)
{
    fightLogs.push_back(log);
}

/// <summary>
/// Clear all the fight logs
/// </summary>
void DataManager::ClearLog()
{
    fightLogs.clear();
}

/// <summary>
/// Get the nbLogs last logs from the logs vector. If the requested number of logs exceeds the total number of logs, 
/// then just the available logs are sent.
/// </summary>
/// <param name="nbLogs">The number of logs requested</param>
/// <returns>All the requested logs</returns>
std::vector<std::string> DataManager::GetLastLogs(int nbLogs)
{
    // If there are less fight logs than requested, then return all the logs
    if (nbLogs > fightLogs.size() - 1 || fightLogs.size() <= 0)
        return fightLogs;

    // Else, just get the nbLogs last logs
    std::vector<std::string> lastLogs = std::vector<std::string>();

    for (int idLog = nbLogs; idLog > 0; idLog--)
    {
        lastLogs.push_back(fightLogs[fightLogs.size() - idLog]);
    }

    return lastLogs;
}
