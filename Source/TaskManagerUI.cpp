#include "TaskManagerUI.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Pages/MainMenu.h"
#include "Pages/AddTask.h"
#include "Pages/UpdateTask.h"

task_manager_UI::task_manager_UI()
	:pState(MAINMENU)
{
	pages.insert({
	{ MAINMENU, std::make_shared<main_menu>() },
	{ ADD, std::make_shared<add_task>() },
	{UPDATE, std::make_shared<update_task>()}
	});
}

void task_manager_UI::render()
{
	system("cls");

	std::shared_ptr<page> selectedPage = SelectPage(pState);
	display_page(selectedPage);
	pState = selectedPage->handle_user_input();
}

std::shared_ptr<page> task_manager_UI::SelectPage(input_state state)
{
	return pages[state];
}

void task_manager_UI::display_page(std::shared_ptr<page> p)
{
	std::cout << p->get_page_content() << std::endl;
}
