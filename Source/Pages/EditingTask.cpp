#include "EditingTask.h"

const std::string NAME_OPTION = "1";
const std::string DESCRIPTION_OPTION = "2";
const std::string COMPLETE_OPTION = "3";
const std::string DISCARD_OPTION = "b";
const std::string EXIT_OPTION = "4";
const std::string SAVE_OPTION = "5";

editing_task::editing_task()
{
	update_page_dynamic_content();
}

void editing_task::set_selected_task(const task& t)
{
	selectedTask = t; 
	update_page_dynamic_content();
}

input_state editing_task::handle_user_input()
{
	std::string input;
	std::cout << "";
	getline(std::cin, input);

	pageContent = select_page_content(input);

	if(pageContent == EXIT_OPTION) {
		return UPDATE;
	}

	return EDITING;
}

std::string editing_task::select_page_content(std::string i)
{
	if (pageContent == mainMenuOptions) {
		return main_menu_options(i);
	}
	if (pageContent == updateNameContent) {
		return update_name_options(i);
	}

	return mainMenuOptions;
}

std::string editing_task::main_menu_options(std::string i)
{
	if (i == NAME_OPTION) {
		return updateNameContent;
	}
	else if (i == DESCRIPTION_OPTION) {
		return updateDescContent;
	}
	else if (i == COMPLETE_OPTION) {
		return completedContent;
	}
	else if (i == EXIT_OPTION)
	{
		return EXIT_OPTION;
	}
	else if ( i == SAVE_OPTION)
	{
		// TO DO: write changes to file.
		return updateConfirmContent;
	}

	return mainMenuOptions;
}

std::string editing_task::update_name_options(std::string i)
{
	if (i == DISCARD_OPTION) {
		return mainMenuOptions;
	}

	task buffer = selectedTask;
	buffer.name = i;
	set_selected_task(buffer);
	return updateConfirmContent;
}

void editing_task::update_page_dynamic_content()
{
	contentHeader = "* Editing " + selectedTask.name + " *\n\n Description: " + 
		selectedTask.description + "\n Completed: " + (selectedTask.isComplete ? "Yes" : "No") + "\n\n";
	mainMenuOptions = contentHeader + "\n1. Update Name \n2. Update Description \n3. Mark as Complete \n4. Exit\n5. Save";
	updateNameContent = contentHeader + "\nb. back\n\nEnter the task's new name: ";
	updateDescContent = contentHeader + "\nb. back\n\nEnter the task's new description: ";
	completedContent = "\n" + selectedTask.name + " was marked as complete! Press enter to continue...";
	updateConfirmContent = "\n" + selectedTask.name + " was updated! Press enter to continue...";

	pageContent = mainMenuOptions;
}