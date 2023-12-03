#include <iostream>
#include <conio.h>
#include "AppBehaviour.h"

int main()
{
	try
	{
		AppBehaviour appBehaviour = AppBehaviour();
		appBehaviour.LaunchGame();
		return EXIT_SUCCESS;
	}
	catch (const std::exception e)
	{
		std::cout << "[ERR] " << e.what() << std::endl;
		std::system("PAUSE");
		return EXIT_FAILURE;
	}
}




int deprecated_main()
{
	return -1;
	//// PART 0 : INITIALIZE DATA
	//int c = 0;
	//int select = 0;
	//Fighter chosenFighter;



	//// PART 1 : POPULATE DATA INSIDE DATA MANAGER
	//try
	//{
	//	DataManager::GetInstance().PopulateData();
	//}
	//catch (const std::exception e)
	//{
	//	std::cout << "[ERR] " << e.what() << std::endl;
	//	std::system("PAUSE");
	//	return -1;
	//}



	//// PART 2 : SELECT FIGHTER
	//while (c != KEY_ENTER)
	//{
	//	UIManager::DisplayHeader();
	//	UIManager::DisplayFighterSelectTitle();
	//	UIManager::DisplayFighterChoice(DataManager::GetInstance().GetFighters(), select);

	//	switch ((c = _getch())) {
	//	case KEY_UP:
	//		if (select == 0)
	//			select = DataManager::GetInstance().GetFighters().size() - 1;
	//		else
	//			select = (select - 1) % DataManager::GetInstance().GetFighters().size();
	//		break;
	//	case KEY_DOWN:
	//		select = (select + 1) % DataManager::GetInstance().GetFighters().size();
	//		break;
	//	default:
	//		break;
	//	}

	//	std::system("CLS");
	//}
	//c = 0;
	//chosenFighter = DataManager::GetInstance().GetFighters()[select];
	//select = 0;

	//// PART 3 : FIGHT PART
	//while (c != KEY_ENTER)
	//{
	//	UIManager::DisplayHeader();
	//	UIManager::DisplayFightLogs();
	//	UIManager::DisplayFighters();
	//	UIManager::DisplayFightOptions(chosenFighter, select);

	//	switch ((c = _getch())) {
	//	case KEY_UP:
	//		if (select == 0)
	//			select = UIManager::FIGHT_ACTIONS_COUNT - 1;
	//		else
	//			select = (select - 1) % UIManager::FIGHT_ACTIONS_COUNT;
	//		break;
	//	case KEY_DOWN:
	//		select = (select + 1) % UIManager::FIGHT_ACTIONS_COUNT;
	//		break;
	//	default:
	//		break;
	//	}

	//	std::system("CLS");
	//}

	//if (select == UIManager::SKILL)
	//{
	//	select = 0;
	//	c = 0;
	//	while (c != KEY_ENTER)
	//	{
	//		UIManager::DisplayHeader();
	//		UIManager::DisplayFightLogs();
	//		UIManager::DisplayFighters();
	//		UIManager::DisplayFighterSkills(chosenFighter, select);

	//		switch ((c = _getch())) {
	//		case KEY_UP:
	//			if (select == 0)
	//				select = chosenFighter.GetSkills().size();	// Not -1 because there is one more row, because of the "Go back to actions"
	//			else
	//				select = (select - 1) % (chosenFighter.GetSkills().size() + 1); // +1 because the same reason
	//			break;
	//		case KEY_DOWN:
	//			select = (select + 1) % (chosenFighter.GetSkills().size() + 1);	// Same reason
	//			break;
	//		default:
	//			break;
	//		}

	//		std::system("CLS");
	//	}
	//}


	//std::system("PAUSE");
}