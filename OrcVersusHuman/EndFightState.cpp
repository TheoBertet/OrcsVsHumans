// EndFightState.cpp
// Author : Théo Bertet
// Description : This file contains all the methods for the End Fight state, that is also a State Machine's state.
#include <conio.h>
#include "EndFightState.h"
#include "KeyboardInputs.h"
#include "UIManager.h"
#include "DataManager.h"

/// <summary>
/// Display the end fight text. The text is different if the player wins, or if he loses.
/// </summary>
void EndFightState::DisplayEndingText()
{
	Fighter& playerFighter = DataManager::GetInstance().GetPlayerFighter();
	Fighter& enemyFighter = DataManager::GetInstance().GetEnemyFighter();
	int c = 0;

	// PREPARE LAST TEXT
	std::string lastText = "";
	if (playerFighter.isAlive())
	{
		lastText = "CONGRATULATIONS ! You killed " + enemyFighter.GetName() + " with heroism !";
	}
	else
	{
		lastText = "MAY THE GODS HAVE MERCY... You have been killed by " + enemyFighter.GetName() + ".";
	}

	// DISPLAY LAST TEXT TO PLAYER
	while (c != KEY_ENTER)
	{
		UIManager::ClearScreen();
		UIManager::DisplayHeader();
		UIManager::DisplayFightLogs(DataManager::GetInstance().GetLastLogs(5));
		UIManager::DisplayFighters(playerFighter, enemyFighter);
		UIManager::DisplayEnemyAction(lastText);

		c = _getch();
	}

	UIManager::ClearScreen();
}



/// <summary>
/// End Fight state display a text depending on the win or the lose of the player
/// </summary>
void EndFightState::StartState(StateMachine* stateMachine)
{
	MState::StartState(stateMachine);

	DisplayEndingText();
}
