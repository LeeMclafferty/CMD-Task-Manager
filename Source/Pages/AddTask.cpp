#include "AddTask.h"
#include <iostream>

const std::string EXIT_OPTION = "4";
const std::string DISCARD_OPTION = "5";

add_task::add_task()
	:taskName(""), taskDesc("")
{
	refresh();
}

input_state add_task::handle_user_input()
{
	std::string input;

	std::cout << input_prompt();
	std::getline(std::cin, input);

	if (taskName == "")
	{
		taskName = input;
	}
	else if (taskName != "" && taskDesc == "")
	{
		taskDesc = input;
	}
	else
	{
		reset();
	}

	if (input == EXIT_OPTION)
	{
		reset();
		return MAINMENU;
	}
	else if (input == DISCARD_OPTION)
	{
		reset();
	}

	refresh();

	return ADD;
}

std::string add_task::input_prompt()
{
	if (taskName == "")
	{
		return "Enter the task's name: ";
	}
	else if (taskDesc == "")
	{
		return "Enter the task's description: ";
	}

	return taskName + ", was added. Press any button to add another task: ";
}

void add_task::refresh()
{
	pageContent = R"(
        * Add A New Task *
        
        Task Name: )" + taskName + R"(
        Task Description: )" + taskDesc + R"(
        
        4. Exit
	5. Discard
    )";
}

void add_task::reset()
{
	taskName = "";
	taskDesc = "";
}
