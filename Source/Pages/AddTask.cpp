#include "AddTask.h"
#include <iostream>
#include <fstream>
#include "../json/json.hpp"

using json = nlohmann::json;


const std::string EXIT_OPTION = "4";
const std::string DISCARD_OPTION = "5";

add_task::add_task()
	:newTask(task())
{
	refresh();
}

/*
* left off here, I need to change this to set the id correctly before saving,
* I need to think about this, since it probably could be done in one of the save
* steps. 
*/
input_state add_task::handle_user_input()
{
	std::string input;

	std::cout << input_prompt();
	std::getline(std::cin, input);

	if (newTask.name == "")
	{
		newTask.name = input;
	}
	else if (newTask.name != "" && newTask.description == "")
	{
		newTask.description = input;
	}
	else
	{
		save_to_json(); // need to finish this call when i work out the ID issue. 
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
