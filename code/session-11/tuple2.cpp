#include <tuple>
#include <iostream>
#include <string>
#include <typeinfo>

struct Person
{
	std::string fn;
	std::string ln;
	size_t year;
	
	bool operator==(const Person& p) const
	{
		if (this == &p) return true;
		
		return std::tie(fn, ln, year) == std::tie(p.fn, p.ln, p.year);
	}
	
	bool operator<(const Person& p) const
	{
		return std::tie(ln, fn, year) < std::tie(p.ln, p.fn, p.year);
	}
};

int main()
{
	Person a { "Susana", "Aguirre", 1978 };
	Person b { "Wanda", "Aguirre", 1978 };
	
	std::cout << (a < b) << "\n";
	
	std::tuple<int, int, int, int, bool, int, double> r;
	
	std::cout << std::tuple_size<decltype(r)>::value << "\n";
	
	std::tuple_element<4, decltype(r)>::type x;
	
	std::cout << typeid(x).name() << "\n";
	
}
