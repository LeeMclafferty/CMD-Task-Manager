#pragma once
#include <string>

class task
{
public:
	task();

private:
	int id;
	std::string taskName;
	std::string description;
	bool isComplete;
};

