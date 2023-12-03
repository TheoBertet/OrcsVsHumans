// PlayerTurnState.cpp
// Author : Théo Bertet
// Description : This file contains all the methods for the Player Turn state, that is also a State Machine's state.
#include <conio.h>
#include "PlayerTurnState.h"
#include "UIManager.h"
#include "DataManager.h"
#include "KeyboardInputs.h"

/// <summary>
/// Loop between all the actions the player can choice.
/// The main while loop is waiting for a Enter key press to end, in a way to detect which option the player chose.
/// If the player's fighter is stunt, no action is possible and turn is skipped.
/// </summary>
void PlayerTurnState::ActionChoiceLoop()
{
	Fighter& playerFighter = DataManager::GetInstance().GetPlayerFighter();
	Fighter& enemyFighter = DataManager::GetInstance().GetEnemyFighter();

	// Skip turn if player is stunt
	if (playerFighter.IsStunt())
	{
		DataManager::GetInstance().AddLog("PLAYER is stunt for this turn...");
		return;
	}

	int c = 0;
	int select = 0;
	while (c != KEY_ENTER)
	{
		UIManager::ClearScreen();
		UIManager::DisplayHeader();
		UIManager::DisplayFightLogs(DataManager::GetInstance().GetLastLogs(5));
		UIManager::DisplayFighters(playerFighter, enemyFighter);
		UIManager::DisplayFightOptions(DataManager::GetInstance().GetPlayerFighter(), select);

		switch ((c = _getch())) {
		case KEY_UP:
			if (select == 0)
				select = UIManager::FIGHT_ACTIONS_COUNT - 1;
			else
				select = (select - 1) % UIManager::FIGHT_ACTIONS_COUNT;
			break;
		case KEY_DOWN:
			select = (select + 1) % UIManager::FIGHT_ACTIONS_COUNT;
			break;
		case KEY_ENTER:
			switch (select)
			{
			case UIManager::ATK:
			{
				enemyFighter.Damages(playerFighter.GetDamages());
				DataManager::GetInstance().AddLog("PLAYER inflicted " + std::to_string(playerFighter.GetDamages()) + " to " + enemyFighter.GetName() + " enemy.");

				int drainDmg = playerFighter.GetAllDrainDamages();
				if (drainDmg > 0)
				{
					playerFighter.Heal(drainDmg);
					DataManager::GetInstance().AddLog("PLAYER drained " + std::to_string(drainDmg) + " hp from enemy.");
				}

				break;
			}
			case UIManager::SKILL:
			{
				SkillChoiceLoop();
				c = 0;
				break;
			}
			}
			break;
		default:
			break;
		}
	}
}

/// <summary>
/// Loop between all the skills the player can choice.
/// The main while loop is waiting for a Enter key press to end, in a way to detect which skill the player chose.
/// There is an additionnal line because there is a "Back to actions" line, because player isn't forced to use a skill if he changed his mind.
/// </summary>
void PlayerTurnState::SkillChoiceLoop()
{
	Fighter & chosenFighter = DataManager::GetInstance().GetPlayerFighter();
	Fighter & enemyFighter = DataManager::GetInstance().GetEnemyFighter();
	int c = 0;
	int select = 0;

	while (c != KEY_ENTER)
	{
		// In case of a skill is under cooldown, and because we don't want to select a not ready skill,
		// we're browsing all skills until we find a ready one, or until we get the "Back to actions" line
		bool currentSelectCorrect = false;
		while (!currentSelectCorrect)
		{
			// In case of the select = the skills size, then we are on the "Back to actions" line
			if (select == chosenFighter.GetSkills().size())
			{
				currentSelectCorrect = true;
				continue;
			}

			// Cannot select a skill that have a cooldown remaining
			if (chosenFighter.GetSkills()[select].GetCoolDownRemaining() > 0)
			{
				select++;
			}
			else
			{
				currentSelectCorrect = true;
			}
		}

		UIManager::ClearScreen();
		UIManager::DisplayHeader();
		UIManager::DisplayFightLogs(DataManager::GetInstance().GetLastLogs(5));
		UIManager::DisplayFighters(chosenFighter, enemyFighter);
		UIManager::DisplayFighterSkills(chosenFighter, select);

		switch ((c = _getch())) {
		case KEY_UP:
			if (select == 0)
				select = chosenFighter.GetSkills().size();	// Not -1 because there is one more row, because of the "Go back to actions"
			else
				select = (select - 1) % (chosenFighter.GetSkills().size() + 1); // +1 because the same reason
			break;
		case KEY_DOWN:
			select = (select + 1) % (chosenFighter.GetSkills().size() + 1);	// Same reason
			break;
		case KEY_ENTER:
			if (select < chosenFighter.GetSkills().size() && chosenFighter.GetSkills()[select].GetCoolDownRemaining() == 0)
			{
				bool castSuccess = chosenFighter.CastSkill(select, enemyFighter);

				std::string logLine = "PLAYER casted " + chosenFighter.GetSkills()[select].GetName();

				if (castSuccess)
				{
					logLine += ", and it's a SUCCESS!";
				}
				else
				{
					logLine += ", and it's a FAIL...";
				}

				DataManager::GetInstance().AddLog(logLine);
			}
			break;
		default:
			break;
		}
	}
}

/// <summary>
/// End the player turn by switching to the Enemy turn. If the enemy is dead, or if the player died, then the next turn is the end fight state.
/// </summary>
/// <param name="stateMachine">The master state machine</param>
void PlayerTurnState::GoToNextStep(StateMachine* stateMachine)
{
	if (DataManager::GetInstance().GetPlayerFighter().isAlive() & DataManager::GetInstance().GetEnemyFighter().isAlive())
	{
		((FightBehaviour*)stateMachine)->EnemyTurn();
	}
	else
	{
		DataManager::GetInstance().AddLog("PLAYER killed " + DataManager::GetInstance().GetEnemyFighter().GetName() + "!");
		((FightBehaviour*)stateMachine)->EndFight();
	}
}

/// <summary>
/// Processing the cooldowns by decreasing each skills cooldown and duration.
/// The process add a log if a skill is now ready.
/// </summary>
void PlayerTurnState::ProcessCooldowns()
{
	Fighter& chosenFighter = DataManager::GetInstance().GetPlayerFighter();

	std::vector<Skill> skillsReady = chosenFighter.ProcessCooldown();

	for (Skill & skill : skillsReady)
	{
		DataManager::GetInstance().AddLog("PLAYER's " + skill.GetName() + " skill is now ready!");
	}
}



/// <summary>
/// The player turn is composed by the skills cooldowns processing and the player's action. Actions can be attacking or using a skill.
/// </summary>
/// <param name="stateMachine">The master state machine</param>
void PlayerTurnState::StartState(StateMachine* stateMachine)
{
	MState::StartState(stateMachine);

	// STEP #1 : Process skills cooldowns and durations
	ProcessCooldowns();
	// STEP #2 : Waiting for player's action
	ActionChoiceLoop();

	GoToNextStep(stateMachine);
}
