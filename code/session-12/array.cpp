#include <iostream>
#include <string>
#include <array>

template <typename T, size_t N>
void print(const std::array<T, N>& a)
{
	for (auto& e: a)
		std::cout << e << "\n";
}

int main()
{
	std::array<int, 4> ns = { 10, 20, 30, 40 };
	
	std::array<std::string, 3> ss = { "Java", "Python", "Go" };
	
	print(ns);
	print(ss);
}
