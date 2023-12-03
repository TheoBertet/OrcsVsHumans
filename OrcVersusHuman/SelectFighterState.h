// SelectFighterState.h
// Author : Théo Bertet
// Description : This file contains all the data structures for the Select Fighter state, that is also a State Machine's state.
#pragma once
#include "StateMachine.h"
#include "AppBehaviour.h"

class SelectFighterState : public MState
{
private:
	/// <summary>
	/// Method that chose an enemy in the list of enemies
	/// If the player chose the Knight, then the enemy will be the Orc.
	/// If the player chose the Orc, then the enemy will be the Knight.
	/// In all other cases, enemy will be randomly chose.
	/// </summary>
	/// <param name="playerId">The character the player chose</param>
	void SelectEnemy(int playerId);

public:
	// Constructor
	SelectFighterState() {  };
	// Destructor
	~SelectFighterState() {  };

	/// <summary>
	/// The select fighter state is the moment where the player chose his fighter.
	/// The main while loop is needed to display all the fighters, the currently selected fighter, and the indications for the player.
	/// When the player chose his fighter, the opponent is also chosen automaticaly, and the fight can start.
	/// </summary>
	/// <param name="stateMachine">The master state machine</param>
	void StartState(StateMachine* stateMachine) override;
	void EndState() override { MState::EndState(); };
};