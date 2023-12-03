// StateMachine.cpp
// Author : Théo Bertet
// Description : This file contains the base structure for a State Machine master.
#include "StateMachine.h"

/// <summary>
/// Method that change the current state with a new one. Old state triggers the EndState method, and new state triggers the
/// StartState method.
/// </summary>
/// <param name="newState">The new state to set</param>
void StateMachine::ChangeState(MState& newState)
{
	currentState->EndState();
	currentState = &newState;
	currentState->StartState(this);
}
