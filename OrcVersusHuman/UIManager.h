// UIManager.h
// Author : Théo Bertet
// Description : This file contains all the data structures for the UI Manager, that groups all the methods for the UI/display.
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "Fighter.h"
#include "Weapon.h"
#include "Armor.h"
#include "Skill.h"

#pragma once
class UIManager
{
private:
	/// <summary>
	/// Get a string of space characters to fill the Right part of the "screen".
	/// </summary>
	/// <param name="leftPart">The characters on the left part</param>
	/// <param name="rightPart">The charaters to put on the right part</param>
	/// <returns>All the spaces to put between the left part and the right part</returns>
	static std::string GetSpaceFilling(std::string leftPart, std::string rightPart);

	/// <summary>
	/// Get a string of space characters to fill the Right part of a half "screen".
	/// </summary>
	/// <param name="leftPart">The characters on the left part</param>
	/// <param name="rightPart">The charaters to put on the right part</param>
	/// <returns>All the spaces to put between the left part and the right part</returns>
	static std::string GetSpaceFillingHalf(std::string leftPart, std::string rightPart);

	/// <summary>
	/// Get a string that represents a Bar (like a life bar) that indicates a value over the maxValue.
	/// The bar is used to be displayed on a half "screen", and considers a left and a right part. (Screen border, other text, etc.)
	/// The bar will fill all the space between left and right parts.
	/// </summary>
	/// <param name="leftPart">The part on the left of the bar</param>
	/// <param name="rightPart">The part on the right of the bar</param>
	/// <param name="barMaxValue">The bar max value</param>
	/// <param name="barCurValue">The bar current value</param>
	/// <returns>The bar that represents the current value over the max value</returns>
	static std::string GetFilledBarHalfScreen(std::string leftPart, std::string rightPart, int barMaxValue, int barCurValue);

	/// <summary>
	/// Display a void line (with the left and right screen delimiters)
	/// </summary>
	static void DisplayVoidLine();


public:
	enum entryActions { START, HOW_TO_PLAY, QUIT, ENTRY_ACTIONS_COUNT };	// All the main menu possible actions
	enum fightAction { ATK, SKILL, FIGHT_ACTIONS_COUNT };					// All the fight possible actions

	/// <summary>
	/// Display the Game Header with the Game Title
	/// </summary>
	static void DisplayHeader();

	/// <summary>
	/// Clear all the screen
	/// </summary>
	static void ClearScreen();



	/// <summary>
	/// Display the main menu sub title with indications
	/// </summary>
	static void DisplayEntryGameSubtitle();

	/// <summary>
	/// Display all the main game menu choices, and surround the selected choice
	/// </summary>
	/// <param name="selected">The selected choice</param>
	static void DisplayEntryGameChoice(int selected = 0);



	/// <summary>
	/// Display the How To Play page
	/// </summary>
	static void DisplayHowToPlayPage();



	/// <summary>
	/// Display the title of the Fighter Selection, with the indications
	/// </summary>
	static void DisplayFighterSelectTitle();

	/// <summary>
	/// Display all the chosable fighters, and surround the selected fighters to show the player on which one he is
	/// </summary>
	/// <param name="fighters">All the fighters to display</param>
	/// <param name="selected">The currently selected fighter</param>
	static void DisplayFighterChoice(std::vector<Fighter> fighters, int selected = 0);



	/// <summary>
	/// Display the 5 last log lines in a table
	/// If the given logs aren't 5 lines long, then the other lines will be blank
	/// </summary>
	/// <param name="logs">The logs to display</param>
	static void DisplayFightLogs(std::vector<std::string> logs);

	/// <summary>
	/// Display the fighter's skins
	/// </summary>
	/// <param name="playerFighter">The player's fighter, to get its skin</param>
	/// <param name="enemyFighter">The enemy's fighter, to get its skin</param>
	static void DisplayFighters(Fighter & playerFighter, Fighter & enemyFighter);

	/// <summary>
	/// Display the fight player's options, and surround the currently selected option
	/// </summary>
	/// <param name="playerFighter">The player's fighter</param>
	/// <param name="selected">The currently selected option</param>
	static void DisplayFightOptions(Fighter & fighter, int selected = 0);

	/// <summary>
	/// Display the enemy action, depending on what he does.
	/// </summary>
	/// <param name="enemyAction">The enemy action</param>
	static void DisplayEnemyAction(std::string enemyAction);
	


	/// <summary>
	/// Display the player's fighter's skills, and surround the currently selected skill
	/// </summary>
	/// <param name="fighter">The player's fighter</param>
	/// <param name="selected">The index of the currently selected skill</param>
	static void DisplayFighterSkills(Fighter & fighter, int selected = 0);
};

