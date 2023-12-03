// EndFightState.h
// Author : Théo Bertet
// Description : This file contains all the data structures for the End Fight state, that is also a State Machine's state.
#pragma once
#include "StateMachine.h"
#include "FightBehaviour.h"

class EndFightState : public MState
{
private:
	/// <summary>
	/// Display the end fight text. The text is different if the player wins, or if he loses.
	/// </summary>
	void DisplayEndingText();

public:
	EndFightState() { };
	~EndFightState() { };

	/// <summary>
	/// End Fight state display a text depending on the win or the lose of the player
	/// </summary>
	void StartState(StateMachine* stateMachine) override;
	void EndState() override { MState::EndState(); };
};

