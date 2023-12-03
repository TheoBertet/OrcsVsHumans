// Skill.cpp
// Author : Théo Bertet
// Description : This file contains all the methods for skills.
#include "Skill.h"
#include "Tools.h"

// Default Constructor
Skill::Skill() : Skill("N/A", "N/A", 0, false, 0, 0, 0, 0, 0)
{
}

// Copy Constructor
Skill::Skill(const Skill& copySkill) : Skill(copySkill.name, copySkill.description, copySkill.damagesMultiplicator,
	copySkill.stunEnemy, copySkill.duration, copySkill.successRate, copySkill.cooldown, copySkill.heal, copySkill.drainDmg)
{
}

// Comfort Constructor
Skill::Skill(std::string _name, std::string _desc, float _dmgMulti, bool _stunEnemy, int _duration, float _successRate, int _cooldown, int _heal, float _drain)
{
	name = _name;
	description = _desc;
	damagesMultiplicator = _dmgMulti;
	stunEnemy = _stunEnemy;
	duration = _duration;
	durationRemaining = 0;
	successRate = _successRate;
	cooldown = _cooldown;
	heal = _heal;
	drainDmg = _drain;
	cdRemaining = 0;
	failed = false;
}

// Destructor
Skill::~Skill()
{
	name = "Deleted";
	description = "Skill deleted";
	damagesMultiplicator = 0;
	stunEnemy = false;
	duration = 0;
	successRate = 0;
	cooldown = 0;
	cdRemaining = 0;
	failed = false;
	heal = 0;
	drainDmg = 0;
}

// Method to clone an armor, same as a copy constructor
Skill* Skill::Clone()
{
	return new Skill(*this);
}



/// <summary>
/// Method that indicates the skill duration that remains before stopping to be effective
/// </summary>
/// <returns>Number of turns before the effect stops</returns>
int Skill::GetDurationRemaining()
{
	return durationRemaining;
}

/// <summary>
/// Method to decrease the remaining duration, used at the end of the turn
/// </summary>
void Skill::DecreaseDuration()
{
	durationRemaining = std::max(0, durationRemaining - 1);
}



/// <summary>
/// Method to get the remaining cooldown (the number of turns before this skill can be used again)
/// </summary>
/// <returns>Number of turns before this skill can be used again</returns>
int Skill::GetCoolDownRemaining()
{
	return cdRemaining;
}

/// <summary>
/// Method that decrease the remaining cooldown
/// </summary>
void Skill::DecreaseCooldown()
{
	cdRemaining = std::max(0, cdRemaining-1);
}

/// <summary>
/// Method that indicates if the skill has been failed or not
/// </summary>
/// <returns>TRUE if it's a fail, FALSE if it's a success</returns>
bool Skill::IsFailed()
{
	return failed;
}



/// <summary>
/// Cast the skill.
/// Roll the success rate and return if it's a fail or not.
/// </summary>
/// <returns>TRUE if the cast is successful, ELSE if it's a fail</returns>
bool Skill::Cast()
{
	float roll = (float)(Tools::Random(1, 100)) / 100;

	cdRemaining = cooldown;

	failed = (roll > successRate);

	if (failed)
		durationRemaining = 0;
	else
		durationRemaining = duration;

	return !failed;
}



// Get the skill's name
std::string Skill::GetName()
{
	return name;
}

// Get the skill's description
std::string Skill::GetDescription()
{
	return description;
}

// Get the skill's damage multiplicator
float Skill::GetDamageMulti()
{
	return damagesMultiplicator;
}

// Indicates if the skill stun or not the target
bool Skill::GetStunEnemy()
{
	return stunEnemy;
}

// Get the duration of the skill
int Skill::GetDuration()
{
	return duration;
}

// Get the success rate of the skill
float Skill::GetSuccessRate()
{
	return successRate;
}

// Get the max cooldown of the skill
int Skill::GetCooldown()
{
	return cooldown;
}

// Get the heal amount of the skill
int Skill::GetHeal()
{
	return heal;
}

// Get the percentage of drain damage of the skill
float Skill::GetDrainDamage()
{
	return drainDmg;
}