#pragma once
#include "Page.h"

class main_menu : public page
{
public:
	main_menu();
	virtual input_state handle_user_input() override;
};

