#include "AddTask.h"
#include <iostream>

add_task::add_task()
	:taskName(""), taskDesc("")
{
	pageContent = R"(
        * Add A New Task *
        
        Task Name: )" + defaultString + R"(
        Task Description: )" + defaultString + R"(
        
        4. Exit
	5. Discard
    )";
}

input_state add_task::handle_user_input()
{
	std::string input;

	std::cout << input_prompt();
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// Clear input buffer to avoid returning empty string. 
	std::getline(std::cin, input);

	if (taskName == "")
	{
		taskName = input;
	}
	else
	{
		taskDesc = input;
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

	return taskName + ", was added."; // Placeholder until I get it looping to add task.
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
