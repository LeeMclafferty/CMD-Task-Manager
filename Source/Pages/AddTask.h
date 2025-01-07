#pragma once
#include "Page.h"
#include <string>


class add_task : public page
{
public:
	add_task();
	virtual input_state handle_user_input() override;

private:
	task newTask;

	std::string input_prompt();

	void refresh();
	void reset();
};

