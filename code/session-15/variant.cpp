#include <variant>

#include <iostream>
#include <string>
#include <vector>

using my_variant = std::variant<int, std::string, double, std::vector<int>>;

void show(const my_variant& p)
{
	/*if (std::holds_alternative<std::string>(p))
		std::cout << std::get<std::string>(p) << "\n";
	else
		std::cerr << "NOT A STRING\n";*/
		
	auto pp = std::get_if<std::string>(&p);
	if (pp != nullptr)
		std::cout << *pp << "\n";
	else
		std::cerr << "NOT A STRING\n";
}

void test0()
{
	my_variant data;
	
	data = 4;
	
	std::cout << std::get<int>(data) << "\n";
	std::cout << std::get<0>(data) << "\n";
	std::cout << "Holds: " << std::holds_alternative<std::string>(data) << "\n";
	
	data = "Hello";
	std::cout << std::get<std::string>(data) << "\n";
	std::cout << std::get<1>(data) << "\n";
	
	data = 3.14159;
	std::cout << std::get<double>(data) << "\n";
	std::cout << std::get<2>(data) << "\n";
	
	data = std::vector<int> { };
	
	//data = "Bye";
	show(data);
}

void test1()
{
	try
	{
		std::variant<int, double, bool> p { true };
		
		std::cout << std::get<double>(p) << "\n";
		
	}
	catch (const std::bad_variant_access& ex)
	{
		std::cerr << "EX: " << ex.what() << "\n";
	}
}

void test2()
{
	std::variant<int, double, std::vector<int>, std::string, long long, bool> xz;
	
	std::cout << "Size of variant: " << std::variant_size<decltype(xz)>::value  << "\n";
}

int main()
{
	//test0();
	//test1();
	test2();
}
