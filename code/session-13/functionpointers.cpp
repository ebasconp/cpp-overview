#include <iostream>
#include <cstring>


int sum(int a, int b)
{
	return a + b;
}

int mul(int a, int b)
{
	return a * b;
}

int division(int a, int b)
{
	return a / b;
}


void operar(int (*operador)(int, int), int a, int b)
{
	//std::cout << operador << "\n";
	std::cout << operador(a, b) << "\n";
}

typedef int hola;

hola h(hola a, hola b)
{
	return a - b;
}

//typedef int (*POPERATOR)(int, int);

using POPERATOR = int(*)(int, int); //C++-only // C++11


void operar2(POPERATOR operador, int a, int b)
{
	//std::cout << operador << "\n";
	std::cout << operador(a, b) << "\n";
}



int main()
{
	operar2(sum, 20, 10);
	operar2(mul, 20, 10);
	operar2(division, 20, 10);
	
}
