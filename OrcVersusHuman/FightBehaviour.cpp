// FightBehaviour.cpp
// Author : Théo Bertet
// Description : This file contains all the methods for the fight behaviour, that is also a State Machine.
#include "FightBehaviour.h"
#include "InitiativeState.h"
#include "PlayerTurnState.h"
#include "EnemyTurnState.h"
#include "EndFightState.h"
#include "UIManager.h"
#include "DataManager.h"

/// <summary>
/// Override of the change state method because behaviour is specified. Here, there is UI methods added to base method
/// </summary>
/// <param name="newState">The new state to switch on</param>
void FightBehaviour::ChangeState(MState& newState)
{
	UIManager::ClearScreen();
	UIManager::DisplayHeader();
	UIManager::DisplayFightLogs(DataManager::GetInstance().GetLastLogs(5));
	UIManager::DisplayFighters(DataManager::GetInstance().GetPlayerFighter(), DataManager::GetInstance().GetEnemyFighter());
	UIManager::DisplayFightOptions(DataManager::GetInstance().GetPlayerFighter());

	StateMachine::ChangeState(newState);
}



// Constructor
FightBehaviour::FightBehaviour()
{
	initiativeState = new InitiativeState();
	playerTurnState = new PlayerTurnState();
	enemyTurnState = new EnemyTurnState();
	endFightState = new EndFightState();
}

// Destructor
FightBehaviour::~FightBehaviour()
{
	delete initiativeState;
	delete playerTurnState;
	delete enemyTurnState;
	delete endFightState;
}



/// <summary>
/// Method that trigger the Roll Initiative State
/// </summary>
void FightBehaviour::RollInitiative()
{
	ChangeState(*initiativeState);
}

/// <summary>
/// Method that trigger the Player Turn State
/// </summary>
void FightBehaviour::PlayerTurn()
{
	ChangeState(*playerTurnState);
}

/// <summary>
/// Method that trigger the Enemy Turn State
/// </summary>
void FightBehaviour::EnemyTurn()
{
	ChangeState(*enemyTurnState);
}

/// <summary>
/// Method that trigger the Fight Ending State
/// </summary>
void FightBehaviour::EndFight()
{
	ChangeState(*endFightState);
}
