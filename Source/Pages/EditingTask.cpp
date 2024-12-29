#include "EditingTask.h"

editing_task::editing_task(task t)
{
	selectedTask = t;

	pageContent = "* Editing " + t.name + " *\n\n" + "4. Exit\n5. Save";
}
