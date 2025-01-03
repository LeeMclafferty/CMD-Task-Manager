#include "AddTask.h"
#include <iostream>
#include <fstream>
#include "../json/json.hpp"

using json = nlohmann::json;


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
		save_to_json();
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

void add_task::save_to_json()
{
	json parsedData;
	int nextId = 1;
	std::ifstream jsonFilestream("./tasks.json");

	// Make sure the file opens with no errors and it exist. 
	if (jsonFilestream.is_open()) {
		try {
			parsedData = json::parse(jsonFilestream);
			if (!parsedData.is_object()) {
				parsedData = json::object();
			}
			// Validate next_id
			if (parsedData.contains("next_id") && parsedData["next_id"].is_number_integer()) {
				nextId = parsedData["next_id"];
			}
			else {
				parsedData["next_id"] = nextId; // Initialize if missing
			}

			// Validate tasks
			if (!parsedData.contains("tasks") || !parsedData["tasks"].is_array()) {
				parsedData["tasks"] = json::array();
			}
		}
		catch(const json::parse_error& error) {
			std::cerr << "JSON Parse Error: " << error.what() << '\n';
		}
	}
	else {
		std::cout << "File not found, creating a new one.\n";
		parsedData = {
			{"next_id", nextId},
			{"tasks", json::array()}
		};
	}
	jsonFilestream.close();

	// Create the new task.
	json newTask = {
		{"id", nextId},
		{"taskName", taskName},
		{"taskDescription", taskDesc},
		{"isComplete", false}
	};
	parsedData["tasks"].push_back(newTask);
	parsedData["next_id"] = ++nextId;

	// Write to file
	std::ofstream jsonOut("./tasks.json");
	if (jsonOut.is_open()) {
		std::cout << parsedData.dump(4) << std::endl;
		jsonOut << parsedData.dump(4); // Pretty print, remove to decrease file size.
		jsonOut.close();
	}
	else {
		std::cerr << "Error: Could not open task.json for writing.\n";
	}
}
