#include "TaskManagerUI.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Pages/MainMenu.h"

task_manager_UI::task_manager_UI()
	:pState(MAINMENU)
{
	pages.insert(
		{MAINMENU, std::make_shared<main_menu>() }
	);
}

void task_manager_UI::render()
{
	system("cls");

	page Page = SelectPage(pState);
	display_page(Page);

	handle_user_input();
}

// void task_manager_UI::handle_user_input()
// {
// 	int input;
// 	std::cin >> input;
// 
// 	if (state() == MAINMENU)
// 	{
// 		std::unordered_map<int, input_state> input_to_state = {
// 			{1, ADD},
// 			{2, UPDATE},
// 			{3, DELETE},
// 			{4, EXIT}
// 		};
// 
// 		// TODO: add input validation here.
// 		pState = input_to_state[input];
// 	}
// 	else {
// 		pState = MAINMENU;
// 	}
// }

page task_manager_UI::SelectPage(input_state state)
{
	return *pages[state];
}

void task_manager_UI::display_page(page p)
{
	std::cout << p.GetPageContent() << std::endl;
}
