// FightState.h
// Author : Théo Bertet
// Description : This file contains all the data structures for the Fight state, that is also a State Machine's state.
#pragma once
#include "StateMachine.h"
#include "AppBehaviour.h"

class FightState : public MState
{
public:
	FightState() {  };
	~FightState() {  };

	/// <summary>
	/// The fight state is just another state machine's parent.
	/// When the child state machine is ended (= the fight is ended), we go back to the main menu.
	/// </summary>
	/// <param name="stateMachine">The master state machine</param>
	void StartState(StateMachine* stateMachine) override;
	void EndState() override { MState::EndState(); };
};

