// AppBehaviour.cpp
// Author : Théo Bertet
// Description : This file contains all the methods for the main app behaviour, that is also a State Machine.
#include "AppBehaviour.h"
#include "LoadingState.h"
#include "EntryGameState.h"
#include "SelectFighterState.h"
#include "FightState.h"
#include "HowToPlayState.h"

// Constructor
AppBehaviour::AppBehaviour()
{
	loadingState = new LoadingState();
	entryGame = new EntryGameState();
	selectFighterState = new SelectFighterState();
	fightState = new FightState();
	howToPlayState = new HowToPlayState();
}

// Destructor
AppBehaviour::~AppBehaviour()
{
	delete loadingState;
	delete entryGame;
	delete selectFighterState;
	delete fightState;
	delete howToPlayState;
}

/// <summary>
/// Method that trigger the Launch State
/// </summary>
void AppBehaviour::LaunchGame()
{
	ChangeState(*loadingState);
}

/// <summary>
/// Method that trigger the Game Entry State
/// </summary>
void AppBehaviour::EntryGame()
{
	ChangeState(*entryGame);
}

/// <summary>
/// Method that trigger the state when the player has to select a fighter
/// </summary>
void AppBehaviour::SelectFighter()
{
	ChangeState(*selectFighterState);
}

/// <summary>
/// Method that trigger the Show Rules state (How To Play)
/// </summary>
void AppBehaviour::SeeRules()
{
	ChangeState(*howToPlayState);
}

/// <summary>
/// Method that trigger the Fight State.
/// This method create a new State Machine master (FightBehaviour) that represents the turn-by-turn fight part.
/// </summary>
void AppBehaviour::StartFight()
{
	ChangeState(*fightState);
}
