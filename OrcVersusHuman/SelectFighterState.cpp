// SelectFighterState.cpp
// Author : Théo Bertet
// Description : This file contains all the methods for the Select Fighter state, that is also a State Machine's state.
#include <conio.h>
#include <cstdlib>
#include "SelectFighterState.h"
#include "KeyboardInputs.h"
#include "DataManager.h"
#include "UIManager.h"
#include "Tools.h"

/// <summary>
/// Method that chose an enemy in the list of enemies
/// If the player chose the Knight, then the enemy will be the Orc.
/// If the player chose the Orc, then the enemy will be the Knight.
/// In all other cases, enemy will be randomly chose.
/// </summary>
/// <param name="playerId">The character the player chose</param>
void SelectFighterState::SelectEnemy(int playerId)
{
	int enemyId = 0;

	if (playerId == 0)
	{
		enemyId = 1;
	}
	else if (playerId == 1)
	{
		enemyId = 0;
	}
	else
	{
		enemyId = Tools::Random(0, DataManager::GetInstance().GetFighters().size() - 1);
	}

	DataManager::GetInstance().SetEnemyFighter(enemyId);
}

/// <summary>
/// The select fighter state is the moment where the player chose his fighter.
/// The main while loop is needed to display all the fighters, the currently selected fighter, and the indications for the player.
/// When the player chose his fighter, the opponent is also chosen automaticaly, and the fight can start.
/// </summary>
/// <param name="stateMachine">The master state machine</param>
void SelectFighterState::StartState(StateMachine* stateMachine)
{
	MState::StartState(stateMachine);

	int c = 0;
	int select = 0;

	while (c != KEY_ENTER)
	{
		UIManager::DisplayHeader();
		UIManager::DisplayFighterSelectTitle();
		UIManager::DisplayFighterChoice(DataManager::GetInstance().GetFighters(), select);

		switch ((c = _getch())) {
		case KEY_UP:
			if (select == 0)
				select = DataManager::GetInstance().GetFighters().size() - 1;
			else
				select = (select - 1) % DataManager::GetInstance().GetFighters().size();
			break;
		case KEY_DOWN:
			select = (select + 1) % DataManager::GetInstance().GetFighters().size();
			break;
		default:
			break;
		}

		UIManager::ClearScreen();
	}

	SelectEnemy(select);
	DataManager::GetInstance().SetPlayerFighter(select);
	((AppBehaviour*)stateMachine)->StartFight();
}
