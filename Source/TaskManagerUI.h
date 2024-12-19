#pragma once

class task_manager_UI
{
	// Program is not large enough to justify proper state machine
	enum input_state
	{
		MAINMENU,
		ADD,
		UPDATE,
		DELETE,
		EXIT
	};

public:
	task_manager_UI();
	void render();
	inline input_state state() const { return pState; }

private:
	void display_main_menu();
	void handle_user_input();
	void display_task();

	input_state pState;
};

