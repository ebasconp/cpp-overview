#include <any>
#include <iostream>

#include <string>
#include <vector>

int main()
{
	try
	{
		using namespace std::string_literals;
		
		std::any a = 2;
		std::cout << a.has_value() << "\n";
		
		a = "Hello"s;
		std::cout << std::any_cast<std::string>(a) << "\n";	
		
		auto& type = a.type();
		if (type == typeid(std::string))
			std::cout << "It is a string\n";
		else
			std::cout << a.type().name() << "\n";
		
		//std::cout << std::any_cast<const char*>(a) << "\n";	 // bad_cast
		
		std::any b = std::make_any<std::vector<int>>();
		std::any_cast<std::vector<int>>(b).push_back(10);
		
		const auto& p = std::any_cast<std::vector<int>>(b);
	
		std::cout << "****\n";
		for (auto& e : p) std::cout << e << "\n";

	
	}
	catch (const std::bad_any_cast& ex)
	{
		std::cerr << "EX: " << ex.what() << "\n";
	}
	
}
