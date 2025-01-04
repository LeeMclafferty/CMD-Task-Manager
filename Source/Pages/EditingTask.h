#pragma once
#include "Page.h"
#include "../Task.h"

class editing_task : public page
{
public:
	editing_task();
	void set_selected_task(const task& t);
	input_state handle_user_input();

private:
	std::string select_page_content(std::string i);
	std::string main_menu_options(std::string i);
	std::string update_name_options(std::string i);
	void update_page_dynamic_content();
	task selectedTask;

	std::string contentHeader;
	std::string mainMenuOptions;
	std::string updateNameContent;
	std::string updateDescContent;
	std::string completedContent;
	std::string updateConfirmContent;
};

