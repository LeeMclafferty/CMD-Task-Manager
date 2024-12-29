#pragma once
#include "Page.h"
#include "../Task.h"

class editing_task : public page
{
public:
	editing_task(task t);

private:
	task selectedTask;
};

