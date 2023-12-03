// FightState.cpp
// Author : Théo Bertet
// Description : This file contains all the methods for the Fight state, that is also a State Machine's state.
#include "FightState.h"
#include "AppBehaviour.h"
#include "FightBehaviour.h"
#include "DataManager.h"

/// <summary>
/// The fight state is just another state machine's parent.
/// When the child state machine is ended (= the fight is ended), we go back to the main menu.
/// </summary>
/// <param name="stateMachine">The master state machine</param>
void FightState::StartState(StateMachine* stateMachine)
{
	FightBehaviour fightBehaviour = FightBehaviour();
	fightBehaviour.RollInitiative();

	DataManager::GetInstance().ClearLog();
	((AppBehaviour*)stateMachine)->EntryGame();
}
