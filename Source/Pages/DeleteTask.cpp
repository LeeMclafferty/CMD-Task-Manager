#include "DeleteTask.h"
#include <iostream>

delete_task::delete_task()
{
	update_page_content();
}

input_state delete_task::handle_user_input()
{
	std::string input;
	std::cout << "Enter the name of the task you want to delete: ";
	getline(std::cin, input);

	return DELETE;
}

void delete_task::update_page_content()
{
	pageHeader = "* Delete Task *\n\n" + display_tasks();
	pageContent = pageHeader;
}
