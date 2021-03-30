#include "mydll.h"

#include <iostream>

	const char* is_even_or_odd(int n)
	{
		return n % 2 == 0 ? "even" : "odd";
	}

	Person::Person(const std::string& fn, const std::string& ln, size_t year)
	: first_name{ fn }, last_name{ ln }, year_of_birth{ year }
{
}

void Person::show() const
{
	std::cout << "(" << year_of_birth << ") " << last_name << ", " << first_name << "\n";
}