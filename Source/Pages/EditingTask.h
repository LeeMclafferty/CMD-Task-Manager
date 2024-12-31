#pragma once
#include "Page.h"
#include "../Task.h"

class editing_task : public page
{
public:
	editing_task();
	inline void set_selected_task(const task& t) { selectedTask = t; }
	input_state handle_user_input();

private:
	void set_page_content();
	task selectedTask;
};

