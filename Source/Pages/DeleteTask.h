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
};

