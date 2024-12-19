#include "TaskManagerUI.h"
#include <iostream>
#include <string>

task_manager_UI::task_manager_UI()
{

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
	std::cout << input << std::endl;
}

void task_manager_UI::display_task()
{

}
