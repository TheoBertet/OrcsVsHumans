// PlayerTurnState.h
// Author : Théo Bertet
// Description : This file contains all the data structures for the Player Turn state, that is also a State Machine's state.
#pragma once
#include "StateMachine.h"
#include "FightBehaviour.h"

class PlayerTurnState : public MState
{
private:
	/// <summary>
	/// Loop between all the actions the player can choice.
	/// The main while loop is waiting for a Enter key press to end, in a way to detect which option the player chose.
	/// If the player's fighter is stunt, no action is possible and turn is skipped.
	/// </summary>
	void ActionChoiceLoop();

	/// <summary>
	/// Loop between all the skills the player can choice.
	/// The main while loop is waiting for a Enter key press to end, in a way to detect which skill the player chose.
	/// There is an additionnal line because there is a "Back to actions" line, because player isn't forced to use a skill if he changed his mind.
	/// </summary>
	void SkillChoiceLoop();

	/// <summary>
	/// End the player turn by switching to the Enemy turn. If the enemy is dead, or if the player died, then the next turn is the end fight state.
	/// </summary>
	/// <param name="stateMachine">The master state machine</param>
	void GoToNextStep(StateMachine* stateMachine);

	/// <summary>
	/// Processing the cooldowns by decreasing each skills cooldown and duration.
	/// The process add a log if a skill is now ready.
	/// </summary>
	void ProcessCooldowns();

public:
	PlayerTurnState() { };
	~PlayerTurnState() { };

	/// <summary>
	/// The player turn is composed by the skills cooldowns processing and the player's action. Actions can be attacking or using a skill.
	/// </summary>
	/// <param name="stateMachine">The master state machine</param>
	void StartState(StateMachine* stateMachine) override;
	void EndState() override { MState::EndState(); };
};

