// EntryGameState.cpp
// Author : Théo Bertet
// Description : This file contains all the methods for the main menu state, that is also a State Machine's state.
#include <conio.h>
#include "EntryGameState.h"
#include "UIManager.h"
#include "KeyboardInputs.h"

/// <summary>
/// The Main menu is composed of some options. Depending on the options chosen, the current state can be changed or the app is quit.
/// Contains a main while loop detecting the keyboard input, used to know which option is selected and chosen.
/// </summary>
/// <param name="stateMachine">The master state machine</param>
void EntryGameState::StartState(StateMachine* stateMachine)
{
	MState::StartState(stateMachine);


	int c = 0;
	int select = 0;
	while (c != KEY_ENTER)
	{
		UIManager::ClearScreen();
		UIManager::DisplayHeader();
		UIManager::DisplayEntryGameSubtitle();
		UIManager::DisplayEntryGameChoice(select);

		switch ((c = _getch())) {
		case KEY_UP:
			if (select == 0)
				select = UIManager::ENTRY_ACTIONS_COUNT - 1;
			else
				select = (select - 1) % UIManager::ENTRY_ACTIONS_COUNT;
			break;
		case KEY_DOWN:
			select = (select + 1) % UIManager::ENTRY_ACTIONS_COUNT;
			break;
		case KEY_ENTER:
			switch (select)
			{
			case UIManager::START:
				((AppBehaviour*)stateMachine)->SelectFighter();
				break;
			case UIManager::HOW_TO_PLAY:
				((AppBehaviour*)stateMachine)->SeeRules();
				break;
			case UIManager::QUIT:
				return;
				break;
			}
			break;
		default:
			break;
		}
	}
}