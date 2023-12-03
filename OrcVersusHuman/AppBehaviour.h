// AppBehaviour.h
// Author : Théo Bertet
// Description : This file contains all the data structures for the main app behaviour, that is also a State Machine.
#pragma once
#include <iostream>
#include "StateMachine.h"
#include "MState.h"

// These classes are pre defined because they are needed, but they will be really defined in their own files
class LoadingState;
class EntryGameState;
class SelectFighterState;
class FightState;
class HowToPlayState;

class AppBehaviour : public StateMachine
{
private:
	// All the possible states for this state machine master
	LoadingState * loadingState;
	EntryGameState * entryGame;
	SelectFighterState * selectFighterState;
	FightState * fightState;
	HowToPlayState * howToPlayState;

public:
	// Constructor
	AppBehaviour();
	// Destructor
	~AppBehaviour();

	/// <summary>
	/// Method that trigger the Launch State
	/// </summary>
	void LaunchGame();

	/// <summary>
	/// Method that trigger the Game Entry State
	/// </summary>
	void EntryGame();

	/// <summary>
	/// Method that trigger the state when the player has to select a fighter
	/// </summary>
	void SelectFighter();

	/// <summary>
	/// Method that trigger the Show Rules state (How To Play)
	/// </summary>
	void SeeRules();

	/// <summary>
	/// Method that trigger the Fight State.
	/// This method create a new State Machine master (FightBehaviour) that represents the turn-by-turn fight part.
	/// </summary>
	void StartFight();
};