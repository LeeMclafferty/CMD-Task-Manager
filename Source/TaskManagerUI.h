#pragma once
#include "Pages/Page.h"
#include <unordered_map>
#include <memory>

class task_manager_UI : public std::enable_shared_from_this<task_manager_UI>
{

public:
	task_manager_UI();
	void post_construct();
	void render();
	inline input_state state() const { return pState; }
	std::shared_ptr<page> select_page(input_state state);

private:
	void display_page(std::shared_ptr<page> p);

	input_state pState;
	std::unordered_map<input_state, std::shared_ptr<page>> pages;
};

