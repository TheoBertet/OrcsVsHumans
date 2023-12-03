// EnemyTurnState.cpp
// Author : Théo Bertet
// Description : This file contains all the data structures for the Enemy Turn state, that is also a State Machine's state.
#include <conio.h>
#include "EnemyTurnState.h"
#include "Fighter.h"
#include "DataManager.h"
#include "KeyboardInputs.h"
#include "UIManager.h"

/// <summary>
/// Process the cooldowns of all the active skills, by decreasing the cooldowns and durations
/// </summary>
void EnemyTurnState::ProcessCooldowns()
{
	Fighter& enemyFighter = DataManager::GetInstance().GetEnemyFighter();

	enemyFighter.ProcessCooldown();
}

/// <summary>
/// Process the enemy's behaviour
/// If the enemy has available skills, he will use them if they are needed.
/// For example, if the enemy has a healing skill but he doesn't need it, he won't use it
/// Afterwards, the enemy attacks the player
/// </summary>
void EnemyTurnState::ProcessBehaviour()
{
	// GET IMPORTANT DATA
	Fighter& playerFighter = DataManager::GetInstance().GetPlayerFighter();
	Fighter& enemyFighter = DataManager::GetInstance().GetEnemyFighter();
	int c = 0;
	std::string enemyAction = "";

	// Skip turn if enemy is stunt
	if (enemyFighter.IsStunt())
	{
		DataManager::GetInstance().AddLog("ENEMY is stunt for this turn...");
		return;
	}

	// ENEMY BEHAVIOUR
	// STEP #1 : Use skills if available
	int skillId = 0;
	for (Skill & skill : enemyFighter.GetSkills())
	{
		if (skill.GetCoolDownRemaining() == 0)
		{
			// If the skill is a heal, then only cast it if the heal is useful
			// Logic is : If the skill heals and that the heals is greater than the missing hp, then don't use it
			if (skill.GetHeal() > 0 && skill.GetHeal() > enemyFighter.GetHealthPoints() - enemyFighter.GetCurrentHP())
			{
				continue;
			}

			// If the skill is a life drain, then only cast it if the drain is useful
			// Logic is : If the skill drains life and that the drain is greater than the missing hp, then don't use it
			if (skill.GetDrainDamage() > 0 && (skill.GetDrainDamage() * enemyFighter.GetDamages()) > enemyFighter.GetHealthPoints() - enemyFighter.GetCurrentHP())
			{
				continue;
			}

			bool castSuccess = enemyFighter.CastSkill(skillId, playerFighter);

			std::string logLine = enemyFighter.GetName() + " enemy casted " + skill.GetName();

			if (castSuccess)
				logLine += ", and it's a SUCCESS!";
			else
				logLine += ", and it's a fail...";

			DataManager::GetInstance().AddLog(logLine);
		}

		skillId++;
	}

	// STEP #2 : Attack the enemy
	playerFighter.Damages(enemyFighter.GetDamages());
	DataManager::GetInstance().AddLog(enemyFighter.GetName() + " enemy inflicted " + std::to_string(enemyFighter.GetDamages()) + " to PLAYER.");
	enemyAction = enemyFighter.GetName() + " attacks you !";

	// Drain life part
	int drainDmg = enemyFighter.GetAllDrainDamages();
	if (drainDmg > 0)
	{
		enemyFighter.Heal(drainDmg);
		DataManager::GetInstance().AddLog(enemyFighter.GetName() + " enemy drained " + std::to_string(drainDmg) + " hp from PLAYER.");
	}

	// DISPLAY ENEMY ACTION TO PLAYER
	while (c != KEY_ENTER)
	{
		UIManager::ClearScreen();
		UIManager::DisplayHeader();
		UIManager::DisplayFightLogs(DataManager::GetInstance().GetLastLogs(5));
		UIManager::DisplayFighters(playerFighter, enemyFighter);
		UIManager::DisplayEnemyAction(enemyAction);

		c = _getch();
	}
}

/// <summary>
/// Go to next state. If the player died, the next state is the End Fight screen. If the player is still alive, the next state is 
/// the Player's turn.
/// </summary>
/// <param name="stateMachine">The parent state machine given in StartState</param>
void EnemyTurnState::EndTurn(StateMachine* stateMachine)
{
	if (DataManager::GetInstance().GetPlayerFighter().isAlive() & DataManager::GetInstance().GetEnemyFighter().isAlive())
	{
		((FightBehaviour*)stateMachine)->PlayerTurn();
	}
	else
	{
		DataManager::GetInstance().AddLog(DataManager::GetInstance().GetEnemyFighter().GetName() + " killed PLAYER!");
		((FightBehaviour*)stateMachine)->EndFight();
	}
}



/// <summary>
/// Enemy Turn state is composed by the processing of cooldowns and durations, and by the behaviour of the enemy.
/// The behaviour of the enemy is described in ProcessBehaviour() method.
/// </summary>
/// <param name="stateMachine">The master state machine</param>
void EnemyTurnState::StartState(StateMachine* stateMachine)
{
	MState::StartState(stateMachine);
	ProcessCooldowns();
	ProcessBehaviour();
	EndTurn(stateMachine);
}
