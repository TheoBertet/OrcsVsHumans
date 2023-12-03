// Skill.h
// Author : Théo Bertet
// Description : This file contains all the data structure for skills.
#include<iostream>

#pragma once
class Skill
{
protected:
	std::string name;				// Name of the skill
	std::string description;		// Description of the skill
	float damagesMultiplicator;		// The damages multiplicator applied on the caster for the given duration
	bool stunEnemy;					// Indicate if the skill stun or not the target
	int duration;					// The duration of the skill effect, in number of turns
	int durationRemaining;			// The remaining duration of the skill
	float successRate;				// The success rate of the skill when it's cast
	int heal;						// The amount of hp the skill heals
	int cooldown;					// The duration between two possible casts, in number of turns
	int cdRemaining;				// The remaining cooldown remaining ; if cdRemaining is 0, then the skill isn't effective
	bool failed;					// If the skill is effective, indicate if the skill has failed or not
	float drainDmg;					// If the skill drain damage, this indicates the percentage of damage drained

public:
	// Default Constructor
	Skill();
	// Copy Constructor
	Skill(const Skill& copySkill);
	// Comfort Constructor
	Skill(std::string _name, std::string _desc, float _dmgMulti, bool _stunEnemy, int _duration, float _successRate, int _cooldown, int _heal, float _drain);
	// Destructor
	~Skill();

	// Method to clone an armor, same as a copy constructor
	Skill* Clone();



	/// <summary>
	/// Method that indicates the skill duration that remains before stopping to be effective
	/// </summary>
	/// <returns>Number of turns before the effect stops</returns>
	int GetDurationRemaining();

	/// <summary>
	/// Method to decrease the remaining duration, used at the end of the turn
	/// </summary>
	void DecreaseDuration();



	/// <summary>
	/// Method to get the remaining cooldown (the number of turns before this skill can be used again)
	/// </summary>
	/// <returns>Number of turns before this skill can be used again</returns>
	int GetCoolDownRemaining();

	/// <summary>
	/// Method that decrease the remaining cooldown
	/// </summary>
	void DecreaseCooldown();

	/// <summary>
	/// Method that indicates if the skill has been failed or not
	/// </summary>
	/// <returns>TRUE if it's a fail, FALSE if it's a success</returns>
	bool IsFailed();



	/// <summary>
	/// Cast the skill.
	/// Roll the success rate and return if it's a fail or not.
	/// </summary>
	/// <returns>TRUE if the cast is successful, ELSE if it's a fail</returns>
	bool Cast();

	std::string GetName();			// Get the skill's name
	std::string GetDescription();	// Get the skill's description
	float GetDamageMulti();			// Get the skill's damage multiplicator
	bool GetStunEnemy();			// Indicates if the skill stun or not the target
	int GetDuration();				// Get the duration of the skill
	float GetSuccessRate();			// Get the success rate of the skill
	int GetCooldown();				// Get the max cooldown of the skill
	int GetHeal();					// Get the heal amount of the skill
	float GetDrainDamage();			// Get the percentage of drain damage of the skill
};

