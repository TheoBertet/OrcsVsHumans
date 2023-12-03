// LoadingState.cpp
// Author : Théo Bertet
// Description : This file contains all the methods for the Loading Data state, that is also a State Machine's state.
#include "LoadingState.h"
#include "DataManager.h"
#include "AppBehaviour.h"

/// <summary>
/// The loading state concerns the populating of all the game data.
/// THIS STEP IS MANDATORY.
/// </summary>
/// <param name="stateMachine">The master state machine</param>
void LoadingState::StartState(StateMachine* stateMachine)
{
	MState::StartState(stateMachine);

	try
	{
		DataManager::GetInstance().PopulateData();
		((AppBehaviour*)stateMachine)->EntryGame();
	}
	catch (const std::exception e)
	{
		throw e;
	}

}
