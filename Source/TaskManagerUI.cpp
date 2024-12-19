#include "TaskManagerUI.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <stdlib.h>

task_manager_UI::task_manager_UI()
	:pState(MAINMENU)
{

}

void task_manager_UI::render()
{
	system("cls");
	if (state() == MAINMENU)
	{
		display_main_menu();
	}
	else
	{
		display_task();
	}

	handle_user_input();
}

void task_manager_UI::display_main_menu()
{
	std::string menu = R"(
	* CMD Task Manager *

	1. Add Task
	2. Update Task
	3. Delete Task
	4. Exit

	)";

	std::cout << menu << std::endl;
}

void task_manager_UI::handle_user_input()
{
	int input;
	std::cin >> input;

	if (state() == MAINMENU)
	{
		std::unordered_map<int, input_state> input_to_state = {
			{1, ADD},
			{2, UPDATE},
			{3, DELETE},
			{4, EXIT}
		};

		// TODO: add input validation here.
		pState = input_to_state[input];
	}
	else {
		pState = MAINMENU;
	}
}

void task_manager_UI::display_task()
{
	
	std::cout << "Test Menu Switch" << std::endl;
}
