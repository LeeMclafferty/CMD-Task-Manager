#include "DeleteTask.h"
#include <iostream>

delete_task::delete_task()
{
	update_page_content();
}

input_state delete_task::handle_user_input()
{
	std::string input = "";
	std::string confirm = "";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //empty cin buffer
	std::cout << "Enter the name of the task you want to delete: ";
	getline(std::cin, input);
	selectedTask = get_task_by_name(input);

	if(selectedTask.name == "") {
		std::cout << "No task found, hit enter to continue...";
		std::cin >> confirm;
		return DELETE;
	}

	handle_confirm(confirm);

	return DELETE;
}

void delete_task::update_page_content()
{
	pageHeader = "* Delete Task *\n\n" + display_tasks();
	pageContent = pageHeader;

}

bool delete_task::delete_task_from_file(task t, std::string filePath)
{
	json file = read_and_validate_json(filePath);
	file = validate_json_strcuture(file);

	for (auto it = file["tasks"].begin(); it != file["tasks"].end(); ++it) {
		if ((*it)["taskName"] == t.name) {
			file["tasks"].erase(it);
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
		std::cout << "Invalid Input, try again...\nAre you sure you want to delete " + selectedTask.name + ", This cannot be undone (Y/N): ";
		getline(std::cin, s);
	}
}
