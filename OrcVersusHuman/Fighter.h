// Fighter.h
// Author : Théo Bertet
// Description : This file contains all the data structure concerning fighters.
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Weapon.h"
#include "Skill.h"
#include "Armor.h"
#include "Skin.h"

#pragma once
class Fighter
{
protected:
	std::string name;				// Fighter's name
	int healthPoints;				// Fighter's max health points
	int currentHp;					// Fighter's current health points
	int defaultDamages;				// Fighter's default damages (when he has no weapon)
	Weapon weapon;					// Fighter's weapon
	Armor armor;					// Fighter's armor
	Skin skin;						// Fighter's skin
	std::vector<Skill> skills;		// List of all the Fighter's skills
	bool stunt;						// Indicates if the figher is stunt or not

	enum PassiveEffect { STUNT, POISONED };			// An enum for passive effects (Poisoned is not implemented now)
	std::map<PassiveEffect, int> passiveEffects { 	// Key is PassiveEffect identifier, Value is remainding duration
		{ STUNT, 0 },
		{ POISONED, 0}
	};

public:
	// Default Constructor
	Fighter();
	// Copy Constructor
	Fighter(const Fighter &copyFighter);
	// Comfort Constructor #1
	Fighter(std::string _name, int _hp, int _defaultDamages);
	// Comfort Constructor #2
	Fighter(std::string _name, int _hp, int _defaultDamages, Weapon _weapon, Armor armor, std::vector<Skill> _skills, Skin _skin);
	// Destructor
	~Fighter();

	// Method to clone an armor, same as a copy constructor
	Fighter* Clone();



	/// <summary>
	/// Method that add or replace the weapon of the fighter
	/// </summary>
	/// <param name="_weapon">The new weapon</param>
	void AddWeapon(Weapon _weapon);

	/// <summary>
	/// Method that remove the weapon of the fighter
	/// </summary>
	void RemoveWeapon();



	/// <summary>
	/// Method that add or replace the armor of the fighter
	/// </summary>
	/// <param name="_armor">The new armor</param>
	void AddArmor(Armor _armor);

	/// <summary>
	/// Method that remove the armor of the fighter
	/// </summary>
	void RemoveArmor();



	/// <summary>
	/// Method that add a skill to the figher's skills list
	/// </summary>
	/// <param name="_skill">The skill to add into the skills list</param>
	void AddSkill(Skill _skill);

	/// <summary>
	/// Method that clear the whole skills list
	/// </summary>
	void ClearSkills();

	/// <summary>
	/// Method that process all the effects of a skill the fighter has
	/// </summary>
	/// <param name="skillId">The index of the skill to cast</param>
	/// <param name="target">The fighter's target ; useful when skill affect directly the target, as stun effect</param>
	/// <returns>TRUE if the cast is successful, FALSE if it's a fail</returns>
	bool CastSkill(int skillId, Fighter& target);



	/// <summary>
	/// Method that add a skin to the fighter. The skin is used in the fight part
	/// </summary>
	/// <param name="_skin">The skin to add</param>
	void AddSkin(Skin _skin);

	/// <summary>
	/// Method to remove the fighter's skin
	/// </summary>
	void RemoveSkin();



	/// <summary>
	/// Inflicts the damages to the fighter, considering his armor if he has one.
	/// Logic is :	If armor is broken, then the fighter takes all damages.
	///				If armor isn't broken, but damages exceed the remaining armor points, then armor take what it can and fighter the rest
	///				If armor isn't broken and the damages don't exceed the remaining armor points, then armor take all damages
	/// </summary>
	/// <param name="damages">Amout of damages to deal with</param>
	void Damages(int damages);

	/// <summary>
	/// Heal the fighter. The heal cannot give more hp than the fighter maximum hp. (healthpoints)
	/// </summary>
	/// <param name="heal">Amount of hp to heal</param>
	void Heal(int heal);

	/// <summary>
	/// Indicate if the fighter is dead or not. A fighter is considered dead if his hp are below or equal to 0.
	/// </summary>
	/// <returns>TRUE if he's alive, FALSE if he's dead</returns>
	bool isAlive();



	/// <summary>
	/// Method to get all the drain damage. Some skills can drain part of the damages dealt to the target.
	/// </summary>
	/// <returns>The amount of damage that are drained</returns>
	int GetAllDrainDamages();



	/// <summary>
	/// Method that indicates if the fighter is stunt or not
	/// </summary>
	/// <returns>TRUE if the fighter is stunt, FALSE if he's not</returns>
	bool IsStunt();

	/// <summary>
	/// Method to stun the figther for a given duration
	/// </summary>
	/// <param name="duration">The number of turns the fighter must be stunt</param>
	void Stun(int duration);



	/// <summary>
	/// Process all the skills and effects cooldowns of the fighter, and return the skills that are now ready, for the logs
	/// </summary>
	/// <returns>The list of the skills that are now ready</returns>
	std::vector<Skill> ProcessCooldown();

	/// <summary>
	/// Process all secondary effects, like poison damages - NOT IMPLEMENTED
	/// </summary>
	void ProcessEffects();

	/// <summary>
	/// Calculate the damages for the current round, considering the active skills
	/// </summary>
	/// <returns>The amount of damages</returns>
	int GetDamages();



	std::string GetName();					// Get the fighter's name
	int GetHealthPoints();					// Get the fighter's max health points
	int GetCurrentHP();						// Get the fighter's current health points
	int GetDefaultDamages();				// Get the fighter's default damages
	Weapon& GetWeapon();					// Get the fighter's weapon
	Armor& GetArmor();						// Get the fighter's armor
	Skin GetSkin();							// Get the fighter's skin
	std::vector<Skill>& GetSkills();		// Get the list of the figther's skills
};

