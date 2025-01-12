#pragma once
#include "Page.h"

class delete_task : public page
{
public:
	delete_task();

protected:
	virtual input_state handle_user_input() override;

private:
	void update_page_content();

	std::string pageHeader;
	task selectedTask;

	bool delete_task_from_file(task t, std::string filePath);
	void handle_confirm(std::string& s);
};

