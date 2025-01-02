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
	void update_page_content();
	task selectedTask;
};

