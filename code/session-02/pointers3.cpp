#include <iostream>

void my_swap(int* a, int * b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}


int main()
{
	int n = 40;
	int p = 80;

	std::cout << n << ", " << p << "\n";
	
	my_swap(&n, &p);
	
	std::cout << n << ", " << p << "\n";
}
