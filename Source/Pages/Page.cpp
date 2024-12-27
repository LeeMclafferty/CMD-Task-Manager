#include "Page.h"
#include "../json/json.hpp"
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

void page::display_tasks()
{
	get_all_tasks();

	for (task t : tasks)
	{
		std::cout << t << "\n";
	}
}
