#pragma once
#include <string>
#include <vector>
#include "../task.h"

// Program is not large enough to justify proper state machine
enum input_state
{
	MAINMENU,
	ADD,
	UPDATE,
	DELETE,
	EXIT
};

class page
{
public:
	page();

	inline std::string get_page_content() const { return pageContent; }
	virtual input_state handle_user_input();

protected:
	std::string pageContent;
	std::vector<task> get_all_tasks();
	void display_tasks();

private:
	std::vector<task> tasks;

};

