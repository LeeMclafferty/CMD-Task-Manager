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
	void select_page_content(std::string i);
	void setup_page_dynamic_content();
	task selectedTask;

	void setup_static_content();
	std::string contentHeader;
	std::string mainMenuOptions;
	std::string updateNameContent;
};

