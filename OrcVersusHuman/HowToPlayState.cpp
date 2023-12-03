// HowToPlayState.cpp
// Author : Théo Bertet
// Description : This file contains all the methods for the How To Play state, that is also a State Machine's state.
#include <conio.h>
#include "HowToPlayState.h"
#include "KeyboardInputs.h"
#include "UIManager.h"

/// <summary>
/// Display the page with all the How To Play informations.
/// Quit the page when user press Enter.
/// </summary>
/// <param name="stateMachine">The master state machine</param>
void HowToPlayState::StartState(StateMachine* stateMachine)
{
	MState::StartState(stateMachine);

	int c = 0;
	while (c != KEY_ENTER)
	{
		UIManager::ClearScreen();
		UIManager::DisplayHeader();
		UIManager::DisplayHowToPlayPage();

		c = _getch();
	}

	((AppBehaviour*)stateMachine)->EntryGame();
}
