// FightBehaviour.h
// Author : Théo Bertet
// Description : This file contains all the data structures for the fight behaviour, that is also a State Machine.
#pragma once
#include <iostream>
#include "StateMachine.h"
#include "MState.h"

// These classes are pre defined because they are needed, but they will be really defined in their own files
class InitiativeState;
class PlayerTurnState;
class EnemyTurnState;
class EndFightState;

class FightBehaviour : public StateMachine
{
private:
	// All the possible states for this state machine master
	InitiativeState * initiativeState;
	PlayerTurnState * playerTurnState;
	EnemyTurnState * enemyTurnState;
	EndFightState * endFightState;

protected:
	/// <summary>
	/// Override of the change state method because behaviour is specified. Here, there is UI methods added to base method
	/// </summary>
	/// <param name="newState">The new state to switch on</param>
	void ChangeState(MState& newState) override;

public:
	// Constructor
	FightBehaviour();
	// Destructor
	~FightBehaviour();



	/// <summary>
	/// Method that trigger the Roll Initiative State
	/// </summary>
	void RollInitiative();

	/// <summary>
	/// Method that trigger the Player Turn State
	/// </summary>
	void PlayerTurn();

	/// <summary>
	/// Method that trigger the Enemy Turn State
	/// </summary>
	void EnemyTurn();

	/// <summary>
	/// Method that trigger the Fight Ending State
	/// </summary>
	void EndFight();
};

