#pragma once
#include <string>
#include <iostream>
#include "json/json.hpp"
using json = nlohmann::json;

class task
{
public:
	task();

	int id;
	std::string name;
	std::string description;
	bool isComplete;

	friend std::ostream& operator<<(std::ostream& os, const task& t);
};

namespace nlohmann {

	// de-serializer for json to task object
	template <>
	struct adl_serializer<task> {
		static void from_json(const json& j, task& t) {
			j.at("id").get_to(t.id);
			j.at("taskName").get_to(t.name);
			j.at("taskDescription").get_to(t.description);
			j.at("isComplete").get_to(t.isComplete);
		}
	};
}
