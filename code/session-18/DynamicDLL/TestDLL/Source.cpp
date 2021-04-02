#include <iostream>
#include <string>

#include "MyClass.h"


extern "C"
{
	__declspec(dllexport) void say_hi()
	{
		std::cout << "HELLO WORLD!!!\n";
	}

	__declspec(dllexport) const char* is_even_or_odd(int n)
	{
		if (n % 2 == 0)
			return "even";

		return "odd";
	}

	__declspec(dllexport) IClass* create_my_class(const char* s)
	{
		MyClass* mc = new MyClass(s);
		std::cout << "MYCLASSPTR: " << mc << "\n";
		return mc;
	}

	__declspec(dllexport) void release_my_class(MyClass* c)
	{
		delete c;
	}
}