#include "Page.h"
#include <fstream>
#include <iostream>

using json = nlohmann::json;

page::page()
{
	get_all_tasks();
	display_tasks();
}

input_state page::handle_user_input()
{
	return MAINMENU;
}

std::vector<class task> page::get_all_tasks()
{
	tasks.clear();
	json parsedData;
	std::ifstream jsonFileStream("./tasks.json");

	if (jsonFileStream.is_open()) {
		try {
			parsedData = json::parse(jsonFileStream);
		}
		catch(const json::parse_error& error) {
			std::cerr << "JSON Parse Error: " << error.what() << '\n';
		}
	}

	tasks = parsedData["tasks"].get<std::vector<task>>();

	//std::cout << parsedData.dump(4) << std::endl;
	return tasks;
}

std::string page::display_tasks()
{
	std::stringstream ss;
	get_all_tasks();

	ss << "* Task List *\n\n";

	for (const task& t : tasks)
	{
		ss << t << "\n"; 
	}

	return ss.str(); // Return the entire task list as a string
}

void page::save_to_json(task t)
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
		catch (const json::parse_error& error) {
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
		{"taskName", t.name},
		{"taskDescription", t.description},
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

nlohmann::json page::read_and_validate_json(std::string filePath)
{
	return json();
}

nlohmann::json page::validate_json_strcuture(nlohmann::json parstedJson)
{
	return json();
}

nlohmann::json page::add_task_to_json(nlohmann::json file, task t)
{

}

void page::write_json_to_file(std::string filePath, nlohmann::json file)
{

}

