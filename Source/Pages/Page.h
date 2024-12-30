#pragma once
#include <string>
#include <vector>
#include <memory>
#include "../task.h"

// Program is not large enough to justify proper state machine
enum input_state
{
	MAINMENU,
	ADD,
	UPDATE,
	DELETE,
	EXIT,
	EDITING
};

class page
{
public:
	page();

	inline std::string get_page_content() const { return pageContent; }
	virtual input_state handle_user_input();
	inline void set_ui_manager(std::shared_ptr<class task_manager_UI> m) { ui_manager = m; }
	std::weak_ptr<class task_manager_UI> get_ui_mananger() { return ui_manager; }

protected:
	std::string pageContent;
	std::vector<task> get_all_tasks();
	std::string display_tasks();

private:
	std::vector<task> tasks;
	std::weak_ptr<class task_manager_UI> ui_manager;

};

