// MState.h
// Author : Théo Bertet
// Description : This file contains the base structure for a State Machine's state.
#pragma once

class StateMachine;

class MState
{
public:
	// Constructor
	MState() {};
	// Destructor
	~MState() {};

	/// <summary>
	/// Method with all the process to execute when state starts
	/// </summary>
	/// <param name="stateMachine">The master state machine</param>
	virtual void StartState(StateMachine * stateMachine) {};

	/// <summary>
	/// Method will all the process to execute when state ends
	/// </summary>
	virtual void EndState() {};
};

