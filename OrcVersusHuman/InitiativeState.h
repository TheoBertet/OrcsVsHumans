// InitiativeState.h
// Author : Théo Bertet
// Description : This file contains all the data structures for the initiative roll state, that is also a State Machine's state.
#pragma once
#include "StateMachine.h"
#include "FightBehaviour.h"

class InitiativeState : public MState
{
public:
	InitiativeState() { };
	~InitiativeState() { };

	/// <summary>
	/// The initiative state define which fighter starts the fight.
	/// </summary>
	/// <param name="stateMachine">The master state machine</param>
	void StartState(StateMachine* stateMachine) override;
	void EndState() override { MState::EndState(); };
};

