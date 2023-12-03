// StateMachine.h
// Author : Théo Bertet
// Description : This file contains the base structure for a State Machine master.

#pragma once
#include "MState.h"

class StateMachine
{
private:

protected:
	MState * currentState;		// The current state machine's state
	
	/// <summary>
	/// Method that change the current state with a new one. Old state triggers the EndState method, and new state triggers the
	/// StartState method.
	/// </summary>
	/// <param name="newState">The new state to set</param>
	virtual void ChangeState(MState& newState);

public:
	// Constructor
	StateMachine() { currentState = new MState(); };
	// Destructor
	~StateMachine() { };
};