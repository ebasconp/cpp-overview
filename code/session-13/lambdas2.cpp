#include <iostream>
#include <vector>
#include <string>
#include <set>



template <typename Container, typename Filter>
void print(const Container& container, Filter filter)
{
	for (auto& e : container)
		if (filter(e))
			std::cout << e << "\n";
			
	std::cout << "-----------------------\n";
}

int main()
{
	
	std::vector<int> numbers = { 10, 2, 6, 1, 7, 12, 25, 40, 31 };
	print(numbers, [](int n) { return n % 2 == 0;});
	
	int min = 10;
	int max = 30;
	
	auto filtrar_rango = [&min, &max](int n) { return n >= min && n <= max; };
	
	print(numbers, filtrar_rango);
	
	min = 1; max = 10;
	print(numbers, filtrar_rango);
	
	std::set<std::string> dias = { "lunes", "martes", "miercoles", "jueves", "viernes", "sabado", "domingo" };
	
	print(dias, [](auto& s) { return s.starts_with("m"); });
	
}
