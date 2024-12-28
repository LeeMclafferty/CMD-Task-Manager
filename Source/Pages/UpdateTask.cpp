#include "UpdateTask.h"
#include <iostream>
#include <string>

const std::string EXIT_OPTION = "4";
const std::string DISCARD_OPTION = "5";

update_task::update_task()
{
    set_page_content_select();
}


input_state update_task::handle_user_input()
{
    std::string input;

    std::cout << "Enter a Task's name to edit: ";
    getline(std::cin, input);

    if (input == EXIT_OPTION)
    {
        return MAINMENU;
    }

    for (task t : get_all_tasks())
    {
        if (t.name == input)
        {
            // TODO: set task to edit.
            // also want to standardize input to not be case sensitive with to lower.
        }
    }

	return UPDATE;
}

void update_task::set_page_content_select()
{
	pageContent = display_tasks();

	pageContent += R"(
        ------------------------------
        4. Exit
    )";
}

void update_task::set_page_content_form()
{

}
