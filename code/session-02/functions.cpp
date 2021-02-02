#include <iostream>


// PROTOTYPE:
int mul(int, int, int); 



int main()
{
	int a = 2;
	int b = 3;
	int c = 4;
	
	int r = mul(a, b, c);
	std::cout << r << "\n";
}

int mul(int x, int y, int z)
{
	return x * y * z;
}
