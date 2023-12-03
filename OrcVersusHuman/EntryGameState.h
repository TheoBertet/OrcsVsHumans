// EntryGameState.h
// Author : Théo Bertet
// Description : This file contains all the data structures for the main menu state, that is also a State Machine's state.
#pragma once
#include "StateMachine.h"
#include "AppBehaviour.h"

class EntryGameState :
	public MState
{
public:
	// Constructor
	EntryGameState() {  };
	// Destructor
	~EntryGameState() {  };

	/// <summary>
	/// The Main menu is composed of some options. Depending on the options chosen, the current state can be changed or the app is quit.
	/// Contains a main while loop detecting the keyboard input, used to know which option is selected and chosen.
	/// </summary>
	/// <param name="stateMachine">The master state machine</param>
	void StartState(StateMachine* stateMachine) override;
	void EndState() override { MState::EndState(); };
};

