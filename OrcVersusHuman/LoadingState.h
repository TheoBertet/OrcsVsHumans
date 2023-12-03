// LoadingState.h
// Author : Théo Bertet
// Description : This file contains all the data structures for the Loading Data state, that is also a State Machine's state.
#pragma once
#include "StateMachine.h"
#include "AppBehaviour.h"

/// <summary>
/// The loading state concerns the populating of all the game data.
/// THIS STEP IS MANDATORY.
/// </summary>
/// <param name="stateMachine">The master state machine</param>
class LoadingState : public MState
{
public:
	// Constructor
	LoadingState() {  };
	// Destructor
	~LoadingState() {  };

	/// <summary>
	/// The loading state concerns the populating of all the game data.
	/// THIS STEP IS MANDATORY.
	/// </summary>
	/// <param name="stateMachine">The master state machine</param>
	void StartState(StateMachine* stateMachine) override;
	void EndState() override { MState::EndState(); };
};

