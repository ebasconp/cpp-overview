#include "mydll.h"

#include <iostream>

#include "mydll_impl.h""

Person::Person(const std::string& fn, const std::string& ln, size_t year)
	: impl{new PersonImpl()}
{
	impl->first_name = fn;
	impl->last_name = ln;
	impl->year_of_birth = year;
}

Person::~Person()
{
	delete impl;
}

void Person::set_school(const std::string& s)
{
	impl->school = s;
}

void Person::set_city(const std::string& c)
{
	impl->city = c;
}

void Person::show() const
{
	std::cout << "(" << impl->year_of_birth << ") " << impl->last_name << ", " << impl->first_name;
	if (!impl->school.empty())
		std::cout << " - " << impl->school;

	if (!impl->city.empty())
		std::cout << "[" << impl->city << "]";

	std::cout << "\n";
}