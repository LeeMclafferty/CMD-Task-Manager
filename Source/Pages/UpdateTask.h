#pragma once
#include "Page.h"
#include "../Task.h"

class update_task : public page
{
public:
	update_task();
	virtual input_state handle_user_input();

private:
	void set_page_content_select();
	task get_exsisting_task(std::string s);

	task selectedTask;
};
