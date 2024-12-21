#pragma once
#include <string>

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

	inline std::string GetPageContent() const { return pageContent; }
	virtual void handle_user_input() = 0; // left off implementing this for main_menu

protected:
	std::string pageContent;
};

