#include <iostream>
#include <tuple>
#include <string>


template <typename A, typename B, typename C>
void print(const std::tuple<A, B, C>& tup)
{
	std::cout << "Nombre:   " << std::get<0>(tup) << "\n";
	std::cout << "Apellido: " << std::get<1>(tup) << "\n";
	std::cout << "Carnet:   " << std::get<2>(tup) << "\n";
}

using product = std::tuple<size_t, std::string, double>;



int main()
{
	std::tuple<std::string, std::string, long> p1 { "Juan", "Perez", 102929821 };
	
	product product1 { 12341234, "Nintendo Wii", 200.5 };
	
	auto p2 = std::make_tuple("Ramiro", "Arce", 24323421);
	
	auto product2 = std::tuple { 45345312, "TV Sony", 600 }; // since C++17

	print(p1);
	print(p2);
	
	std::tuple<int, int, int> triplet1 { 10, 20, 50 };
	std::tuple<int, int, int> triplet2 { 10, 20, 40 };
	
	std::cout << "E: " << (triplet1 > triplet2) << "\n";
	
}
