#pragma once
#include "Pages/Page.h"
#include <unordered_map>
#include <memory>

class task_manager_UI
{


public:
	task_manager_UI();
	void render();
	inline input_state state() const { return pState; }

private:
	//void handle_user_input();
	page SelectPage(input_state state);
	void display_page(page p);

	input_state pState;
	std::unordered_map<input_state, std::shared_ptr<page>> pages;
};

