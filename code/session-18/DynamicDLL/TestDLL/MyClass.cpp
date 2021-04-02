#include "MyClass.h"
#include <iostream>

MyClass::MyClass(const std::string& s)
	: s{s}
{
	std::cout << "MyClass ctor\n";
}

MyClass::~MyClass()
{
	std::cout << "MyClass dtor";
}

void MyClass::print() const
{
	std::cout << "MyClass: " << s << "\n";
}

