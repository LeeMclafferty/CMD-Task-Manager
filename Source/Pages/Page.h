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
	virtual input_state handle_user_input();

protected:
	std::string pageContent;
	std::string defaultString = "_________";
};

