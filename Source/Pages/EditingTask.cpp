#include "EditingTask.h"

const std::string EXIT_OPTION = "4";
const std::string DISCARD_OPTION = "5";

editing_task::editing_task()
{
	update_page_content();
}

void editing_task::set_selected_task(const task& t)
{
	selectedTask = t; 
	update_page_content();
}

input_state editing_task::handle_user_input()
{
	std::string input;
	std::cout << "";
	getline(std::cin, input);

	return EDITING;
}

void editing_task::update_page_content()
{
	pageContent = "* Editing " + selectedTask.name + " *\n\n" + "1. Update Name" + 
		"\n2. Update Description" "\n3. Mark as Complete"+ "\n4. Exit\n5. Save";
}
