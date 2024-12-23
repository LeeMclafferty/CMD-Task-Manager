#include "MainMenu.h"
#include <iostream>
#include <unordered_map>

main_menu::main_menu()
{
	pageContent = R"(
	* CMD Task Manager *

	1. Add Task
	2. Update Task
	3. Delete Task
	4. Exit

	)";
}

input_state main_menu::handle_user_input()
{
	int input;
	std::cin >> input;

	if (input < 1 || input > 4) return MAINMENU;
	std::unordered_map<int, input_state> input_to_state = {
		{1, ADD},
		{2, UPDATE},
		{3, DELETE},
		{4, EXIT}
	};

	return input_to_state[input];
}
