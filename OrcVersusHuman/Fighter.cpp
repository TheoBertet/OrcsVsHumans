// Fighter.cpp
// Author : Théo Bertet
// Description : This file contains all the methods concerning fighters.
#include "Fighter.h"

// Default Constructor
Fighter::Fighter()
{
	name = "N/A";
	healthPoints = 0;
	currentHp = healthPoints;
}

// Copy Constructor
Fighter::Fighter(const Fighter& copyFighter) : Fighter(copyFighter.name, copyFighter.healthPoints, copyFighter.defaultDamages, copyFighter.weapon, copyFighter.armor, copyFighter.skills, copyFighter.skin)
{
}

// Comfort Constructor #1
Fighter::Fighter(std::string _name, int _hp, int _defaultDamages)
{
	name = _name;
	healthPoints = _hp;
	currentHp = healthPoints;
	defaultDamages = _defaultDamages;
}

// Comfort Constructor #2
Fighter::Fighter(std::string _name, int _hp, int _defaultDamages, Weapon _weapon, Armor armor, std::vector<Skill> _skills, Skin _skin)
{
	name = _name;
	healthPoints = _hp;
	currentHp = healthPoints;
	defaultDamages = _defaultDamages;
	AddWeapon(_weapon);
	AddArmor(armor);
	skills = _skills;
	skin = _skin;
	stunt = false;
}

// Destructor
Fighter::~Fighter()
{
	name = "Deleted";
	healthPoints = 0;
	currentHp = 0;
	defaultDamages = 0;
	RemoveWeapon();
	ClearSkills();
}

// Method to clone an armor, same as a copy constructor
Fighter* Fighter::Clone()
{
	return new Fighter(*this);
}

/// <summary>
/// Method that add or replace the weapon of the fighter
/// </summary>
/// <param name="_weapon">The new weapon</param>
void Fighter::AddWeapon(Weapon _weapon)
{
	weapon = _weapon;
}

/// <summary>
/// Method that remove the weapon of the fighter
/// </summary>
void Fighter::RemoveWeapon()
{
	weapon = Weapon();
}



/// <summary>
/// Method that add or replace the armor of the fighter
/// </summary>
/// <param name="_armor">The new armor</param>
void Fighter::AddArmor(Armor _armor)
{
	armor = _armor;
}

/// <summary>
/// Method that remove the armor of the fighter
/// </summary>
void Fighter::RemoveArmor()
{
	armor = Armor();
}



/// <summary>
/// Method that add a skill to the figher's skills list
/// </summary>
/// <param name="_skill">The skill to add into the skills list</param>
void Fighter::AddSkill(Skill _skill)
{
	skills.push_back(_skill);
}

/// <summary>
/// Method that clear the whole skills list
/// </summary>
void Fighter::ClearSkills()
{
	skills.clear();
}

/// <summary>
/// Method that process all the effects of a skill the fighter has
/// </summary>
/// <param name="skillId">The index of the skill to cast</param>
/// <param name="target">The fighter's target ; useful when skill affect directly the target, as stun effect</param>
/// <returns>TRUE if the cast is successful, FALSE if it's a fail</returns>
bool Fighter::CastSkill(int skillId, Fighter& target)
{
	if (skillId < skills.size())
	{
		bool success = skills[skillId].Cast();
		if (success)
		{
			if (skills[skillId].GetStunEnemy())
			{
				target.Stun(skills[skillId].GetDuration());
			}
			if (skills[skillId].GetHeal() > 0)
			{
				Heal(skills[skillId].GetHeal());
			}
		}
		return success;
	}
	else
	{
		throw new std::exception("In Fighter::CastSkill, the skillId is out of bounds.");
	}

	return false;
}



/// <summary>
/// Method that add a skin to the fighter. The skin is used in the fight part
/// </summary>
/// <param name="_skin">The skin to add</param>
void Fighter::AddSkin(Skin _skin)
{
	skin = _skin;
}

/// <summary>
/// Method to remove the fighter's skin
/// </summary>
void Fighter::RemoveSkin()
{
	skin = Skin();
}

/// <summary>
/// Inflicts the damages to the fighter, considering his armor if he has one.
/// Logic is :	If armor is broken, then the fighter takes all damages.
///				If armor isn't broken, but damages exceed the remaining armor points, then armor take what it can and fighter the rest
///				If armor isn't broken and the damages don't exceed the remaining armor points, then armor take all damages
/// </summary>
/// <param name="damages">Amout of damages to deal with</param>
void Fighter::Damages(int damages)
{
	if (armor.GetName() == "N/A" || armor.IsBroken())
	{
		currentHp -= damages;
	}
	else
	{
		if (armor.GetCurrentArmorPoints() >= damages)
		{
			armor.Damages(damages);
		}
		else
		{
			currentHp -= damages - armor.GetCurrentArmorPoints();
			armor.Damages(armor.GetCurrentArmorPoints());
		}
	}

}

/// <summary>
/// Heal the fighter. The heal cannot give more hp than the fighter maximum hp. (healthpoints)
/// </summary>
/// <param name="heal">Amount of hp to heal</param>
void Fighter::Heal(int heal)
{
	currentHp = std::min(healthPoints, currentHp+heal);
}

/// <summary>
/// Indicate if the fighter is dead or not. A fighter is considered dead if his hp are below or equal to 0.
/// </summary>
/// <returns>TRUE if he's alive, FALSE if he's dead</returns>
bool Fighter::isAlive()
{
	if (currentHp <= 0)
		return false;
	else
		return true;
}



/// <summary>
/// Method to get all the drain damage. Some skills can drain part of the damages dealt to the target.
/// </summary>
/// <returns>The amount of damage that are drained</returns>
int Fighter::GetAllDrainDamages()
{
	int allDrainDmg = 0;

	for (Skill& skill : skills)
	{
		if (skill.GetDurationRemaining() > 0 && skill.GetDrainDamage() > 0)
		{
			allDrainDmg += (GetDamages() * skill.GetDrainDamage());
		}
	}

	return allDrainDmg;
}



/// <summary>
/// Method that indicates if the fighter is stunt or not
/// </summary>
/// <returns>TRUE if the fighter is stunt, FALSE if he's not</returns>
bool Fighter::IsStunt()
{
	return stunt;
}

/// <summary>
/// Method to stun the figther for a given duration
/// </summary>
/// <param name="duration">The number of turns the fighter must be stunt</param>
void Fighter::Stun(int duration)
{
	stunt = true;
	passiveEffects[STUNT] = duration + 1;
	// Add a turn to the duration, as the stun effect is applied before the fighter turn (and effects cooldown is processed at the
	// beginning of a turn)
}



/// <summary>
/// Process all the skills and effects cooldowns of the fighter, and return the skills that are now ready, for the logs
/// </summary>
/// <returns>The list of the skills that are now ready</returns>
std::vector<Skill> Fighter::ProcessCooldown()
{
	std::vector<Skill> skillsReady = std::vector<Skill>();

	// Process skills cooldowns
	for (Skill & skill : skills)
	{
		if (skill.GetCoolDownRemaining() > 0)
		{
			skill.DecreaseCooldown();
			skill.DecreaseDuration();

			// Useful for the logs
			if (skill.GetCoolDownRemaining() == 0)
			{
				skillsReady.push_back(skill);
			}
		}
	}

	// Process passive effects cooldowns
	for (auto& effect : passiveEffects)
	{
		effect.second = std::max(0, effect.second - 1);
		if (effect.second == 0)
		{
			switch (effect.first)
			{
			case STUNT:
				stunt = false;
				break;
			}
		}
	}

	return skillsReady;
}



/// <summary>
/// Process all secondary effects, like poison damages - NOT IMPLEMENTED
/// </summary>
void Fighter::ProcessEffects()
{
	// NOT IMPLEMENTED
}



/// <summary>
/// Calculate the damages for the current round, considering the active skills
/// </summary>
/// <returns>The amount of damages</returns>
int Fighter::GetDamages()
{
	int damages = 0;

	if (weapon.GetName() != "N/A")
	{
		damages = weapon.GetDamages();

		// Calculation of the damages bonus due to active skills
		for (Skill& skill : skills)
		{
			if (skill.GetDurationRemaining() > 0)
			{
				damages *= skill.GetDamageMulti();
			}
		}
	}
	else
	{
		damages = defaultDamages;
	}

	return damages;
}



// Get the fighter's name
std::string Fighter::GetName()
{
	return name;
}

// Get the fighter's max health points
int Fighter::GetHealthPoints()
{
	return healthPoints;
}

// Get the fighter's current health points
int Fighter::GetCurrentHP()
{
	return currentHp;
}

// Get the fighter's default damages
int Fighter::GetDefaultDamages()
{
	return defaultDamages;
}

// Get the fighter's weapon
Weapon& Fighter::GetWeapon()
{
	return weapon;
}

// Get the fighter's armor
Armor& Fighter::GetArmor()
{
	return armor;
}

// Get the fighter's skin
Skin Fighter::GetSkin()
{
	return skin;
}

// Get the list of the figther's skills
std::vector<Skill>& Fighter::GetSkills()
{
	return skills;
}
