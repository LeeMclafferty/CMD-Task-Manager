#include "DeleteTask.h"
#include <iostream>

const std::string EXIT_OPTION = "4";

delete_task::delete_task()
{
	update_page_content();
}

input_state delete_task::handle_user_input()
{
	update_page_content();
	std::string input = "";
	std::string confirm = "";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //empty cin buffer
	std::cout << "Enter the name of the task you want to delete: ";
	getline(std::cin, input);

	if (input == EXIT_OPTION) {
		return MAINMENU;
	}

	selectedTask = get_task_by_name(input);

	if(selectedTask.name == "") {
		std::cout << "No task found, hit any key to continue...";
		std::cin >> confirm;
		return DELETE;
	}

	handle_confirm(confirm);
	bool success = delete_task_from_file(selectedTask, "./tasks.json");

	if (success) {
		std::cout << selectedTask.name + " was deleted!";
		std::cin >> confirm;
	}
	else {
		std::cout << selectedTask.name + " could not be deleted...";
		std::cin >> confirm;
	}

	return DELETE;
}

void delete_task::update_page_content()
{
	pageHeader = "* Delete Task *\n\n" + display_tasks() + "4. Exit\n\n";
	pageContent = pageHeader;

}

bool delete_task::delete_task_from_file(task t, std::string filePath)
{
	json file = read_and_validate_json(filePath);
	file = validate_json_strcuture(file);

	for (auto it = file["tasks"].begin(); it != file["tasks"].end(); ++it) {
		if ((*it)["taskName"] == t.name) {
			file["tasks"].erase(it);
			write_json_to_file(filePath, file);
			return true;
		}
	}
	
	return false;

}

void delete_task::handle_confirm(std::string& s)
{
	std::cout << "Are you sure you want to delete " + selectedTask.name + ", This cannot be undone (Y/N): ";

	getline(std::cin, s);

	std::transform(s.begin(), s.end(), s.begin(),
		[](unsigned char c) { return std::tolower(c); });

	while ((s != "y") && (s != "yes")) {
		if (s == "EXIT_OPTION" || s == "n" || s == "no") {
			break;
		}
		std::cout << "Invalid Input, try again...\nAre you sure you want to delete " + selectedTask.name + ", This cannot be undone (Y/N): ";
		getline(std::cin, s);
	}
}
