#include "UpdateTask.h"
#include <iostream>
#include <string>
#include <cctype>
#include "../TaskManagerUI.h"
#include "EditingTask.h"

const std::string EXIT_OPTION = "4";
const std::string DISCARD_OPTION = "5";

update_task::update_task()

{
    selectedTask = task();
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
    else {
        selectedTask = get_exsisting_task(input);
        if (selectedTask.name != "")
        {
            auto uiManager = get_ui_mananger().lock();
            if (!uiManager) {
                std::cerr << "Error: UI Manager no longer exists and cannot be accesses by UpdateTask";
                return MAINMENU;
            }

            auto editPage = std::dynamic_pointer_cast<editing_task>(uiManager->select_page(EDITING));
            if (editPage) {
                //std::cout << "Editing task instance at " << editPage.get() << std::endl;
                editPage->set_selected_task(selectedTask);
            }

            return EDITING;
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

task update_task::get_exsisting_task(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c) { return std::tolower(c); });

	for (task t : get_all_tasks())
	{
		std::string lowerName = t.name;
		std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(),
			[](unsigned char c) { return std::tolower(c); });

		if (lowerName == s)
		{
            return t;
		}
	}

    return task();
}
