#pragma once
#include "Page.h"
#include "../Task.h"

class editing_task : public page
{
public:
	editing_task();
	inline void set_selected_task(task t) { t = selectedTask; }
private:
	task selectedTask;
};

