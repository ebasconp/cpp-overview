#include <iostream>

void c()
{
	std::cout << "Hello C\n";
	
	int a = 6, b = 1;
	
	//std::cout << (a / (--b)) << "\n";
	
	int* p = nullptr;
	std::cout << *p << "\n";
	
	std::cout << "Bye C\n";
}

void b()
{
	std::cout << "Hello B\n";
	c();
	std::cout << "Bye B\n";
}

void a()
{
	try
	{
		std::cout << "Hello A\n";
		b();
		std::cout << "Bye A\n";
	}
	catch (double x)
	{
		std::cerr << "ERROR CODE: " << x << "\n";
	}
	catch (...) // Generic exception handler
	{
		std::cerr << "ALGO MALO HA PASADO\n";
	}	
}

int main()
{
	a();
	std::cout << "That's all folks!!!\n";
}
