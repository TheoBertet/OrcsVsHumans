// InitiativeState.cpp
// Author : Théo Bertet
// Description : This file contains all the methods for the initiative roll state, that is also a State Machine's state.
#include <iostream>
#include "InitiativeState.h"
#include "Fighter.h"
#include "DataManager.h"
#include "Tools.h"

/// <summary>
/// The initiative state define which fighter starts the fight.
/// </summary>
/// <param name="stateMachine">The master state machine</param>
void InitiativeState::StartState(StateMachine* stateMachine)
{
	MState::StartState(stateMachine);
	std::string enemyName = DataManager::GetInstance().GetEnemyFighter().GetName();


	int playerInit = Tools::Random(1, 100);
	int enemyInit = Tools::Random(1, 100);

	DataManager::GetInstance().AddLog("PLAYER rolls " + std::to_string(playerInit) + " in initiative.");
	DataManager::GetInstance().AddLog(enemyName + " enemy rolls " + std::to_string(enemyInit) + " in initiative.");

	if (playerInit >= enemyInit)
	{
		DataManager::GetInstance().AddLog("PLAYER starts the fight!");
		((FightBehaviour*)stateMachine)->PlayerTurn();
	}
	else
	{
		DataManager::GetInstance().AddLog(enemyName + " enemy stats the fight!");
		((FightBehaviour*)stateMachine)->EnemyTurn();
	}
}
