#pragma once

#include "dll.h"

#include <string>
#include <memory>

struct PersonImpl;

class MYDLL_EXPORT Person
{
	PersonImpl* impl;

public:
	Person(const std::string& fn, const std::string& ln, size_t year);
	~Person();

	void set_school(const std::string& s);
	void set_city(const std::string& c);

	void show() const;
};