#include "EditingTask.h"

editing_task::editing_task()
{
	set_page_content();
}

input_state editing_task::handle_user_input()
{
	set_page_content();
	std::string input;
	std::cin >> input;

	return EDITING;
}

void editing_task::set_page_content()
{
	//std::cout << "editing_task instance created at " << this << std::endl;
	pageContent = "* Editing " + selectedTask.name + " *\n\n" + "4. Exit\n5. Save";
}
