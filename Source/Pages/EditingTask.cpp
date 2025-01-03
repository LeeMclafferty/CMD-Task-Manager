#include "EditingTask.h"

const std::string EXIT_OPTION = "4";
const std::string DISCARD_OPTION = "5";

editing_task::editing_task()
{
	setup_static_content();
	setup_page_dynamic_content();
}

void editing_task::set_selected_task(const task& t)
{
	selectedTask = t; 
	setup_page_dynamic_content();
}

input_state editing_task::handle_user_input()
{
	std::string input;
	std::cout << "";
	getline(std::cin, input);

	select_page_content(input);

	return EDITING;
}

void editing_task::select_page_content(std::string i)
{
	if (i == "1") {
		pageContent = contentHeader += updateNameContent;
	}
}

void editing_task::setup_page_dynamic_content()
{
	contentHeader = "* Editing " + selectedTask.name + " *\n\n";
	pageContent = contentHeader;
	pageContent += mainMenuOptions;
}

void editing_task::setup_static_content()
{
	mainMenuOptions = "1. Update Name \n2. Update Description \n3. Mark as Complete \n4. Exit\n5. Save";
	updateNameContent = "\nb. back\n5. Save\n\nEnter the task's new name: ";
}
