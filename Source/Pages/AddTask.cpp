#include "AddTask.h"
#include <iostream>

add_task::add_task()
	:taskName(""), taskDesc("")
{
	pageContent = R"(
	* Add A New Task *

	Task Name: _________
	Task Description: _________

	4. Exit

	)";
}

input_state add_task::handle_user_input()
{
	std::string input;

	std::cout << input_prompt();
	std::cin >> input;

	return ADD;
}

std::string add_task::input_prompt()
{
	if (taskName == "")
		return "Enter the task's name: ";
	if (taskDesc == "")
		return "Enter the task's description: ";
}
