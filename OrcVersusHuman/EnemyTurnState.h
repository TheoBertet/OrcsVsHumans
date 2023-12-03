// EnemyTurnState.h
// Author : Théo Bertet
// Description : This file contains all the data structures for the Enemy Turn state, that is also a State Machine's state.
#pragma once
#include "StateMachine.h"
#include "FightBehaviour.h"

class EnemyTurnState : public MState
{
private:
	/// <summary>
	/// Process the cooldowns of all the active skills, by decreasing the cooldowns and durations
	/// </summary>
	void ProcessCooldowns();

	/// <summary>
	/// Process the enemy's behaviour
	/// If the enemy has available skills, he will use them if they are needed.
	/// For example, if the enemy has a healing skill but he doesn't need it, he won't use it
	/// Afterwards, the enemy attacks the player
	/// </summary>
	void ProcessBehaviour();

	/// <summary>
	/// Go to next state. If the player died, the next state is the End Fight screen. If the player is still alive, the next state is 
	/// the Player's turn.
	/// </summary>
	/// <param name="stateMachine">The parent state machine given in StartState</param>
	void EndTurn(StateMachine* stateMachine);

public:
	EnemyTurnState() { };
	~EnemyTurnState() { };

	/// <summary>
	/// Enemy Turn state is composed by the processing of cooldowns and durations, and by the behaviour of the enemy.
	/// The behaviour of the enemy is described in ProcessBehaviour() method.
	/// </summary>
	/// <param name="stateMachine">The master state machine</param>
	void StartState(StateMachine* stateMachine) override;
	void EndState() override { MState::EndState(); };
};

