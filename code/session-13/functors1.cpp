#include <iostream>
#include <vector>
#include <string>
#include <set>

bool filtrar_pares(int n)
{
	return n % 2 == 0;
}

bool filtrar_nada(int)
{
	return true;
}

bool filtrar_todo(int)
{
	return false;
}

template <typename Container, typename Filter>
void print(const Container& container, Filter filter)
{
	for (auto& e : container)
		if (filter(e))
			std::cout << e << "\n";
			
	std::cout << "-----------------------\n";
}

bool filtrar_entre_10_y_30(int n)
{
	return n >= 10 && n <= 30;
}

struct FiltrarRango
{
	int min;
	int max;
	
	bool operator()(int n) const
	{
		return n >= min && n <= max;
	}
};

template <typename Filter>
struct FiltrarInverso
{
	Filter filter;
	
	bool operator()(int n) const
	{
		return !filter(n);
	}
};

template <typename Filter>
FiltrarInverso<Filter> make_filter(Filter f)
{
	return FiltrarInverso<Filter> { f };
}

bool filtrar_m(const std::string& d)
{
	return d.starts_with("m");
}

int main()
{
	
	std::vector<int> numbers = { 10, 2, 6, 1, 7, 12, 25, 40, 31 };
	print(numbers, filtrar_pares);
	
	FiltrarRango f { 10, 30 };
	
	print(numbers, f);
	
	print(numbers, FiltrarRango { 1, 10 });
	
	print(numbers, make_filter(filtrar_pares));
	
	print(numbers, make_filter(FiltrarRango { 1, 10 }));
	
	std::set<std::string> dias = { "lunes", "martes", "miercoles", "jueves", "viernes", "sabado", "domingo" };
	
	print(dias, filtrar_m);
	
}
