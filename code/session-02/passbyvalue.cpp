#include <iostream>

void multiplicar_por_2(int x)
{
	x *= 2;
	std::cout << "Dentro: " << x << "\n";
}


int main()
{
	int var = 200;
	multiplicar_por_2(var);
	std::cout << "Valor final: " << var << "\n";
}
