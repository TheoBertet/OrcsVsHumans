// HowToPlayState.h
// Author : Théo Bertet
// Description : This file contains all the data structures for the How To Play state, that is also a State Machine's state.
#pragma once
#include "StateMachine.h"
#include "AppBehaviour.h"

class HowToPlayState : public MState
{
private:

public:
	// Constructor
	HowToPlayState() {  };
	// Destructor
	~HowToPlayState() {  };

	/// <summary>
	/// Display the page with all the How To Play informations.
	/// Quit the page when user press Enter.
	/// </summary>
	/// <param name="stateMachine">The master state machine</param>
	void StartState(StateMachine* stateMachine) override;
	void EndState() override { MState::EndState(); };
};

