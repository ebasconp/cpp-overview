#pragma once

#include <string>
#include <iostream>

#include "IClass.h"

class MyClass : public IClass
{
	std::string s;
public:
	MyClass(const std::string& s);
	~MyClass();
	void print() const override;
};