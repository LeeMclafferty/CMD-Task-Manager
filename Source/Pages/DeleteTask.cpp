#include "DeleteTask.h"
#include <iostream>

delete_task::delete_task()
{
	pageContent = "* Delete Task* ";
}

input_state delete_task::handle_user_input()
{
	std::string input;
	std::cin >> input;

	return MAINMENU;
}

void delete_task::update_page_content()
{
	pageContent = "* Delete Task *\n\n" + display_tasks();
}
