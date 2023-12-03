// UIManager.cpp
// Author : Théo Bertet
// Description : This file contains all the data structures for the UI Manager, that groups all the methods for the UI/display.
#include "UIManager.h"

/// <summary>
/// Get a string of space characters to fill the Right part of the "screen".
/// </summary>
/// <param name="leftPart">The characters on the left part</param>
/// <param name="rightPart">The charaters to put on the right part</param>
/// <returns>All the spaces to put between the left part and the right part</returns>
std::string UIManager::GetSpaceFilling(std::string leftPart, std::string rightPart)
{
    int screenWidth = 94;
    std::string spaces = "";
    
    int nbSpaces = screenWidth - leftPart.length() - rightPart.length();

    for (int index = 0; index < nbSpaces; index++)
    {
        spaces += " ";
    }

    return spaces;
}

/// <summary>
/// Get a string of space characters to fill the Right part of a half "screen".
/// </summary>
/// <param name="leftPart">The characters on the left part</param>
/// <param name="rightPart">The charaters to put on the right part</param>
/// <returns>All the spaces to put between the left part and the right part</returns>
std::string UIManager::GetSpaceFillingHalf(std::string leftPart, std::string rightPart)
{
    int screenWidth = 47;
    std::string spaces = "";
    int nbSpaces = screenWidth - leftPart.length() - rightPart.length();

    for (int index = 0; index < nbSpaces; index++)
    {
        spaces += " ";
    }

    return spaces;
}

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
std::string UIManager::GetFilledBarHalfScreen(std::string leftPart, std::string rightPart, int barMaxValue, int barCurValue)
{
    int screenWidth = 47;
    std::string barExtremity = "<>";
    std::string bar = "";

    int nbSteps = screenWidth - leftPart.length() - rightPart.length() - 2 * barExtremity.length();
    if (nbSteps > 1)
    {
        int filledSteps = (barCurValue * nbSteps) / barMaxValue;

        bar += barExtremity;
        for (int curStep = 0; curStep <= nbSteps; curStep++)
        {
            if (curStep <= filledSteps && filledSteps > 0)
            {
                bar += "=";
            }
            else
            {
                bar += ".";
            }
        }
        bar += barExtremity;
    }

    return bar;
}

/// <summary>
/// Display a void line (with the left and right screen delimiters)
/// </summary>
void UIManager::DisplayVoidLine()
{
    std::cout << "|" << GetSpaceFilling("|", "|") << "|" << std::endl;
}



/// <summary>
/// Display the Game Header with the Game Title
/// </summary>
void UIManager::DisplayHeader()
{
    std::cout
        << "+--------------------------------------------------------------------------------------------+" << std::endl
        << "|      ___   __    ___  __              __                                _        __  __    |" << std::endl
        << "|     /___\\ /__\\  / __\\/ _\\     /\\   /\\/ _\\       /\\  /\\ /\\ /\\   /\\/\\    /_\\    /\\ \\ \\/ _\\   |" << std::endl
        << "|    //  /// \\// / /   \\ \\      \\ \\ / /\\ \\       / /_/ // / \\ \\ /    \\  //_\\\\  /  \\/ /\\ \\    |" << std::endl
        << "|   / \\_/// _  \\/ /___ _\\ \\      \\ V / _\\ \\     / __  / \\ \\_/ // /\\/\\ \\/  _  \\/ /\\  / _\\ \\   |" << std::endl
        << "|   \\___/ \\/ \\_/\\____/ \\__/       \\_/  \\__/     \\/ /_/   \\___/ \\/    \\/\\_/ \\_/\\_\\ \\/  \\__/   |" << std::endl
        << "|                                                                                            |" << std::endl
        << "+--------------------------------------------------------------------------------------------+" << std::endl;
}

/// <summary>
/// Clear all the screen
/// </summary>
void UIManager::ClearScreen()
{
    std::system("CLS");
}



/// <summary>
/// Display the main menu sub title with indications
/// </summary>
void UIManager::DisplayEntryGameSubtitle()
{
    std::cout
        << "|                                                                                            |" << std::endl
        << "|                   Use UP and DOWN arrows to navigate, and ENTER to select                  |" << std::endl
        << "|                                                                                            |" << std::endl
        << "+--------------------------------------------------------------------------------------------+" << std::endl;
}

/// <summary>
/// Display all the main game menu choices, and surround the selected choice
/// </summary>
/// <param name="selected">The selected choice</param>
void UIManager::DisplayEntryGameChoice(int selected)
{
    std::map<entryActions, std::string> entryOptions{
        { START, "New Game" },
        { HOW_TO_PLAY, "How to play"},
        { QUIT, "Exit"}
    };

    std::cout
        << "|                                                                                            |" << std::endl;

    int index = 0;
    for (auto& option : entryOptions)
    {
        // Preparing the left and right displays when an option is selected
        std::string selectDislayLeft;
        std::string selectDislayRight;
        if (selected == index)
        {
            selectDislayLeft = "| >>> ";
            selectDislayRight = "<<< |";
        }
        else
        {
            selectDislayLeft = "|     ";
            selectDislayRight = "    |";
        }

        std::string optionDisplay = selectDislayLeft + option.second;

        // Display the option display
        std::cout
            << "|                                                                                            |" << std::endl
            << optionDisplay << GetSpaceFilling(optionDisplay, selectDislayRight) << selectDislayRight << std::endl
            << "|                                                                                            |" << std::endl;

        index++;
    }

    std::cout
        << "|                                                                                            |" << std::endl
        << "| A game made by Theo Bertet (https://github.com/TheoBertet) @ 2023                          |" << std::endl
        << "+--------------------------------------------------------------------------------------------+" << std::endl;
}



/// <summary>
/// Display the How To Play page
/// </summary>
void UIManager::DisplayHowToPlayPage()
{
    std::cout
        << "|                                                                                            |" << std::endl
        << "|                                  Welcome to ORCS VS HUMANS !                               |" << std::endl
        << "|                                                                                            |" << std::endl
        << "| ORCS VS HUMANS is a turn by turn fight game, opposing different fighters each owning       |" << std::endl
        << "| weapons, armors and skills.                                                                |" << std::endl
        << "| A weapon deals damage, an armor can take damage instead of the fighter, and a skill has a  |" << std::endl
        << "| special behaviour, that can increase damage, heal the fighter, etc.                        |" << std::endl
        << "|                                                                                            |" << std::endl
        << "| All skills have a cooldown ; that means you can't use a skill twice before the cooldown    |" << std::endl
        << "| timer is down. They also have a hit rate. Note that a failed hit rate will trigger the     |" << std::endl
        << "| cooldown too.                                                                              |" << std::endl
        << "|                                                                                            |" << std::endl
        << "| Every fight starts with an initiative roll. Each fighter roll a 100 faces dice, and the    |" << std::endl
        << "| one with the higher score starts the fight.                                                |" << std::endl
        << "| A fighter win the fight when his oponnent dies.                                            |" << std::endl
        << "|                                                                                            |" << std::endl
        << "| Now, you know everything... So may the gods have mercy, because you will need it.          |" << std::endl
        << "|                                                                                            |" << std::endl
        << "+--------------------------------------------------------------------------------------------+" << std::endl
        << "|                                                                                            |" << std::endl
        << "| PRESS ENTER TO GO BACK TO MENU                                                             |" << std::endl
        << "|                                                                                            |" << std::endl
        << "+--------------------------------------------------------------------------------------------+" << std::endl;
}



/// <summary>
/// Display the title of the Fighter Selection, with the indications
/// </summary>
void UIManager::DisplayFighterSelectTitle()
{
    std::cout
        << "|                                                                                            |" << std::endl
        << "|                                    SELECT YOUR FIGHTER                                     |" << std::endl
        << "|                   Use UP and DOWN arrows to navigate, and ENTER to select                  |" << std::endl
        << "|                                                                                            |" << std::endl
        << "+--------------------------------------------------------------------------------------------+" << std::endl;
}

/// <summary>
/// Display all the chosable fighters, and surround the selected fighters to show the player on which one he is
/// </summary>
/// <param name="fighters">All the fighters to display</param>
/// <param name="selected">The currently selected fighter</param>
void UIManager::DisplayFighterChoice(std::vector<Fighter> fighters, int selected)
{
    int index = 0;
    for (Fighter f : fighters)
    {
        // Preparing the left and right displays when a fighter is selected
        std::string selectDislayLeft;
        std::string selectDislayRight;
        if (selected == index)
        {
            selectDislayLeft = "| >>> ";
            selectDislayRight = "<<< |";
        }
        else
        {
            selectDislayLeft = "|     ";
            selectDislayRight = "    |";
        }

        // Preparing fighter data
        std::string fighterName = selectDislayLeft + "   " + f.GetName();
        std::string fighterHp = selectDislayLeft + " Health points : " + std::to_string(f.GetHealthPoints());
        std::string weaponLine = selectDislayLeft + " Weapon : ";
        std::string fighterWeapon = selectDislayLeft + "  - " + f.GetWeapon().GetName() + " (Damages : " + std::to_string(f.GetWeapon().GetDamages()) + ")";
        std::string armorLine = selectDislayLeft + " Armor : ";
        std::string fighterArmor = selectDislayLeft + "  - " + f.GetArmor().GetName() + " (Armor points : " + std::to_string(f.GetArmor().GetArmorPoints()) + ")";
        std::string skillsLine = selectDislayLeft + " Skills : ";

        // Display the figther data
        std::cout
            << fighterName << GetSpaceFilling(fighterName, selectDislayRight) << selectDislayRight << std::endl
            << fighterHp << GetSpaceFilling(fighterHp, selectDislayRight) << selectDislayRight << std::endl;

        // Display weapon if fighter has one
        if (f.GetWeapon().GetName() != "N/A")
        {
            std::cout
                << weaponLine << GetSpaceFilling(weaponLine, selectDislayRight) << selectDislayRight << std::endl
                << fighterWeapon << GetSpaceFilling(fighterWeapon, selectDislayRight) << selectDislayRight << std::endl;
        }

        // Display armor if fighter has one
        if (f.GetArmor().GetName() != "N/A")
        {
            std::cout
                << armorLine << GetSpaceFilling(armorLine, selectDislayRight) << selectDislayRight << std::endl
                << fighterArmor << GetSpaceFilling(fighterArmor, selectDislayRight) << selectDislayRight << std::endl;
        }

        // Display skills if fighter has at least one
        if (f.GetSkills().size() > 0)
        {
            std::cout
                << skillsLine << GetSpaceFilling(skillsLine, selectDislayRight) << selectDislayRight << std::endl;
        }

        // Display all the skills (in case a fighter has more than one skill)
        for (Skill s : f.GetSkills())
        {
            std::string skillFirstLine = selectDislayLeft + "  - " + s.GetName() + " : " + s.GetDescription();
            std::string skillSecondLine = selectDislayLeft + "     (Cooldown : " + std::to_string(s.GetCooldown()) + ", Success Rate : " + std::to_string(s.GetSuccessRate()) + ")";

            std::cout
                << skillFirstLine << GetSpaceFilling(skillFirstLine, selectDislayRight) << selectDislayRight << std::endl
                << skillSecondLine << GetSpaceFilling(skillSecondLine, selectDislayRight) << selectDislayRight << std::endl;
        }

        std::cout
            << selectDislayLeft << "                                                                                   " << selectDislayRight << std::endl
            << "+--------------------------------------------------------------------------------------------+" << std::endl;
        
        index++;
    }
}



/// <summary>
/// Display the 5 last log lines in a table
/// If the given logs aren't 5 lines long, then the other lines will be blank
/// </summary>
/// <param name="logs">The logs to display</param>
void UIManager::DisplayFightLogs(std::vector<std::string> logs)
{
    std::cout
        << "| == COMBAT LOG ==                                                                           |" << std::endl;

    int nbLogLines = 5;
    int nbLogs = 0;
    for (std::string log : logs)
    {
        std::string startLogLine = "| " + log;
        std::cout
            << startLogLine << GetSpaceFilling(startLogLine, "|") << "|" << std::endl;
        nbLogs++;
    }

    for (int emptyLogs = 0; emptyLogs < nbLogLines - nbLogs; emptyLogs++)
    {
        std::cout
            << "|                                                                                            |" << std::endl;
    }

    std::cout
        << "+--------------------------------------------------------------------------------------------+" << std::endl;
}

/// <summary>
/// Display the fighter's skins
/// </summary>
/// <param name="playerFighter">The player's fighter, to get its skin</param>
/// <param name="enemyFighter">The enemy's fighter, to get its skin</param>
void UIManager::DisplayFighters(Fighter & playerFighter, Fighter & enemyFighter)
{
    // DISPLAY LIFE & INFOS
    std::cout
        << "|                                                                                            |" << std::endl;

    // DISPLAY NAMES
    std::string leftPart = "|      PLAYER";
    std::string rightPart = "      " + enemyFighter.GetName();
    std::cout
        << leftPart + GetSpaceFillingHalf(leftPart, "")
        << rightPart + GetSpaceFillingHalf(rightPart, "|") + "|" << std::endl;

    // DISPLAY HEALTHPOINTS
    leftPart = "|      HP: " + std::to_string(playerFighter.GetCurrentHP()) + "/" + std::to_string(playerFighter.GetHealthPoints());
    rightPart = "      HP: " + std::to_string(enemyFighter.GetCurrentHP()) + "/" + std::to_string(enemyFighter.GetHealthPoints());
    std::cout
        << leftPart + GetSpaceFillingHalf(leftPart, "")
        << rightPart + GetSpaceFillingHalf(rightPart, "|") + "|" << std::endl;

    // DISPLAY LIFE BAR
    leftPart = "|      ";
    leftPart += GetFilledBarHalfScreen(leftPart, "      ", playerFighter.GetHealthPoints(), playerFighter.GetCurrentHP());
    rightPart = "      ";
    rightPart += GetFilledBarHalfScreen(rightPart, "      |", enemyFighter.GetHealthPoints(), enemyFighter.GetCurrentHP());
    std::cout
        << leftPart + GetSpaceFillingHalf(leftPart, "")
        << rightPart + GetSpaceFillingHalf(rightPart, "|") + "|" << std::endl;

    // DISPLAY ARMOR POINTS
    Armor& playerArmor = playerFighter.GetArmor();
    Armor& enemyArmor = enemyFighter.GetArmor();
    // Skip this step if none of the fighters has an armor
    if (playerArmor.GetName() != "N/A" || enemyArmor.GetName() != "N/A")
    {
        // DISPLAY THE ARMOR POINTS VALUES
        if (playerArmor.GetName() != "N/A")
        {
            leftPart = "|      AP: " + std::to_string(playerArmor.GetCurrentArmorPoints()) + "/" + std::to_string(playerArmor.GetArmorPoints());
        }
        else
        {
            leftPart = "|";
        }

        if (enemyArmor.GetName() != "N/A")
        {
            rightPart = "      AP: " + std::to_string(enemyArmor.GetCurrentArmorPoints()) + "/" + std::to_string(enemyArmor.GetArmorPoints());
        }
        else
        {
            rightPart = "";
        }

        std::cout
            << leftPart + GetSpaceFillingHalf(leftPart, "")
            << rightPart + GetSpaceFillingHalf(rightPart, "|") + "|" << std::endl;

        // DISPLAY THE ARMOR POINTS BARS
        if (playerArmor.GetName() != "N/A")
        {
            leftPart = "|      ";
            leftPart += GetFilledBarHalfScreen(leftPart, "      ", playerArmor.GetArmorPoints(), playerArmor.GetCurrentArmorPoints());
        }
        if (enemyArmor.GetName() != "N/A")
        {
            rightPart = "      ";
            rightPart += GetFilledBarHalfScreen(rightPart, "      |", enemyArmor.GetArmorPoints(), enemyArmor.GetCurrentArmorPoints());
        }
        
        std::cout
            << leftPart + GetSpaceFillingHalf(leftPart, "")
            << rightPart + GetSpaceFillingHalf(rightPart, "|") + "|" << std::endl;
    }

    // SPACE BETWEEN INFOS AND CHARACTERS
    std::cout
        << "|                                                                                            |" << std::endl;

    // DISPLAY CHARACTERS
    for (int currentLine = 0; currentLine < 8; currentLine++)
    {
        std::string leftFighterLine = "|      " + playerFighter.GetSkin().GetLines()[currentLine];
        std::string rightFighterLine = enemyFighter.GetSkin().GetLines()[currentLine];

        std::cout
            << leftFighterLine + GetSpaceFillingHalf(leftFighterLine, "")
            << rightFighterLine + GetSpaceFillingHalf(rightFighterLine, "|") + "|" << std::endl;
    }

    // DISPLAY FOOTER
    std::cout
        << "|                                                                                            |" << std::endl
        << "+--------------------------------------------------------------------------------------------+" << std::endl;
}

/// <summary>
/// Display the fight player's options, and surround the currently selected option
/// </summary>
/// <param name="playerFighter">The player's fighter</param>
/// <param name="selected">The currently selected option</param>
void UIManager::DisplayFightOptions(Fighter & fighter, int selected)
{
    std::string optionsLabel = "| WHAT DO YOU DO ?";
    std::cout
        << optionsLabel + GetSpaceFilling(optionsLabel, "|") + "|" << std::endl;

    std::map<fightAction, std::string> fightOptions {
        { ATK, "Attack" },
        { SKILL, "Skills"}
    };

    for (auto const& fightAct : fightOptions)
    {
        // Preparing the left and right displays when a fighter is selected
        std::string selectDislayLeft;
        std::string selectDislayRight;
        if (selected == fightAct.first)
        {
            selectDislayLeft = "| >>> ";
            selectDislayRight = "<<< |";
        }
        else
        {
            selectDislayLeft = "|     ";
            selectDislayRight = "    |";
        }

        // DISPLAY
        
        // First preparing the display
        std::string action = selectDislayLeft + fightAct.second;
        if (fightAct.first == ATK && fighter.GetWeapon().GetName() != "N/A")
            action += " (Damages : " + std::to_string(fighter.GetDamages()) + ")";

        // Then display the action
        std::cout << action << GetSpaceFilling(action, selectDislayRight) << selectDislayRight << std::endl;
    }

    std::cout
        << "+--------------------------------------------------------------------------------------------+" << std::endl;
}

/// <summary>
/// Display the enemy action, depending on what he does.
/// </summary>
/// <param name="enemyAction">The enemy action</param>
void UIManager::DisplayEnemyAction(std::string enemyAction)
{
    std::cout
        << "|                                                                                            |" << std::endl;

    std::string line = "| " + enemyAction;
    std::cout <<
        line + GetSpaceFilling(line, "|") + "|" << std::endl;


    std::cout
        << "|                                                                                            |" << std::endl
        << "+--------------------------------------------------------------------------------------------+" << std::endl;
}



/// <summary>
/// Display the player's fighter's skills, and surround the currently selected skill
/// </summary>
/// <param name="fighter">The player's fighter</param>
/// <param name="selected">The index of the currently selected skill</param>
void UIManager::DisplayFighterSkills(Fighter & fighter, int selected)
{
    int index = 0;
    for (Skill & fighterSkill : fighter.GetSkills())
    {
        // Preparing the left and right displays when a fighter is selected
        std::string selectDislayLeft;
        std::string selectDislayRight;
        if (selected == index)
        {
            selectDislayLeft = "| >>> ";
            selectDislayRight = "<<< |";
        }
        else
        {
            selectDislayLeft = "|     ";
            selectDislayRight = "    |";
        }

        // DISPLAY

        // First preparing the display
        std::string skillName = selectDislayLeft + fighterSkill.GetName();
        // Display if the skill is ready, or if it's under cooldown
        if (fighterSkill.GetCoolDownRemaining() == 0)
        {
            skillName += " (Ready - Cooldown : " + std::to_string(fighterSkill.GetCooldown()) + ")";
        }
        else
        {
            skillName += " (Ready in " + std::to_string(fighterSkill.GetCoolDownRemaining()) + " turns)";
        }

        std::string skillDesc = selectDislayLeft + fighterSkill.GetDescription();
        std::string skillRate = selectDislayLeft + "Rate of Success : " + std::to_string(fighterSkill.GetSuccessRate());

        // Then display the action
        std::cout << skillName << GetSpaceFilling(skillName, selectDislayRight) << selectDislayRight << std::endl;
        std::cout << skillDesc << GetSpaceFilling(skillDesc, selectDislayRight) << selectDislayRight << std::endl;
        std::cout << skillRate << GetSpaceFilling(skillRate, selectDislayRight) << selectDislayRight << std::endl;

        DisplayVoidLine();
        index++;
    }

    // Display the "Back to actions", in case the player no longer wants to use a skill
    // Preparing the left and right displays when a fighter is selected
    std::string selectDislayLeft;
    std::string selectDislayRight;
    if (selected == fighter.GetSkills().size())
    {
        selectDislayLeft = "| >>> ";
        selectDislayRight = "<<< |";
    }
    else
    {
        selectDislayLeft = "|     ";
        selectDislayRight = "    |";
    }
    std::string goBackLine = selectDislayLeft + "Back to actions";
    std::cout << goBackLine << GetSpaceFilling(goBackLine, selectDislayRight) << selectDislayRight << std::endl;

}
