#include <iostream>

void f(int n)
{
	std::cout << n << "\n";
	f(n + 1);
}


int main()
{
	f(1);
}
