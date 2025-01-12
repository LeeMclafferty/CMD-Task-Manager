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

// "./tasks.json"
void page::save_to_json(task t, std::string filePath)
{
	json file = read_and_validate_json(filePath);
	file = validate_json_strcuture(file);
	file = add_task_to_json(file, t);
	write_json_to_file(filePath, file);
}

task page::get_task_by_name(std::string name)
{
	std::transform(name.begin(), name.end(), name.begin(),
		[](unsigned char c) { return std::tolower(c); });

	for (task t : get_all_tasks())
	{
		std::string lowerName = t.name;
		std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(),
			[](unsigned char c) { return std::tolower(c); });

		if (lowerName == name)
		{
			return t;
		}
	}

	return task();
}

nlohmann::json page::read_and_validate_json(std::string filePath)
{
	json parsedData;
	std::ifstream jsonFilestream("./tasks.json");

	// Make sure the file opens with no errors and it exist. 
	if (jsonFilestream.is_open()) {
		try {
			parsedData = json::parse(jsonFilestream);
		}
		catch (const json::parse_error& error) {
			std::cerr << "JSON Parse Error: " << error.what() << '\n';
		}
	}
	else {
		std::cout << "File not found." << filePath << "\n";
		return json::object();
	}
	jsonFilestream.close();

	return parsedData;
}

nlohmann::json page::validate_json_strcuture(nlohmann::json parsedJson)
{
	if (!parsedJson.is_object()) {
		parsedJson = json::object();
	}
	
	// Validate next_id
	if (!parsedJson.contains("next_id") || !parsedJson["next_id"].is_number_integer()) {
		parsedJson["next_id"] = 1; // Initialize if missing
	}

	// Validate tasks
	if (!parsedJson.contains("tasks") || !parsedJson["tasks"].is_array()) {
		parsedJson["tasks"] = json::array(); // Set to empty array if tasks not found
	}

	return parsedJson;
}

nlohmann::json page::add_task_to_json(nlohmann::json file, task t)
{
	int nextId = file["next_id"];
	auto tasks = file["tasks"];

	// If the task exist, then update it instead. 
	for (auto& i : tasks) {
		if (t.id == i["id"]) {
			i["taskName"] = t.name;
			i["taskDescription"] = t.description;
			i["isComplete"] = t.isComplete;

			return file;
		}
	}

	// Create the new task.
	json newTask = {
		{"id", nextId},
		{"taskName", t.name},
		{"taskDescription", t.description},
		{"isComplete", t.isComplete}
	};
	file["tasks"].push_back(newTask);
	file["next_id"] = ++nextId;

	return file;
}

void page::write_json_to_file(std::string filePath, nlohmann::json file)
{
	std::ofstream jsonOut(filePath);
	if (jsonOut.is_open()) {
		std::cout << file.dump(4) << std::endl;
		jsonOut << file.dump(4); // Pretty print, remove to decrease file size.
		jsonOut.close();
	}
	else {
		std::cerr << "Error: Could not open task.json for writing.\n";
	}
}

