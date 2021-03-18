#include <iostream>
#include <string_view>
#include <string>

constexpr std::string_view error_not_found = "File not found";
constexpr std::string_view error_disk_full = "Disk full";


void print_text(const std::string_view& s)
{
	std::cout << s << "\n";
}


// Never return std::string_view of local strings
std::string_view foo()
{
	std::string h = "Hello";
	return h;
}

int main()
{
	std::string h1 = "hola mundo";
	const char* h2 = "hello world";
	
	print_text(h1);
	print_text(h2);
	
	std::cout << foo() << "\n";
	
	std::string_view hola { h1.c_str(), 4 };
	std::cout << hola << "\n";
	
	std::string_view mundo { h1.c_str() + 5, 5 };
	std::cout << mundo << "\n";
	
	std::string smundo { mundo };
	std::cout << smundo << "\n";
	
	std::string cc = "ccoca colax";
	std::string_view ccsv = cc;
	
	ccsv.remove_prefix(1);
	ccsv.remove_suffix(1);	
	
	std::cout << ccsv << "\n";
	
	std::string h3 = "bolivianos el hado propicio";
	
	size_t index = h3.find("pro");
	if (index == std::string::npos)
		std::cerr << "Not found\n";
	else
	{
		std::string lw = h3.substr(index);
		std::cout << lw << "\n";
	}
		
	std::string_view j3 = h3;
	size_t index2 = j3.find("pro");
	if (index2 == std::string_view::npos)
		std::cerr << "Not found\n";
	else
	{
		std::string_view jw = j3.substr(index);
		std::cout << jw << "\n";
	}
	
	using namespace std::string_view_literals;
	
	std::string_view xx = "hello world";
	auto yy = "hello world"sv;
	
	std::cout << yy << "\n";
	
	std::cout << error_disk_full << "\n";
	
}
