#pragma once

#include "dll.h"

#include <string>


class MYDLL_EXPORT Person
{
	std::string first_name;
	std::string last_name;
	size_t year_of_birth;

public:
	Person(const std::string& fn, const std::string& ln, size_t year);
	void show() const;
};