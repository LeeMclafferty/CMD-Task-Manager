#include "Task.h"

task::task()
	:id(0), name(""), description(""), isComplete(false)
{

}

std::ostream& operator<<(std::ostream& os, const task& t)
{
	os << "Name: " << t.name << "\n"
		<< "Description: " << t.description << "\n"
		<< "Completed: " << (t.isComplete ? "Yes" : "No") << "\n";

	return os;
}